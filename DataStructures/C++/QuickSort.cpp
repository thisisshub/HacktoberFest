 // C++ program to implement Quick Sort

#include <iostream>
using namespace std;

       //function to swap two elements

		void swap(int *ele1, int *ele2)
		{
			int t = *ele1;
			*ele1 = *ele2;
			*ele2 = t;
		}
		
		/*A  function  that takes last element as pivot, places 
           the pivot element at its correct position in sorted 
             array, and places all smaller (smaller than pivot) 
              to left of pivot and all greater elements to right of pivot */
		
		int partition(int ar[], int low, int high)
		{
			int pivot,index,row;
			
			pivot = ar[high]; //pivot element
			index = low-1;    //index of smaller element
			
			for(row = low; row <= high-1; row++)
			{
				if(ar[row] <= pivot)
				{
					index++;
					
					 swap(&ar[index], &ar[row]);
				}
			}
			
			//swap function is called
			
			swap(&ar[index+1], &ar[high]);
			
			return (index+1);
		}
		
		//function to implement QuickSort
		
		void QuickSort(int ar[], int low, int high)
		{
			
		  /*ar : Array that has to be sorted
		    low : Starting index
			high : Ending index*/
		
			if(low < high)
			{
				int partIndex = partition(ar, low, high);    //partitioning index
				
				//sorting elements before and after partition
				
				QuickSort(ar, low, partIndex-1);
				QuickSort(ar, partIndex+1, high);
			}
		}
		
		//function to display elements of the array
		
		void displayArray(int ar[], int len)
		{
			for(int row = 0; row < len; row++)
			 
			   cout<<ar[row]<<"\t";
   
		}
		
		 //main function to control program execution by calling other functions
		
		int main()
		{
			int arr[10], size;
			
			cout<<"Enter the length of the array"<<endl;
			 
			cin>>size;
			
			cout<<"Enter the elements in an array "<<endl;
			
			 for(int row = 0; row < size; row++ )
			     cin>>arr[row];
			   
			   //finction to sort array is called
			     
			  QuickSort(arr, 0, size-1); 
			  
            cout<<"Sorted array: "<<endl; 
             
             //function to display array is called
             
             displayArray(arr, size); 
             
       return 0;    
		}
		