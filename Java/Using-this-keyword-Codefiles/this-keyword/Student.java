public class Student {

	 int roll_number;
	 String name;
	 
	 Student()
	 {this(11);
		 System.out.println("I am Default Constructor");
		/* roll_number=0;
		 name=null;*/
	 }
	 Student(int r_no)
	 {this(11,"Raju");
		 System.out.println("I am a constructor with a single parameter");
		// roll_number=r_no;
	 }
	 Student(int roll_number,String name)
	 {
		 System.out.println("I am Parameterized Constructor");
		 roll_number=this.roll_number;
		 name=this.name;
	 }
	 void studentDetail()
	 {
		 System.out.println(roll_number);
		 System.out.println(name);
	 }
	public static void main(String[] args) {
		 Student stu = new Student();
		 stu.studentDetail();
		/* Student stu2 = new Student(11);
		 stu2.studentDetail();
		 Student stu3=new Student(11,"Raju");
		 stu3.studentDetail();*/
		

	}

}
