import java.util.Scanner;

class bank_account
{
    Scanner s = new Scanner(System.in);
    public String name;
    int account_number;
    double balance;

    bank_account()
    {
        System.out.print("Enter your name: ");
        name = s.nextLine();
        System.out.print("Enter your account number: ");
        account_number = s.nextInt();
        System.out.print("Enter your balance: ");
        balance = s.nextDouble();
    }
    void display_balance()
    {
        System.out.println("\nAccount balance of " + name + " is " + balance + "\n");
    }
    
    void withdraw(double withdrawing_amount)
    {
        if (withdrawing_amount > balance)
        {
            System.out.println("Insufficinet Balance");
        } else
        {
            balance -= withdrawing_amount;
            System.out.println("Now your account balance is " + balance);
        }
    }
    void deposit(double deposit_amount)
    {
        balance += deposit_amount;
        System.out.println("Now your account balance is " + balance);
    }
}

public class bank
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);

        bank_account a1 = new bank_account();
        a1.display_balance();
        
        System.out.print("Enter the deposit amount: ");
        a1.deposit(s.nextDouble());
        System.out.print("Enter the withdrawing amount: ");
        a1.withdraw(s.nextDouble());
    }
}
