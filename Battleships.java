import java.util.Scanner;
public class BattleShips
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        String board[][]=new String[5][5];
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                board[i][j]="O";
            }
        }
        int turn=0,guessRow=5,guessCol=5;
             
       
        int row=(int)(Math.round(Math.random()*4));
        int col=(int)(Math.round(Math.random()*4));
        
        System.out.println();
        System.out.println();
        while(guessRow!=row  || guessCol!=col)
        {
            System.out.println("\f");
            System.out.println("BATTLESHIPS!");
             for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {   
                    System.out.print(board[i][j]+"  ");

                }
                System.out.println();
            }
             
         System.out.println("Turn: "+ ++turn);
         System.out.println("Guess a row (from 0 to 4): ");
          guessRow=s.nextInt();
          System.out.println("Guess a column (from 0 to 4): ");
          guessCol=s.nextInt();
         if(row==guessRow && col==guessCol)
         {
             board[row][col]="#";
          System.out.println("You've sunk my ship!");
         break;
        }
         else if(guessRow>4 || guessCol>4)
         {
         System.out.println("Coordinates are not in the ocean");
       }
         else
         {
           System.out.println("You've missed my ship!");
           board[guessRow][guessCol]="X";
         
    }
    
}
board[row][col]="#";
 for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {   
                System.out.print(board[i][j]+"  ");
            }
            System.out.println();
        }
}
}



