// Java program to find maximum sum of hour glass in a 3x3 arrrix

import java.io.*;

class MaximumHourglassSum { 

	static int findMaximumSum(int[][] arr)	{ 
		if (arr.length < 3 || arr[0].length < 3) 
			return -1; 


		int maximumSum = Integer.MIN_VALUE;
		
		for (int i = 0; i < arr.length-2; i++)
			for (int j = 0; j < arr[0].length-2; j++)	{  
				int sum = (arr[i][j] + arr[i][j + 1] + 
						arr[i][j + 2]) + (arr[i + 1][j + 1]) + 
						(arr[i + 2][j] + arr[i + 2][j + 1] + 
						arr[i + 2][j + 2]); 


				maximumSum = Math.max(maximumSum, sum); 
			} 
			
		return maximumSum; 
	} 

	// Driver code 
	static public void main (String[] args)	{
		
		int[][] arr = {
			{1, 2, 3, 0, 0}, 
			{0, 0, 0, 0, 0}, 
			{2, 1, 4, 0, 0}, 
			{0, 0, 0, 0, 0}, 
			{1, 1, 0, 1, 0}
		};
		
		int res = findMaximumSum(arr); 
		
		if (res == -1) 
			System.out.println("Not possible!"); 
		else
			System.out.println("Maximum sum of hour glass = " + res); 
	}
} 
