/**
 * stackmain
 */



class stack{
    int top=-1;
    int limit = 5;
    float array[] = new float[limit];

    boolean push(float x)
    {
        if (top >= (limit - 1)) {
            System.out.println("Stack Overflow");
            return false;
        }
        else {
        array[++top] = x;
            return true;
        }
    }

    float pop()
    {
        if (top < 0) {
            System.out.println("Stack Underflow");
            return 0;
        }
        else {
            float x = array[top--];
            return x;
        }
    }

    void display() {
        for(int i=top;i>=0;i--) {
            System.out.println("| " + array[i] + " ");
        }
        System.out.println("\n");
    }

    public static void copy(stack s1, stack s2){
        int i;
        for(i=0;i<=s1.top;i++) {
            s2.array[i] = s1.array[i];
        }
        s2.top = s1.top;
    }
 
}


 class stack_implementation {




    public static void main(String[] args) {
        stack stack1 = new stack();
        stack stack2 = new stack();
        stack1.push(2.1f);
        stack1.push(2.2f);
        stack1.push(2.3f);
        stack1.pop();
        stack1.push(2.4f);
        stack1.pop();
        stack.copy(stack1,stack2);
        stack1.display();
        stack2.display();
    }
}