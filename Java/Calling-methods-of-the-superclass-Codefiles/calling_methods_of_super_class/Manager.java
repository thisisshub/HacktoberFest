
public class Manager extends Employee{
	
	public String department="";
	
	public Manager(String name, String email_address, String dept)  {

	       super(name,email_address);

	       department=dept;

	   }
	
	
public void setDepartment(String newDepartment)  {
		department=newDepartment;
	}
	
	public String getDepartment()  {
		return department;
	}
	
	@Override
	public String getDetails()  {

		return ( super.getDetails()+"\n"

		        +"Manager of: " + department);

		}
}




