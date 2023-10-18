import java.util.Scanner;

public class factorial_for_loop {

    public static void main(String [] args) {
        int num, fact;
        Scanner s = new Scanner(System.in);
        
        System.out.print("Enter a number: ");
        num = s.nextInt();
        
        fact = 1;
        for (int i =0;i < num; i++)
        {
            fact = fact * (num - i);
        }
        System.out.println("Factorial of "+num+" is " + fact);
    }
}
