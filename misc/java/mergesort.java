import java.util.Scanner;
public class MergeSort
{
 public static void merge(int a[],int l,int m,int r)
   {  
       int i, j,c=l;
       int b[]=new int[r+1];
 
	for(i=l,j=m+1;i<=m && j<=r;c++)
             {
                  if(a[i] <= a[j])
                  b[c] = a[i++];
                 else
                 b[c] = a[j++];
      	}
	 while(i<=m)    
                 b[c++] = a[i++]; 
               while(j<=r)   
                 b[c++] = a[j++];          
   	 for(i = l ; i <= r; i++)
                        a[i] = b[i];
   }   
   public static void Sort(int a[],int l,int r)
   {  
         if(l<r)
        {
           int m=(l+r)/2;
           Sort(a,l,m);
           Sort(a,m+1,r);
           merge(a,l,m,r);
         }    
   }  
 public static void print(int a[])
{
       for(int i=0;i<a.length;i++)
        {       
        System.out.print(a[i]+"  ");
        }       
}
    public static void main(String[] args) 
    {
        int n,i;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter number of elements in the array:");
        n = s.nextInt();
        int a[] = new int[n];
        System.out.println("Enter "+n+" elements ");
        for(i=0;i<n;i++)
        {
            a[i]=s.nextInt();
        }
        System.out.println( "elements in array:");
        print(a);
         Sort(a,0,n-1);
        System.out.println( "\nelements after sorting:");
         print(a);    
  }      
}
