class Employee
    {
        public string name;
        public int salary;
        public int joiningDate;

        public Employee()
        {

        }

        public Employee(string name, int salary, int joiningDate)
        {
            this.name = name;
            this.salary = salary;
            this.joiningDate = joiningDate;
        }

        public void GetEmployeeData()
        {
            {
                Console.WriteLine("Enter the name of employee: ");
                name = Convert.ToString(Console.ReadLine());
                Console.WriteLine("Enter the salary of employee: ");
                salary = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the date of joining of employee: ");
                joiningDate = Convert.ToInt32(Console.ReadLine());
            }
        }

        public void DisplayEmployee()
        {
            Console.WriteLine("The name of employee is: "+ name);
            Console.WriteLine("The salary of employee is: "+salary);
            Console.WriteLine("The date of joining of employee is: "+joiningDate);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Employee[] e = new Employee[10];
            for(int i = 0; i < 10; i++)
            {
                 Console.WriteLine($"Enter the data of employee with id: {i} *****************************************");
                e[i] = new Employee();
                e[i].GetEmployeeData();
            }

            Console.WriteLine("***********The data of given employees is: ");

            for(int i = 0; i < 10; i++)
            {
                e[i].DisplayEmployee();
            }
        }
    }
