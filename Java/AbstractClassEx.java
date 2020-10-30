abstract class Op{
    abstract void isum();
    abstract void fsum();
}
class SumClass extends Op{
    void isum(){
        int a=10,b=20;
        System.out.println(a+b);
    }
    void fsum(){
        float a=20.98f,b=39.3f;
        System.out.println(a+b);

    }}

    class AbstractClassEx{
public static void main(String args[]) {
    Op op = new SumClass();
    op.isum();
    op.fsum();
}
}
