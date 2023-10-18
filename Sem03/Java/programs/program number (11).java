public class sum_function_returning_int {
    static int sum()
    {
        int a, b, c;
        a=10; b=20;
        c = a+b;
        System.out.println("c = " + c);
        return c;
    }
    public static void main(String args[])
    {
        int x;
        x = sum();
        System.out.println("x = " + x);
    }
}
