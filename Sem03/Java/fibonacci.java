import java.util.Scanner;

public class fibonacci {
    static int fibonacci_rec(int previous, int penultimate, int count) {
        int next = previous+penultimate;
        if(count>0){
            System.out.print("  "+next);
            return fibonacci_rec(previous+penultimate, previous, count-1);
        } else
        {
            return -1;
        }
    }
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = s.nextInt();
        System.out.print(0+"  "+1);
        fibonacci_rec(1, 0, num-2);
    }
}
