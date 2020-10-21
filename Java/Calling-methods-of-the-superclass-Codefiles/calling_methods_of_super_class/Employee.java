public class Employee {
	
	public String name="";
    public String email_address;
    public Employee(String name, String email_address)  {

        this.name=name;

        this.email_address=email_address;

     }
   
   /* public void setName(String newName)  {
    	name=newName;
    }
    
    public String getName()  {
    	return name;
    }
    
    public void setEmail(String newEmail)  {
    	email_address=newEmail;
    }
    
    public String getEmail() {
    	return email_address;
    }*/
  public String getDetails()  
   {
    	
	return("Name: " + name + "\n" + "Email: " + email_address);
   }
			
}

