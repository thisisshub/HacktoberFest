import java.util.Scanner;

public class Que3 {
	public static int reversenumber(int y)
	{
		int reverse=0;
		while(y!=0)
		{
			reverse=reverse*10;
			reverse = reverse+ y%10;
            y=y/10;
		}
		return reverse;
	}
	
	public static void main (String args[])
	{
		Scanner sc= new Scanner(System.in);
		int j,i;

        
        
        System.out.println("Enter your elements:");
        int [][] matrix= new int[3][3];
        
        for (i=0; i<3; i++)
        {
            for (j=0; j<3; j++)
            {
                matrix[i][j]=sc.nextInt();
                
            }
        }
        
        System.out.println("Your matrix is:");
        for (i=0; i<3; i++)
        {
            for (j=0; j<3; j++)
            {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
            
        }
        System.out.println();
        
        System.out.print("Elements of forward diagonal are: ");
        for (i = 0; i < 3; i++) 
        { 
            for (j = 0; j < 3; j++) 
            { 
            	if (i == j) 
                { 
                    System.out.print(matrix[i][j] + " "); 
                } 
            } 
           
        }
        System.out.println();
        
        System.out.print("Elements of reverse diagonal are: ");
        for (i = 0; i < 3; i++) 
        { 
            for (j = 0; j < 3; j++) 
            { 
  
                
                if ((i + j) == (3 - 1)) { 
                    System.out.print(matrix[i][j] + " "); 
                } 
            } 
        } 
        System.out.println();
        
       
        for (i=0; i<3; i++)
        {
            for (j=0; j<3; j++)
            {
            	if((i+j)%2==0)
            	{
            		matrix[i][j]=reversenumber(matrix[i][j]);
            	}
            	
            }
        }
            System.out.println("Your output matrix is:");
            for (i=0; i<3; i++)
            {
                for (j=0; j<3; j++)
                {
                    System.out.print(matrix[i][j] + " ");
                }
                System.out.println();
                
            }
        
        
        
        
        
	}

}
