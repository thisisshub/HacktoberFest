
public class Demo {
	public static void main(String[] args) {
		

		StudentEnroll s1=new StudentEnroll("IT101","ADIL","IT");
		StudentEnroll s2=new StudentEnroll("EC101","AMAL","EC");
		StudentEnroll s3=new StudentEnroll("CS101","CAROL","CS"); 

		s1.showData();
		s2.showData();
		s3.showData();
		
		System.out.println("Organisation:"+StudentEnroll.ORG_NAME);

}
	}

