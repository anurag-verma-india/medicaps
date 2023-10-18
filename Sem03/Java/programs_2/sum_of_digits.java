import java.util.Scanner;

public class sum_of_digits {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("\n\nEnter a number: ");
        int num = s.nextInt();
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num = (num - (num % 10)) / 10;
        }
        System.out.println("Sum of the digits of number is " + sum + "\n\n");
    }
}
