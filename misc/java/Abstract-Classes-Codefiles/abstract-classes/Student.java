
public class Student extends Person{
	
	int regno;
	char grade;

	
	public Student(String name, int age, int regno, char grade) {
		super(name, age);
		this.regno = regno;
		this.grade = grade;
	}


	public void showDetails()
	
	{
		System.out.println("Student regno:"+regno);
		System.out.println("Student grade:"+grade);
	}
	

}
