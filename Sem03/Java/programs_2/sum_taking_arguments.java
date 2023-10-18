class sum_taking_arguments {
    static void sum(int a, int b)
    {
        int c;
        c = a = b;
        System.out.println("c = " + c);
    }
    public static void main(String args[])
    {
        int x, y;
        x = 20;
        y=30;
        sum(x,y);
        sum(100, 200);
    }
}