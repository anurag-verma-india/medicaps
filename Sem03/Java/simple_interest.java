import java.util.Scanner;

public class simple_interest {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter principal amount: ");
        double principal = input.nextDouble();
        System.out.print("Enter interest rate: ");
        double rate = input.nextDouble();
        System.out.print("Enter interest duration: ");
        double time= input.nextDouble();

        double interest = (principal * time * rate) /100;

        System.out.println("\nPrincipal: "+principal);
        System.out.println("Interest rate: "+rate);
        System.out.println("Time Duration: "+time);
        System.out.println("Simple Interest: "+interest);
    }
}
