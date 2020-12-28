import java.sql.*;
import java.util.*;
import java.io.Console;
class jdbc2{
	
	public static void main(String args[]){
		try{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/school","root","root");
			Statement stmt = conn.createStatement();
		 	stmt.executeUpdate("create table student007(roll int,name varchar(20),per float)");
			int roll;
			String name;
			float per;
			Console con = System.console();
			while(true){
				System.out.print("enter roll no or -1 to exit:");
				roll =  Integer.parseInt(con.readLine());
				if(roll == -1)
					break;
				System.out.print("enter name:");
				name = con.readLine();
				
				System.out.print("enter per:");
				per = Float.parseFloat(con.readLine());
				
				int cnt = stmt.executeUpdate("insert into student007 values( "+roll+",'"+name+"',"+per+")");
				if(cnt == 1)
				System.out.println("Record inserted successfully");
				
			}
			ResultSet rst =  stmt.executeQuery("select * from student007");
			while(rst.next()){
					System.out.println(rst.getInt(1)+"\t"+rst.getString(2)+"\t"+rst.getFloat(3));
			}
			conn.close();
			
				
			
		}	
		catch(ClassNotFoundException e){
			e.printStackTrace();
		}
		catch(SQLException e){
			e.printStackTrace();
		}
	}
}