class A extends Thread{
    public void run(){
        for(int i = 0 ; i <= 50 ; i++){
            System.out.println("T A " + i);
        }
        System.out.println("T A out ");
    }
}

class B extends Thread{
    public void run(){
        for(int i = 0 ; i <= 50 ; i++){
            System.out.println("T B " + i);
        }
        System.out.println("T B out ");
    }
}

class C extends Thread{
    public void run(){
        for(int i = 0 ; i <= 50 ; i++){
            System.out.println("T C " + i);
        }
        System.out.println("T C out ");
    }
}

public class MultiThreat {
 
    public static void main(String args[]){
        new A().start();
        new B().start();
        new C().start();
    }
    
}
