
public class Demo {
	
	public static void main(String[] args) {
		
		//Person p=new Person("John");cannot instantiate
		Person p1=new Employee("John",40,"E267",10000);
		p1.showBasicDetails();
		p1.showDetails();
		
		Person p2=new Student("Hari",20,12005,'A');
		p2.showBasicDetails();
		p2.showDetails();
		
	}

}
