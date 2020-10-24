import java.io.FileNotFoundException;
import java.io.FileReader;

public class StudentMarks {
	int marks;

	public StudentMarks(int marks) {
		this.marks = marks;
	}
public void validate() throws InvalidMarkException, FileNotFoundException
{
if (marks<0 || marks>100)
	throw new InvalidMarkException(marks+" is not a valid entry");
else

	System.out.println("Entry OK");
	FileReader fr=null;
	fr=new FileReader("/home/spoken/Marks");
}

public static void main(String[] args) {
	
	StudentMarks m1=new StudentMarks(40);
	

	
			try {
				m1.validate();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InvalidMarkException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		 
	
	
	System.out.println("rest of the code");
	
}




}
