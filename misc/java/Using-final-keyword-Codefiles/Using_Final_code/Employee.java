final public class Employee {
	
    public static final String name;
    public String email_address;
    
    /* 
    public void setName(String newName)  {
    	name=newName;
    }
    */
    
    static{ 
    	name="Sneha";
    }
    
    public String getName()  {
    	return name;
    }
    
    public void setEmail(final String newEmail)  {
    	email_address=newEmail;
    	// newEmail="kinitrupti@gmail.com";
    }
    
    public String getEmail() 
    {
    	return email_address;
    }
    
    public String getDetails()  
    {
    	
	return("Name: " + getName() + "\n" + "Email: " + getEmail());
    }
			
}

