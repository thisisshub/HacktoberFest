public class StringDemo {
    public static void main(String agrs[]){
        String greet = "HeLlO";
        String name = "JaVa";

        char SPACE = ' ';

        greet = greet.toLowerCase();
        name = name.toUpperCase();

        String msg = greet + SPACE + name;

        System.out.println(msg);
    }
}
