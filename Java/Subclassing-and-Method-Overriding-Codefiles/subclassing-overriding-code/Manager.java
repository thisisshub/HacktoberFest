
public class Manager extends Employee{
	
	public String department="";
	
	public void setDepartment(String newDepartment)  {
		department=newDepartment;
	}
	
	public String getDepartment()  {
		return department;
	}
	@Override
	 public String getDetails()  
	     {
	    return ( "Name: " + getName() + "\n" + "Email: " +getEmail()+"\n"
	     +"Manager of: " + getDepartment());
	    }

}




