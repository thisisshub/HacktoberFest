import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class MarksFile {
	
	
	public static void main(String[] args) {
		
		FileReader fr=null;
		
		try {
			fr=new FileReader("/home/spoken/Marks");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		finally{
			
			System.out.println("Inside finally block");
			try {
				fr.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		
		
		
		
		
		
		
		
	}

}

