import java.util.Stack;

public class ValidParentheses {
    public static boolean isValid(String s) {
        if (s.length() == 0 || s.length() == 1) {
            return false;
        }

        Stack<Character> leftParentheses = new Stack<>();
        leftParentheses.push('X');

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '{' || s.charAt(i) == '[' || s.charAt(i) == '(') {
                leftParentheses.push(s.charAt(i));
            } else {
                if (pair(leftParentheses.peek(), s.charAt(i))) {
                    leftParentheses.pop();
                } else {
                    return false;
                }
            }
        }
        return leftParentheses.size() == 1;
    }

    private static boolean pair(char a, char b) {
        if (a == '{' && b == '}') {
            return true;
        } else if (a == '[' && b == ']') {
            return true;
        } else return a == '(' && b == ')';
    }

    public static void main(String[] args) {
        String parentheses = "{}[]()())";

        System.out.println(isValid(parentheses));
    }
}