/*
A string containing only parentheses is balanced if the following is true: 1. if it is an empty string 2. if A and B are correct, AB is correct, 3. if A is correct, (A) and {A} and [A] are also correct.

Examples of some correctly balanced strings are: "{}()", "[{()}]", "({()})"

Examples of some unbalanced strings are: "{}(", "({)}", "[[", "}{" etc.

Given a string, determine if it is balanced or not.
*/

import java.util.*;
public class BalancedBrackets{
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
			String input=sc.next();
      Stack<String> s=new Stack<String>();
      boolean v=true;
      for(int i=0;i<input.length();i++){
          char h=input.charAt(i);
          String ch=String.valueOf(h);
          if(h=='('|| h=='{' || h=='['){
              s.push(ch);
          }else{
          try{
            String c=s.pop();
            if(h==')'){
               if(!(c.equals("("))){
                   v=false;
                   break;
                }
             } if(h=='}'){
             if(!(c.equals("{"))) 
             {
                  v=false;
                  break;
             }
             }if(h==']'){
             if(!(c.equals("["))){
                  v=false;
                  break;
               } 
             }
          }catch(Exception e){
              v=false;          
          }
         }
        }
      if(v&&s.isEmpty()) System.out.println(true);
      else System.out.println(false);
   }
	}
}



