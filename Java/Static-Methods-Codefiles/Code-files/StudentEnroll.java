
public class StudentEnroll {
	private String id, name;
	private static int count;
	private static String orgname="IIT Bombay";

	public StudentEnroll(String id, String name) {
		this.id = id;
		this.name = name;
		count++;
	}
	
	public void showData()
	{
		System.out.println(id+" "+name+" "+orgname);
			
	}

	public static void setOrgName(String org,StudentEnroll s)
	{
		orgname=org;
                //id="newid";
		//to be done later
		s.id="newid";
	}
	public static void showOrgData()
	{
		System.out.println("\nORGANISATION DATA");
		System.out.println("Name:"+orgname);
		System.out.println("Total Students Enrolled:"+count+"\n");

	}

	




}
