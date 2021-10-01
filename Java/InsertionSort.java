public class InsertionSort {
    void insert(int array[]) {  
        int i, j, temp;  
        int n = array.length;  
        for (i = 1; i < n; i++) {  
            temp = array[i];  
            j = i - 1;  
            while(j>=0 && temp <= array[j]) {    
                array[j+1] = array[j];     
                j = j-1;    
            }    
            array[j+1] = temp;    
        }  
    }  
    void printArray(int array[]) {  
        int i;  
        int n = array.length;  
        for (i = 0; i < n; i++)  
        System.out.println(array[i] + " ");  
    }

    public static void main(String args[]) {  
        int array[] = {52,86,43,67,94,108,252,52,16,23,7,3,33,50};  
        InsertionSort i1 = new InsertionSort(); 
        i1.insert(array);  
        System.out.println("\nThe sorted array is:");  
        i1.printArray(array);  
        System.out.println();  
    }
}
