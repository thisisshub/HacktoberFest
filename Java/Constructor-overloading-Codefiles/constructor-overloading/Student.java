public class Student {

	 int roll_number;
	 String name;
	 Student(int number, String the_name)
	 {
		 roll_number=number;
		 name=the_name;
	 }
	 Student(int num)
	 {
		  roll_number=num;
		  name = "no name";
	 }
	 Student()
	 {
		 roll_number=0;
		 name="-";
	 }
	 Student(String the_name,int r_no)
	 {
		 roll_number=r_no;
		 name=the_name;
	 }
	 
	 void studentDetail()
	 {
		 System.out.println(roll_number);
		 System.out.println(name);
	 }
	public static void main(String[] args) {
		Student s = new Student(22,"Ram");
		s.studentDetail();
		Student s2= new Student();
		s2.studentDetail();
		Student s3= new Student("Raju",45);
		s3.studentDetail();
		Student s4 = new Student(61);
		s4.studentDetail();
		
	}

}
