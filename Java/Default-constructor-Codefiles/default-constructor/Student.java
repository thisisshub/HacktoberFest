public class Student {

	 int roll_number;
	 String name;
	 
	 Student()
	 {
		 roll_number=10;
		 name="Raman";
	 }
	 void studentDetail()
	 {
		 System.out.println(roll_number);
		 System.out.println(name);
	 }
	public static void main(String[] args) {
		Student stu = new Student();
 		stu.studentDetail();
	}

}
