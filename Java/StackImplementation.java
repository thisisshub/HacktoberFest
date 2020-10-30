class MyStack
{
    int[] arr;
    int top;
    /* Methods in Stack: push,pop, peek,Empty */
    public MyStack(int n)
    {
        arr = new int[n];
        top= -1;
    }
    
    public boolean Empty()
    {
        return (top<0) ; 
    }
    
    public void push(int data)
    {
        if(top == arr.length)
        {
            System.out.println("Stack OverFlow!!");
            return ;
        }
        else
        {
            top++;
            arr[top]=data;
        }
    }
    
    public int pop() throws Exception
    {
        if(Empty())
        {
            throw new Exception("Stack underflow!!");
            // System.out.println("Stack UnderFlow!!");
            // return 0 ;
        }
            int poppeddata = arr[top];
            top--;
            return poppeddata; 
    }
    
    public int peek()
    {
        if(Empty())
        {
            System.out.println("Stack UnderFlow!!");
            return 0 ;
        }
            return arr[top]; 
    }
    
    public void print()
    {
        for(int i = 0; i<=top;i++)
            System.out.print(arr[i]+" ");
    }
    
}

public class StackImplementation {
    public static void main(String[] args) 
    {
        MyStack stk = new MyStack(10);
        
        stk.push(3);
        stk.push(4);
        stk.push(7);
        stk.push(9);
        
        try{
        System.out.println(stk.pop());
        System.out.println(stk.peek());
        
        System.out.println(stk.pop());
        System.out.println(stk.pop());        
        System.out.println(stk.pop());
        System.out.println(stk.pop());
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
        stk.print();
    }
}