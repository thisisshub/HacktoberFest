#include "assign1_q2_funcs.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

// Merge sort solution of Tutorial 1
void merge_4_way(int* array, int low, int mid1, int mid2, int mid3, int high) {
    int n1 = mid1 - low;
    int n2 = mid2 - mid1;
    int n3 = mid3 - mid2;
    int n4 = high - mid3;


    int arr1[n1], arr2[n2], arr3[n3], arr4[n4];
    for (int i = 0; i < n1; ++i) {
        arr1[i] = array[low+i];
    }

    for (int i = 0; i < n2; ++i) {
        arr2[i] = array[mid1+i];
    }

    for (int i = 0; i < n3; ++i) {
        arr3[i] = array[mid2+i];
    }

    for (int i = 0; i < n4; ++i) {
        arr4[i] = array[mid3+i];
    }


    int i = 0, j = 0, k = 0, p = 0, l = low;  

    // choose smaller of the smallest in the three ranges  
    while (l < high) {
        int min_value = INT_MAX;
        int min_index = -1;
        
        if(i < n1 && min_value >= arr1[i]) {
            min_value = arr1[i];
            min_index = 0;
        }

        if(j < n2 && min_value >= arr2[j]) {
            min_value = arr2[j];
            min_index = 1;
        }

        if(k < n3 && min_value >= arr3[k]) {
            min_value = arr3[k];
            min_index = 2;
        }

        if(p < n4 && min_value >= arr4[p]) {
            min_value = arr4[p];
            min_index = 3;
        }


        if(min_index == 0) {
            array[l++] = arr1[i++]; 
        } else if (min_index == 1) {
            array[l++] = arr2[j++]; 
        } else if(min_index == 2) {
            array[l++] = arr3[k++]; 
        } else if(min_index == 3) {
            array[l++] = arr4[p++]; 
        } else {
            printf("error occurs! \n");
            return;
        }
    }  
}  

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
} 
  
/* Performing the merge sort algorithm on the  
given array of values in the rangeof indices  
[low, high). low is minimum index, high is  
maximum index (exclusive) */
void mergesort_4_way_rec(int* array, int low, int high) {
    // If array size is 1 then do nothing  
    if (high - low < 2)  
        return;

    if (high - low == 2) {
        int x = array[low], y = array[low+1];
        if (x > y) swap(&x, &y);
        array[low] = x;
        array[low+1] = y;
        return;
    }  

     if (high - low == 3) {
        int x = array[low], y = array[low+1], z = array[low+2];
        if (x > y) swap(&x, &y);
        if (y > z) swap(&y, &z);
        if (x > y) swap(&x, &y);
        array[low] = x;
        array[low+1] = y;
        array[low+2] = z;
        return;
     }  
  
    // Splitting array into 3 parts  
	int length = high - low;
    int quarter = length / 4;
    int remainder = length % 4;
    int mid1 = low + quarter;
    int mid2 = mid1 + quarter;
    int mid3 = mid2 + quarter;
    if (remainder == 2)
        mid3++;
    if (remainder == 3){
        mid2++;
		mid3 +=2;
    }

    // Sorting 3 arrays recursively  
    mergesort_4_way_rec(array, low, mid1);  
    mergesort_4_way_rec(array, mid1, mid2);  
    mergesort_4_way_rec(array, mid2, mid3);  
    mergesort_4_way_rec(array, mid3, high);  
  
    // Merging the sorted arrays  
    merge_4_way(array, low, mid1, mid2, mid3, high);  
} 


/* from K&R
 - produces a random number between 0 and 32767.*/
int rand_seed=10;
int rand()
{
    rand_seed = rand_seed * 1103515245 +12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}

int* generateIntArray(int size)
{
	int * array = (int*) malloc(size*sizeof(int));
	for (int i=0; i < size; i++){
        array[i]=rand();
    }
	
	return array;
}

void printArray(int* array, int low, int high)
{
	for(int i=0;i < high - low; i++){
		printf("%d ", array[low + i]);
	}
	printf("\n");
}



void bubble_sort(int *array, int size)
{
	int x,y,t;
	for (x=0; x < size-1; x++)
        for (y=0; y < size-x-1; y++)
            if (array[y] > array[y+1])
            {
                t=array[y];
                array[y]=array[y+1];
                array[y+1]=t;
            }
}

bool verifySortResults(int* array_bubble, int* array_mergesort, int size)
{
	int num_unequal = 0;
	for(int i = 0; i< size; i++){
		if(array_bubble[i] != 	array_mergesort[i])
			num_unequal++;
	}
	
	if(num_unequal!=0){
		printf("The sort result by merge sort is not correct. The number of unequal values: %d.\n", num_unequal);
		return false;
	}
	else{
		printf("The sort result by merge sort is corrent, verified by bubble sort.\n");
		return true;
	}
}



void mergesort4Way4Processes(int* array, int low, int high)
{
	// Q2.1: Write your solution
	// The argument int * array already points to the shared memory segment, hence we can start the parallel merge sort
	// right here, without needing to use shmget(), shmat() etc.

	pid_t pid; // store the pid values from fork() for program logic
	pid_t child_pid[3]; // store the pid values of each child process
	int max_num = (high - low) / 4; // The number of elements to be sorted per process

	if ((pid = fork()) < 0)	{
		// error in fork()
		printf("Error in forking process! Terminating...\n");
		exit(1);
	}
	
	else if (pid == 0)	{
		// the 1st child executes here
		mergesort_4_way_rec(array, low + max_num, low + 2 * max_num);
		
		printf("Process ID: %d; Sorted %d integers: ", getpid(), max_num);
		for (int i = low + max_num; i < low + 2 * max_num; i++)	{
			printf("%d ", array[i]);
		}	
		printf("\n");
	
		exit(0);
	}
	
	else	{
		// the parent continues here		
		child_pid[0] = pid;
		mergesort_4_way_rec(array, low, low + max_num);

		printf("Process ID: %d; Sorted %d integers: ", getpid(), max_num);
		for (int i = low; i < low + max_num; i++)	{
			printf("%d ", array[i]);
		}
		printf("\n");

		if ((pid = fork()) < 0)	{
			// error in fork()
			printf("Error in forking process! Terminating...\n");
			exit(1);
		}

		else if (pid == 0)	{
			// the 2nd child executes here
			mergesort_4_way_rec(array, low + 2 * max_num, low + 3 * max_num);

			printf("Process ID: %d; Sorted %d integers: ", getpid(), max_num);
			for (int i = low + 2 * max_num; i < low + 3 * max_num; i++)	{
				printf("%d ", array[i]);
			}
			printf("\n");

			exit(0);
		}

		else	{
			// the parent continues here
			child_pid[1] = pid;

			if ((pid = fork()) < 0)	{
				// error in fork()
				printf("Error in forking process! Terminating...\n");
				exit(1);
			}
		
			else if (pid == 0)	{
				// the 3rd (and final) child executes here	
				mergesort_4_way_rec(array, low + 3 * max_num, high);

				printf("Process ID: %d; Sorted %d integers: ", getpid(), max_num);
				for (int i = low + 3 * max_num; i < high; i++)	{
					printf("%d ", array[i]);
				}
				printf("\n");

				exit(0);
			}
	
			else	{
				// the parent waits for the processes to terminate, and then carries out the merge operation
				child_pid[2] = pid;

				//wait for 1st child process
				waitpid(child_pid[0], NULL, 0);

				//wait for 2nd child process
				waitpid(child_pid[1], NULL, 0);

				//wait for 3rd child process
				waitpid(child_pid[2], NULL, 0);

				merge_4_way(array, low, low + max_num, low + 2 * max_num, low + 3 * max_num, high);
			
				printf("Process ID: %d; Merged %d integers: ", getpid(), high - low);
				for (int i = low; i < high; i++)	{
					printf("%d ", array[i]);
				}
				printf("\n");

				return;
			}
		}

	}

}

void recursiveMergesort(int* array, int low, int high, int max_num)
{
	// max_num: the maximum number of integers a process can handle
	// Q2.2 Write your solution
	// The shared memory segment has already been created, so we can get straight to the sorting process
	// without worrying about copying the data over to a new array

	if (high - low < 2)	{
		return;
	}	

	if (high - low == max_num)	{
		mergesort_4_way_rec(array, low, high);
		printf("Process ID: %d; Sorted %d integers: ", getpid(), max_num);
		for (int i = low; i < high; i++)	{
			printf("%d ", array[i]);
		}
		printf("\n");
		return;
	}	

	/* first we regulate the length of the array such that we get 4 roughly equal portions.
	 Due to the design of this question, the below statements are redundant, as the array 
	is always perfectly divisible by 4 until we get max_num elements, where we use the
	local 4-way merge-sort anyway 
	*/ 
	int length = high - low;
	int quarter = length / 4;
	int remaining = length % 4;
	int mid1 = low + quarter;
	int mid2 = mid1 + quarter;
	int mid3 = mid2 + quarter;

	if (remaining == 2)	{
		mid3++;
	}	
	if (remaining == 3)	{
		mid2++;
		mid3+=2;
	}

	pid_t pid_1, pid_2, pid_3; // to store the pid of all the child processes
	
	
	// now, we should begin the fork() process

	pid_1 = fork();

	if (pid_1 < 0)	{
		// error in forking process
		printf("Error in forking process! Terminating...\n");
		exit(1);
	}	

	else if (pid_1 == 0)	{
		// child process here
		recursiveMergesort(array, mid1, mid2, max_num);

		exit(0);
	}

	else	{
		// parent process here
		pid_2 = fork();
		
		if (pid_2 < 0)	{
			// error in forking process
			printf("Error in forking process! Terminating...\n");
			exit(1);
		}
		
		else if (pid_2 == 0)	{
			// child process 2 here
			recursiveMergesort(array, mid2, mid3, max_num);

			exit(0);
		}
		
		else	{
			// parent process here
			pid_3 = fork();
			
			if (pid_3 < 0)	{
				// error in forking process
				printf("Error in forking process! Terminating...\n");	
				exit(1);	
			}
	
			else if (pid_3 == 0)	{
				// child process 3 here
				recursiveMergesort(array, mid3, high, max_num);

				exit(0);
			}
		
			else	{
				// parent process here
				recursiveMergesort(array, low, mid1, max_num);
	
				waitpid(pid_1, NULL, 0);
				waitpid(pid_2, NULL, 0);
				waitpid(pid_3, NULL, 0);
			
				merge_4_way(array, low, mid1, mid2, mid3, high);			

				printf("Process ID: %d; Merged %d integers: ", getpid(), high - low);
				for (int i = low; i < high; i++)	{
					printf("%d ", array[i]);
				}
				printf("\n");
	
			}
		}
	}
}


// Plase use the following lines to print related information if needed.
/*
printf("Process ID: %d; Sorted %d integers: ", getpid(), ***);
printf("Process ID: %d; Merged %d integers: ", getpid(), ***);

*/
