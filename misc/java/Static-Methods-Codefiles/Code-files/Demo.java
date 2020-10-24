
public class Demo {
	public static void main(String[] args) {
		//System.out.println("Student Enrollment Data");
		StudentEnroll s1=new StudentEnroll("IT101","ADIL");
		StudentEnroll s2=new StudentEnroll("CS101","AMAL");
		StudentEnroll s3=new StudentEnroll("CS101","CAROL");


		s1.showData();
		s2.showData();
		s3.showData();
		StudentEnroll.showOrgData();

		StudentEnroll.setOrgName("IIT Mumbai", s1);

		s1.showData();
		s2.showData();
		s3.showData();
		StudentEnroll.showOrgData();		

	}
}


