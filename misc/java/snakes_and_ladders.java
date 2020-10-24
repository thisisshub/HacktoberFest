import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import javafx.util.Pair;

public class Solution 
{
    public static void main(String[] args) throws IOException 
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
      while(t-- > 0)
      {
        HashMap<Integer, Integer> ladder = new HashMap<>();
        HashMap<Integer, Integer> snake = new HashMap<>();
        int n = sc.nextInt();
        for(int i=0;i<n;i++)
        {
            int x = sc.nextInt();
            int y = sc.nextInt();
            ladder.put(x,y);
        }
        int m = sc.nextInt();
        for(int i=0;i<m;i++)
        {
            int x = sc.nextInt();
            int y = sc.nextInt();
            snake.put(x,y);
        }
        
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        int ans = 1000;
        q.add(new Pair<Integer,Integer> (1,0));

        boolean visited[] = new boolean[101];

        for(int i=0;i<101;i++)
        {
            visited[i] = false;
        }
        visited[1] = true;

        while(q.size() != 0)
        {
            Pair<Integer, Integer> p = q.poll();
            if(p.getKey() == 100)
            {
                ans = p.getValue();
                break;
            }

            for(int i=1;i<=6;i++)
            {
                int k = p.getKey();
                k+=i;
                if(k <= 100 && visited[k] == false)
                {
                    visited[k] = true;
                    if(ladder.containsKey(k))
                    {
                       int l = ladder.get(k);
                       q.add(new Pair<Integer, Integer> (l, p.getValue()+1 ));
                       visited[l] = true;
                    }
                    else if(snake.containsKey(k))
                    {
                        int l = snake.get(k);
                        q.add(new Pair<Integer, Integer> (l, p.getValue()+1 ));
                        visited[l] = true;
                    }
                    else
                    {
                        q.add(new Pair<Integer, Integer> (k, p.getValue()+1 ));
                    }
                    
                }
            }

        }
        if(ans == 1000)
        {
            System.out.println("-1");
        }
        else
        {
            System.out.println(ans);
        }
      }
    }
}
