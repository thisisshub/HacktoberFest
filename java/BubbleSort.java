class BubbleSort 
{
	void bubbleSort(int arr[])
	{
		int n = arr.length;
		for(int i = 0;i<n-1;i++)
		{
			for(int j = 0;j<n-i-1;j++)
			{
				if(arr[j] > arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;

				}
			}
		}
	}

	void printArray(int arr[])
	{
		System.out.println("Printing Array : ");
		for (int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+" ");
		}
	}

	public static void main(String[] args) {
		BubbleSort obj = new BubbleSort();
		int arr[] = {12,02,11,45,87,2,1,4,87,88,10,-6};
		obj.bubbleSort(arr);
		obj.printArray(arr);


	}
}