import java.util.Scanner;

public class assignment1 
{
	public static void main(String args[]) 
	{
		Scanner sc= new Scanner(System.in);
        
        int r ;
        int c;
        int i;
        int j;
        										//User Input Matrix
        
        System.out.println("Enter number of rows:");
        r= sc.nextInt();
        
        System.out.println("Enter number of columns:");
        c= sc.nextInt();
        
        System.out.println("Enter your elements:");
        int [][] matrix= new int[r][c];
        
        for (i=0; i<r; i++)
        {
            for (j=0; j<c; j++)
            {
                matrix[i][j]=sc.nextInt();
                
            }
        }
        						//Printing Matrix
        System.out.println("Your matrix is:");
        for (i=0; i<r; i++)
        {
            for (j=0; j<c; j++)
            {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
            
        }
        
        System.out.println();
        
        		//Finding largest and smallest element from the row
        for (i=0; i<r; i++)
        {
        	int min=matrix[i][0];
        	int max=matrix[i][0];
        	for (j=0; j<c; j++)
        	{
        		if (matrix[i][j]<=min) 
        		{
        			min=matrix[i][j];
        		}
        		if (matrix[i][j]>=max) 
        		{
        			max=matrix[i][j];
        		}
        		
        	}
        	System.out.println("Largest element in row"+" "+i+":"+max);
        	System.out.println("Smallest element in row"+" "+i+":"+min);
        	
        	
        }
        
        System.out.println(); //for giving space between output of rows and columns
        
        							//Finding largest and smallest element from the row
        for (j=0; j<c; j++)
        {
        	int min1=matrix[0][j];
        	int max1=matrix[0][j];
        	for (i=0; i<r; i++)
        	{
        		if (matrix[i][j]<=min1) 
        		{
        			min1=matrix[i][j];
        		}
        		if (matrix[i][j]>=max1) 
        		{
        			max1=matrix[i][j];
        		}
        		
        	}
        	System.out.println("Largest element in column"+" "+j+":"+max1);
        	System.out.println("Smallest element in column"+" "+j+":"+min1);
        	
        	
        }
        
		

	}

}
