package com.quizapplication;

public class Game {

    Question[] questions=new Question[3];
    Player player=new Player();

    String[] questionsdata={"JAVA was created by _____?","What technology is used to record cryptocurrency transactions?","What tool would you use to reduce the digital image size?"};
    String[] options1={"Ross Ihaka","Digital wallet","Filter"};
    String[] options2={"James Gosling","Mining","Brush"};
    String[] options3={"Guido Van Rassum","Blockchain","Rotate"};
    String[] options4={"Rasmus Lerdorf","Token","Crop"};
    int[] answers={2,3,4};


    public void initGame() {

        for(int i=0;i<3;i++) {
            questions[i]=new Question();
        }


        for(int i=0;i<3;i++) {
            questions[i].question=questionsdata[i];
            questions[i].option1=options1[i];
            questions[i].option2=options2[i];
            questions[i].option3=options3[i];
            questions[i].option4=options4[i];
            questions[i].correctAnswer=answers[i];
        }

    }

    public void play() {

        player.getDetails();

        for(int i=0;i<3;i++) {
            boolean status=questions[i].askQuestion();
            if(status==true) {
                System.out.println("WOW! It's Correct Answer...!");
                player.score=player.score+5;
            }
            else {
                System.out.println("OOPS! It's Wrong Answer...!");
                player.score=player.score-5;
            }

        }

        System.out.println(player.name+" Your Score is : "+player.score);

    }
}
