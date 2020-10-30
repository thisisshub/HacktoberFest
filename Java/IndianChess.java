import java.util.Random;

class Player extends Thread{ 
        
        static int p1=-1;
        static int p2=-1;
        static boolean p1st=false;
        static boolean p2st=false;
        static int p1x=-1,p2x=-1,p1y=-1,p2y=-1;
        static int gameTurn=1;
        int turn;
        int num;
        char pawn;
        char arr[] = new char[49];
        static char board[][] = new char[7][7];
        Player(char p,int t,int n)
        {
            pawn=p;
            turn=t;
            num=n;
            for(int i=0;i<49;i++)
            {
                arr[i]='*';
            }
        }
    public void run(){
        for(int i=0;i<7;i++)
            for(int j=0;j<7;j++)
                board[i][j]='*';
        while(p1<=48 && p2<=48)
        {
            System.out.print("");
            if(turn==gameTurn && num==1)
            {
                System.out.println("Player 1 turn");
                if(p1<0)
                    StartMove(pawn,3,0,board);
                else
                    Move(arr,pawn,board);
                gameTurn=2;
            }
            if(turn==gameTurn && num==2)
            {
                System.out.println("Player 2 turn");
                if(p2<0)
                    StartMove(pawn,3,6,board);
                else
                    Move(arr,pawn,board);
                gameTurn=1;
            }
        }
    }

    public static void Move(char arr[],char pawn, char board[][])
    {       
            int move;
            do{
            move=MoveGen();
            if(move==7)
                move=12; 
            System.out.println("Number moved: "+move);           
            if(pawn=='@'){
            if(p1+move<=48)
            {
                arr[p1]='*';
                p1+=move;
                arr[p1]=pawn;
            }
            P1WriteBoard(arr,board);
            if(p1==48)
                GameOver(0);
            }
            else{
            if(p2+move<=48)
            {
                arr[p2]='*';
                p2+=move;
                arr[p2]=pawn;
            }
            P2WriteBoard(arr,board);
            if(p2==48)
                GameOver(1);
            }
            }while(move==1|| move>=5);
    }
    
    public static void GameOver(int x)
    {
        if(x==0)
            System.out.println("Player1 won");
        else
            System.out.println("Player2 won");
        System.exit(0);
    }
    
    public static void P1WriteBoard(char arr[], char mat[][])
    {
        int x=21,i;
        for(i=0;i<7;i++)
        {
            if(mat[0][i]=='#' && arr[x]=='@')
                p2=-1;
            mat[0][i]=arr[x--];
        }
        x=3;
        for(i=0;i<7;i++)
        {
            if(mat[6][i]=='#' && arr[x]=='@')
                p2=-1;
            mat[6][i]=arr[x++];
        }
        if(mat[1][0]=='#' && arr[22]=='@')
            p2=-1;
        mat[1][0]=arr[22];
        x=24;
        for(i=1;i<=5;i++)
        {
            if(mat[1][i]=='#' && arr[x]=='@')
                p2=-1;
            mat[1][i]=arr[x++];
        }
        if(mat[1][6]=='#' && arr[14]=='@')
            p2=-1;
        mat[1][6]=arr[14];
        if(mat[2][0]=='#' && arr[23]=='@')
            p2=-1;
        mat[2][0]=arr[23];
        x=39;
        for(i=1;i<=4;i++)
        {
            if(mat[2][i]=='#' && arr[x]=='@')
                p2=-1;
            mat[2][i]=arr[x++];
        }
        if(mat[2][5]=='#' && arr[29]=='@')
            p2=-1;
        mat[2][5]=arr[29];
        if(mat[2][6]=='#' && arr[13]=='@')
            p2=-1;
        mat[2][6]=arr[13];
        x=0;
        for(i=3;i<=5;i++)
        {
            if(mat[i][0]=='#' && arr[x]=='@')
                p2=-1;
            mat[i][0]=arr[x++];
        }
        if(mat[3][1]=='#' && arr[38]=='@')
            p2=-1;
        mat[3][1]=arr[38];
        if(mat[3][2]=='#' && arr[47]=='@')
            p2=-1;
        mat[3][2]=arr[47];
        if(mat[3][3]=='#' && arr[48]=='@')
            p2=-1;
        mat[3][3]=arr[48];
        if(mat[3][4]=='#' && arr[43]=='@')
            p2=-1;
        mat[3][4]=arr[43];
        x=38;
        for(i=3;i<=5;i++)
        {
            if(mat[i][1]=='#' && arr[x]=='@')
                p2=-1;
            mat[i][1]=arr[x--];
        }
        x=30;
        for(i=3;i<=5;i++)
        {
            if(mat[i][5]=='#' && arr[x]=='@')
                p2=-1;
            mat[i][5]=arr[x++];
        }
        x=12;
        for(i=3;i<=5;i++)
        {            
            if(mat[i][6]=='#' && arr[x]=='@')
                p2=-1;
            mat[i][6]=arr[x--];
        }
        x=46;
        for(i=2;i<=4;i++)
        {
            if(mat[4][i]=='#' && arr[x]=='@')
                p2=-1;
            mat[4][i]=arr[x--];
        }
        x=35;
        for(i=2;i<=5;i++)
        {
            if(mat[5][i]=='#' && arr[x]=='@')
                p2=-1;
            mat[5][i]=arr[x--];
        }
        if(p2==-1 && p2st)
        {
            System.out.println("Opponent piece cut");
            p2x=-1;
            p2y=-1;
        }
        else
        if(p2x>=0 && p2y>=0)
            mat[p2x][p2y]='#';
        for(i=0;i<7;i++)
            for(int j=0;j<7;j++)
            {
                if(mat[i][j]=='@')
                {
                    p1x=i;
                    p1y=j;
                }
            }
        DispBoard(mat);
    }
    public static void P2WriteBoard(char arr[], char mat[][])
    {
        int x=9,i;
        for(i=0;i<7;i++)
        {
            if(mat[0][i]=='@' && arr[x]=='#')
                p1=-1;
            mat[0][i]=arr[x--];
        }
        if(mat[1][0]=='@' && arr[10]=='#')
            p1=-1;
        mat[1][0]=arr[10];
        x=32;
        for(i=1;i<=5;i++)
        {
            if(mat[1][i]=='@' && arr[x]=='#')
                p1=-1;
            mat[1][i]=arr[x++];
        }
        x=3;
        for(i=0;i<=3;i++)
        {
            if(mat[i][6]=='@' && arr[x]=='#')
                p1=-1;
            mat[i][6]=arr[x--];
        }
        x=9;
        for(i=0;i<=6;i++)
        {
            if(mat[i][0]=='@' && arr[x]=='#')
                p1=-1;
            mat[i][0]=arr[x++];
        }
        x=23;
        for(i=4;i<=6;i++)
        {
            if(mat[i][6]=='@' && arr[x]=='#')
                p1=-1;
            mat[i][6]=arr[x--];
        }
        x=16;
        for(i=1;i<=5;i++)
        {
            if(mat[6][i]=='@' && arr[x]=='#')
                p1=-1;
            mat[6][i]=arr[x++];
        }
        x=28;
        for(i=1;i<=5;i++)
        {
            if(mat[5][i]=='@' && arr[x]=='#')
                p1=-1;
            mat[5][i]=arr[x--];
        }
        
        x=31;
        for(i=2;i<=4;i++)
        {
            if(mat[i][1]=='@' && arr[x]=='#')
                p1=-1;
            mat[i][1]=arr[x--];
        }
        x=44;
        for(i=2;i<=4;i++)
        {
            if(mat[i][2]=='@' && arr[x]=='#')
                p1=-1;
            mat[i][2]=arr[x--];
        }
        x=41;
        for(i=3;i<=5;i++)
        {
            if(mat[4][i]=='@' && arr[x]=='#')
                p1=-1;
            mat[4][i]=arr[x--];
        }
        x=45;
        for(i=3;i<=4;i++)
        {
            if(mat[2][i]=='@' && arr[x]=='#')
                p1=-1;
            mat[2][i]=arr[x++];
        }
        x=37;
        for(i=2;i<=3;i++)
        {
            if(mat[i][5]=='@' && arr[x]=='#')
                p1=-1;
            mat[i][5]=arr[x++];
        }
        x=48;
        for(i=3;i<=4;i++)
        {
            if(mat[3][i]=='@' && arr[x]=='#')
                p1=-1;
            mat[3][i]=arr[x--];
        }
        if(p1==-1 && p1st)
        {
            System.out.println("Opponent piece cut");
            p1x=-1;
            p1y=-1;
        }
        else
        if(p1x>=0 && p1y>=0)
            mat[p1x][p1y]='@';
        for(i=0;i<7;i++)
            for(int j=0;j<7;j++)
            {
                if(mat[i][j]=='#')
                {
                    p2x=i;
                    p2y=j;
                }
            }
        DispBoard(mat);
    }
    
    public static void DispBoard(char mat[][])
    {
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
                System.out.print(mat[i][j]+" ");
            System.out.print("\n");
        }
        System.out.println();
    }
    public static void StartMove(char a,int x,int y,char mat[][])
    {        
        int move=MoveGen();
        if(move==1)
        {   
            mat[x][y]=a;
            if(a=='@')
            {
                p1=0;
                p1st=true;
                p1x=3;
                p1y=0;
            }
            else
            {
                p2=0;
                p2st=true;
                p2x=3;
                p2y=6;
            }
            DispBoard(mat);
        }
        if(move>=5)
            StartMove(a,x,y,mat);
    }
    public static int MoveGen()
    {
        Random rand = new Random();
        return 1+rand.nextInt(7);
    }
}

public class IndianChess {
    public static void main(String args[])
    {
        Player pla1 = new Player('@',1,1);
        Player pla2 = new Player('#',2,2);
        pla1.start();
        pla2.start();
    }
}
