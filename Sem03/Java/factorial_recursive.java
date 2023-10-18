import java.util.Scanner;

public class factorial_recursive {
    static int factorial(int num)
    {
        if(num==1){
            return 1;
        } else
        {
            return num*factorial(num - 1);
        }
    }
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = s.nextInt();
        System.out.println("Factorial of "+num+" is: "+factorial(num));
    }
}
