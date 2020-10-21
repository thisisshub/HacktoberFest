public class Employee {
	
	public String name="";
    public String email_address;
    
    public void setName(String newName)  {
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
    }
  public String getDetails()  
   {
    	
	return("Name: " + getName() + "\n" + "Email: " + getEmail());
   }
			
}

