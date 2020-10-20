import java.util.Scanner;

public class Tennis {

    private static int playerOneScore = 0;
    private static int playerTwoScore = 0;
    private static String playerTwoName;
    private static String playerOneName;

    Scanner sc = new Scanner(System.in);

    public Tennis(String playerOneName, String playerTwoName) {
        this.playerOneName = playerOneName;
        this.playerTwoName = playerTwoName;
    }

    static void singleDouble() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter S for single D for doubles: ");
        char gameType = sc.next().charAt(0);
        switch (gameType) {
            case 'S':
                playerName();
                break;
            case 'D':
                System.out.println("Not available");
                break;
        }
    }

    static void playerName() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter player one name : ");
        playerOneName = sc.nextLine();
        System.out.println("Enter player two name: ");
        playerTwoName = sc.nextLine();
        getToss();
    }

    static void getToss() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Player "+ playerOneName+" has to choose\nEnter Head or Tail :");
        String choise = sc.nextLine();
        switch (choise) {
            case "Head":
                flipCoin(choise);
                break;
            case "Tail":
                flipCoin(choise);
                break;
        }
    }

    static void flipCoin(String choise) {
        if (Math.random() < 0.5) {
            if (choise.equals("Head")) {
                System.out.println("Player "+ playerOneName+" won the toss");
                playsPlayerOne();
            } else {
                System.out.println("Player "+ playerTwoName+" won the toss");
                playsPlayerTwo();
            }
        } else {
            if (choise.equals("Tail")) {
                System.out.println("Player "+ playerOneName+" won the toss");
                playsPlayerOne();
            } else {
                System.out.println("Player "+ playerTwoName+" won the toss");
                playsPlayerTwo();
            }
        }
    }

    static void playsPlayerOne() {
        System.out.println("Playing Player "+ playerOneName);
        System.out.println("Enter \n1 for Fifteen \n2 for Thirty \n3 for Fourty\n4 for Hit\n5 to exit the game");
        Scanner sc = new Scanner(System.in);
        int score = sc.nextInt();
        
        switch (score) {
            case 3: playerTwoScore = playerTwoScore + 3;
            getScore();
            playsPlayerOne();
            break;
            case 2: playerTwoScore = playerTwoScore+2;
            getScore();
            playsPlayerOne();
            break;
            case 1: playerTwoScore = playerTwoScore+1;
            getScore();
            playsPlayerOne();
            break;
            case 4:
                playerOneScore = playerOneScore + 0;
                getScore();
                playsPlayerTwo();
                break;
            case 5:
            break;
        }
        
    }

    static void playsPlayerTwo() {
        System.out.println("Playing Player "+ playerTwoName+"");
        System.out.println("Enter \n1 for Fifteen \n2 for Thirty \n3 for Fourty\n4 for Hit\n5 to exit the game");
        Scanner sc = new Scanner(System.in);
        int score = sc.nextInt();
        
        switch (score) {
            case 3:playerOneScore = playerOneScore + 3;
            getScore();
            playsPlayerTwo();
            break;
            case 2:playerOneScore = playerOneScore + 2;
            getScore();
            playsPlayerTwo();
            break;
            case 1:playerOneScore = playerOneScore + 1;
            getScore();
            playsPlayerTwo();
            break;
            case 4: playerTwoScore = playerTwoScore+0;
            getScore();
            playsPlayerOne();
            break;
            case 5:
            break;
        }
        
    }

    static void getScore(){
        System.out.println("Points of "+ playerOneName+" = "+playerOneScore+" , "+ playerTwoName+" = "+playerTwoScore);
        if(playerOneScore == 3 && playerTwoScore == 3){
            System.out.println("Its Deuce");
        }
        else if(playerOneScore == playerTwoScore+1){
            System.out.println("Player "+ playerOneName+" is in advantage");
        }
        else if(playerTwoScore == playerOneScore+1){
            System.out.println("Player "+ playerTwoName+" is in advantage");
        }
        else if(playerOneScore > 4 || playerTwoScore > 4){
            if(playerOneScore == playerTwoScore+2){
                System.out.println("Player "+ playerOneName+" Wins");
            }
            else{
                System.out.println("Player "+ playerTwoName+" Wins");
            }
        }
    }

    public static void main(String args[]) {
        singleDouble();
        getScore();
    }
}
