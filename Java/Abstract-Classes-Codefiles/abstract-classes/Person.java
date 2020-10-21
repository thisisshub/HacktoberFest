
abstract public class Person {
	
	String name;
	int age;
	
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	//Concrete Method
	public void showBasicDetails()
	{
		System.out.println("Name:"+name);
		System.out.println("Age:"+age);
	}
    //abstract method
	abstract public void showDetails();


}
