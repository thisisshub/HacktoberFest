/*In this problem, you have to add and multiply huge numbers! These numbers are so big that you can't contain them in any ordinary data types like a long integer. */

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class JavaBigDecimal 
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        BigInteger a=new BigInteger(sc.next());
        BigInteger b=new BigInteger(sc.next());
        System.out.println(a.add(b));
        System.out.println(a.multiply(b));
    }
}
