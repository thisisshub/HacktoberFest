#include "assign1_q2_funcs.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char* argv[]) 
{
	printf("This is the BEGINNING of the program.\n");
	if(argc-1 != 2){
		printf("Error: The number of input integers now is %d. Please input 2 integers.\n",argc-1);
		return -1;
	}// Don't modify this Error Checking part
	else{
		printf("n: %s; ", argv[1]);
		printf("max_num: %s.\n", argv[2]);
	}	
	const int n = atoi(argv[1]);
	const int max_num = atoi(argv[2]);
	
	int num_integers = pow(4, n) * max_num;
	printf("Sort (((4^n)*max_num) = %d integers.\n", num_integers);
	int* pInputArray = generateIntArray(num_integers);
	printf("Input array: ");
	printArray(pInputArray, 0 , num_integers);
	printf("\n");
	
	
	struct timespec start, end;
	printf("Start timing...\n");
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	
	//sleep(1);  // This line is only for test. Remove this line when you implement your solution

	int * shared_array; // The shared memory segment for the input array where all processes will conduct the sort
	int shmid; // the ID of the shared memory segment

	shmid = shmget(IPC_PRIVATE, num_integers * sizeof(int), 0666 | IPC_CREAT);
	shared_array = shmat(shmid, 0, 0);

	for (int i = 0; i < num_integers; i++)	{
		// copy over the input array to the shared memory segment
		shared_array[i] = pInputArray[i];
	}
	
	//mergesort4Way4Processes(shared_array, 0, num_integers);
	recursiveMergesort(shared_array, 0, num_integers, max_num);
	
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	printf("End timing.\n");
	//uint64_t delta_ms = (end.tv_sec - start.tv_sec) * 1.0e3 + (end.tv_nsec - start.tv_nsec) * 1.0e-6;
	//printf("The elapsed time (ms) is %lu \n", delta_ms);
	uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1.0e6 + (end.tv_nsec - start.tv_nsec) * 1.0e-3;
	printf("The elapsed time (us) is %lu \n", delta_us);
	// uint64_t delta_s = (end.tv_sec - start.tv_sec);
	// printf("The elapsed time (s) is %lu \n", delta_s);
	
		
	bubble_sort(pInputArray, num_integers);
	verifySortResults(pInputArray, shared_array, num_integers); // Replace YOUR_ARRAY by your array name

	free(pInputArray);
	shmdt(shared_array);
	shmctl(shmid, IPC_RMID, NULL);
	printf("This is the END of the program.\n");
    return 0;
}










