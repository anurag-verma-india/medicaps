import java.util.Scanner;

public class sum_function_returning_int {
    static int sum(int num1, int num2)
    {
        return num1+num2;
    }
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int num1 = s.nextInt();
        System.out.print("Enter second number: ");
        int num2= s.nextInt();
        System.out.println("Sum = "+sum(num1, num2));
    }
}
