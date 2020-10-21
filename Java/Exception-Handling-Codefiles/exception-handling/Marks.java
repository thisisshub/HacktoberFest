


public class Marks {
public static void main(String[] args) {
	
//unchecked exception example
	int[] marks={30,40,35,34,45}; 
	int a=0;
	
	try{
		
		 System.out.println(marks[2]/a);
		System.out.println("\t"+marks[50]);
	   
	}
	
	catch(ArrayIndexOutOfBoundsException e){
		
		System.out.println("Array Overflow Exception occurred");
	}
		
	catch(ArithmeticException e){
		System.out.println("Arithmetic Exception occurred");
	}
	
	
	
	//rest of the code 
	
	System.out.println("Mark List");
	for(int i=0;i<5;i++){
		
		System.out.println(marks[i]);
	}	
	
	}
	
	
}
