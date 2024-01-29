// Java program to illustrate error in case
// of unhandled exception

class tst {
    static void sum(int a, int b) {
    System.out.println("a + b = "+(a+b));
}
    public static void main(String[] args)
    throws InterruptedException, ArrayIndexOutOfBoundsException
    {
        // Thread.sleep(10000);
        // System.out.println("Hi mom");
        
        sum(4,5);   

    }
}

