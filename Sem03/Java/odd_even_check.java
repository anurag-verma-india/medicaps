import java.util.Scanner;

public class odd_even_check {
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);        
        System.out.print("Enter a number: ");
        int num = s.nextInt();
        if(num%2!=0)
        {
            System.out.printf("The number is odd");
        } else
        {
            System.out.printf("The number is even");
        }
    }
}
