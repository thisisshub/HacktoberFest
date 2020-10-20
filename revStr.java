public class FinalReverseWithoutUsingInbuiltFunction {
    public static void main(String[] args) {
        String str = "Saket Saurav";
        char chars[] = str.toCharArray();  // converted to character array and printed in reverse order
        for(int i= chars.length-1; i&gt;=0; i--) {
            System.out.print(chars[i]);
        }
    }
}
