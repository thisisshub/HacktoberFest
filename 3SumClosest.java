import static java.lang.Math.abs; 
import java.util.*; 

class 3SumClosest 
{ 

    // Function to return the sum of a 
    // triplet which is closest to x 
    static int solution(Vector<Integer> arr, int x) 
    { 

        // Sort the array 
        Collections.sort(arr); 

        // To store the closets sum 
        int closestSum = Integer.MAX_VALUE; 

        // Fix the smallest number among 
        // the three integers 
        for (int i = 0; i < arr.size() - 2; i++)  
        { 

            // Two pointers initially pointing at 
            // the last and the element 
            // next to the fixed element 
            int ptr1 = i + 1, ptr2 = arr.size() - 1; 

            // While there could be more pairs to check 
            while (ptr1 < ptr2) 
            { 

                // Calculate the sum of the current triplet 
                int sum = arr.get(i) + arr.get(ptr1) + arr.get(ptr2); 

                // If the sum is more closer than 
                // the current closest sum 
                if (abs(x - sum) < abs(x - closestSum))  
                { 
                    closestSum = sum; 
                } 

                // If sum is greater then x then decrement 
                // the second pointer to get a smaller sum 
                if (sum > x)  
                { 
                    ptr2--; 
                } 

                // Else increment the first pointer 
                // to get a larger sum 
                else
                { 
                    ptr1++; 
                } 
            } 
        } 

        // Return the closest sum found 
        return closestSum; 
    } 

    public static void main(String[] args)  
    { 
        Vector arr = new Vector(Arrays.asList( -1, 2, 1, -4 )); 
        int x = 1; 
        System.out.println(solution(arr, x)); 
    } 
} 
