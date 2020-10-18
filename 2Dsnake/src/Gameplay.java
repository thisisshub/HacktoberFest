import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

public class Gameplay extends JPanel implements KeyListener, ActionListener {
    //for moving snake
    private int snakeXLength[]=new int[750];
    private int snakeYLength[]=new int[750];

    //default length of snake
    private int lengthOfSnake=3;

    //for detecting where the snake is moving
    private boolean left=false;
    private boolean right=false;
    private boolean up=false;
    private boolean down=false;

    //for snake face
    private ImageIcon rightMouth;
    private ImageIcon leftMouth;
    private ImageIcon upMouth;
    private ImageIcon downMouth;

    //for movement of snake (to manage speed)
    private Timer timer;
    private int delay=100;
    private int moves=0;

    //for loading the whole snake
    private ImageIcon snakeImage;

    //for loading the food
    private ImageIcon foodIcon;

    //Random Variables
    private Random random=new Random();

    //Random Positions
    private int xPos=random.nextInt(34);//total no of X positions horizontally
    private int yPos=random.nextInt(23);//total no of Y positions vertically

    //for UI
    private ImageIcon titleImage;

    //food positions
    private int foodXPosition[]={25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,
            425,450,475,500,525,550,575,600,625,650,675,700,725,750,775,800,825,850};
    private int foodYPosition[]={75,100,125,150,175,200,225,250,275,300,325,
            350,375,400,425,450,475,500,525,550,575,600,625};

    //for displaying the scores
    private int scores=0;

    public Gameplay(){
        //for default position of snake
        addKeyListener(this);
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);
        timer=new Timer(delay,this);
        timer.start();
    }
    public void paint(Graphics g){
        //to detect if the game has started
        if(moves==0){
            snakeXLength[2]=50;
            snakeXLength[1]=75;
            snakeXLength[0]=100;

            snakeYLength[2]=100;
            snakeYLength[1]=100;
            snakeYLength[0]=100;
        }

        //to draw title image border
        g.setColor(Color.WHITE);
        g.drawRect(24,10,851,55);

        //to draw title image
        titleImage=new ImageIcon("snaketitle.jpg");
        titleImage.paintIcon(this,g,25,11);

        //to draw border for playing area
        g.setColor(Color.WHITE);
        g.drawRect(24,74,851,577);

        //to draw background for the playing area
        g.setColor(Color.BLACK);
        g.fillRect(25,75,850,575);

        //to draw the Scores
        g.setColor(Color.WHITE);
        g.setFont(new Font("ariel",Font.PLAIN,20));
        g.drawString("Scores: "+scores, 770,45);

        //to define snake without any movement
        rightMouth=new ImageIcon("rightmouth.png");
        rightMouth.paintIcon(this,g,snakeXLength[0],snakeYLength[0]);

        for(int a=0;a<lengthOfSnake;a++){
            if(a==0 && right){
                rightMouth=new ImageIcon("rightmouth.png");
                rightMouth.paintIcon(this,g,snakeXLength[a],snakeYLength[a]);
            }
            if(a==0 && left){
                leftMouth=new ImageIcon("leftmouth.png");
                leftMouth.paintIcon(this,g,snakeXLength[a],snakeYLength[a]);
            }
            if(a==0 && down){
                downMouth=new ImageIcon("downmouth.png");
                downMouth.paintIcon(this,g,snakeXLength[a],snakeYLength[a]);
            }
            if(a==0 && up){
                upMouth=new ImageIcon("upmouth.png");
                upMouth.paintIcon(this,g,snakeXLength[a],snakeYLength[a]);
            }
            if(a!=0){
                //body of snake
                snakeImage=new ImageIcon("snakeimage.png");
                snakeImage.paintIcon(this,g,snakeXLength[a],snakeYLength[a]);
            }
        }

        //to draw food
        foodIcon=new ImageIcon("food.png");

        //to check if snake head collides with food
        if((foodXPosition[xPos]==snakeXLength[0]) && (foodYPosition[yPos]==snakeYLength[0])){
            scores++;
            lengthOfSnake++;



            xPos=random.nextInt(34);
            yPos=random.nextInt(23);
        }
        foodIcon.paintIcon(this,g,foodXPosition[xPos],foodYPosition[yPos]);

        //for detecting the collision
        for(int b=1;b<lengthOfSnake;b++){
            if((snakeXLength[b]==snakeXLength[0]) && (snakeYLength[b]==snakeYLength[0])){
                right=false;
                left=false;
                up=false;
                down=false;

                //to show game over
                g.setColor(Color.WHITE);
                g.setFont(new Font("ariel",Font.BOLD,50));
                g.drawString("GAME OVER",300,300);

                //to show instructions for restarting the game
                g.setFont(new Font("ariel",Font.BOLD,20));
                g.drawString("SPACE to Re-Start",350,340);
            }
        }

        g.dispose();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        timer.start();
        //to check the current direction of snake
        if(right){
            for(int r=lengthOfSnake-1;r>=0;r--){
                snakeYLength[r+1]=snakeYLength[r];
            }
            for(int r=lengthOfSnake;r>=0;r--){
                if(r==0){
                    snakeXLength[r]=snakeXLength[r]+25;
                }else{
                    snakeXLength[r]=snakeXLength[r-1];
                }
                //if snake head touches the boundary
                if(snakeXLength[r]>850){
                    snakeXLength[r]=25;
                }
            }
            repaint();
        }
        if(left){
            for(int r=lengthOfSnake-1;r>=0;r--){
                snakeYLength[r+1]=snakeYLength[r];
            }
            for(int r=lengthOfSnake;r>=0;r--){
                if(r==0){
                    snakeXLength[r]=snakeXLength[r]-25;
                }else{
                    snakeXLength[r]=snakeXLength[r-1];
                }
                //if snake head touches the boundary
                if(snakeXLength[r]<25){
                    snakeXLength[r]=850;
                }
            }
            repaint();
        }
        if(up){
            for(int r=lengthOfSnake-1;r>=0;r--){
                snakeXLength[r+1]=snakeXLength[r];
            }
            for(int r=lengthOfSnake;r>=0;r--){
                if(r==0){
                    snakeYLength[r]=snakeYLength[r]-25;
                }else{
                    snakeYLength[r]=snakeYLength[r-1];
                }
                //if snake head touches the boundary
                if(snakeYLength[r]<75){
                    snakeYLength[r]=625;
                }
            }
            repaint();
        }
        if(down){
            for(int r=lengthOfSnake-1;r>=0;r--){
                snakeXLength[r+1]=snakeXLength[r];
            }
            for(int r=lengthOfSnake;r>=0;r--){
                if(r==0){
                    snakeYLength[r]=snakeYLength[r]+25;
                }else{
                    snakeYLength[r]=snakeYLength[r-1];
                }
                //if snake head touches the boundary
                if(snakeYLength[r]>625){
                    snakeYLength[r]=75;
                }
            }
            repaint();
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {
            //do nothing
    }

    @Override
    public void keyPressed(KeyEvent e) {
        //if space key is pressed the game is restarted
        if(e.getKeyCode()==KeyEvent.VK_SPACE){
            moves=0;
            scores=0;
            lengthOfSnake=3;
            repaint();
        }

        //if arrow keys are pressed
        //if right key is pressed
        if(e.getKeyCode()==KeyEvent.VK_RIGHT){
            moves++;
            right=true;
            /*
            to make sure that the snake does not move in left direction
            while its moving in the right direction.
            this will make sure that if the user presses left key
            while the snake is moving in the right direction,
            the snake does not collides with itself.
            */
            if(!left){
                right=true;
            }else {
                right = false;
                left = true;
            }
            up=false;
            down=false;
        }
        //if left key is pressed
        if(e.getKeyCode()==KeyEvent.VK_LEFT){
            moves++;
            left=true;
            /*
            to make sure that the snake does not move in right direction
            while its moving in the left direction.
            this will make sure that if the user presses right key
            while the snake is moving in the left direction,
            the snake does not collides with itself.
            */
            if(!right){
                left=true;
            }else {
                left = false;
                right = true;
            }
            up=false;
            down=false;
        }
        //if up key is pressed
        if(e.getKeyCode()==KeyEvent.VK_UP){
            moves++;
            up=true;
            /*
            to make sure that the snake does not move in down direction
            while its moving in the up direction.
            this will make sure that if the user presses down key
            while the snake is moving in the up direction,
            the snake does not collides with itself.
            */
            if(!down){
                up=true;
            }else {
                up = false;
                down = true;
            }
            left=false;
            right=false;
        }
        //if down key is pressed
        if(e.getKeyCode()==KeyEvent.VK_DOWN){
            moves++;
            down=true;
            /*
            to make sure that the snake does not move in up direction
            while its moving in the down direction.
            this will make sure that if the user presses up key
            while the snake is moving in the down direction,
            the snake does not collides with itself.
            */
            if(!up){
                down=true;
            }else {
                down = false;
                up = true;
            }
            left=false;
            right=false;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
            //do nothing
    }
}
