import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class InputStream
{
    public static void main(String[] args) throws IOException
    {
        //Enter data using BufferReader
        BufferedReader reader =
                   new BufferedReader(new InputStreamReader(System.in));

        // Reading data using readLine
        String name = reader.readLine();

        // Printing the read line
        System.out.println("Output: " + name);
    }
}
