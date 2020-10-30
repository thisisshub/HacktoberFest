public class StudentEnroll {
	private String id, name, branch;
	public static int count;
	public static String orgname;
	
	

	public StudentEnroll(String id, String name, String branch) {
		System.out.println("constructor invoked");
		this.id = id;
		this.name = name;
		this.branch = branch;
		}
		
		
	static {
		System.out.println("static block-1 is invoked");
	count=100;
	orgname="IITM";
	//id="IT01";
	}


	static {
	System.out.println("static block-2 invoked");
	count=200;
	orgname="IITB";
	}	
		
	         public void showData()
	{
         
		System.out.println(id+" "+name+" "
		+branch+" "+count+ " "+orgname);
		
	}
	
	
}