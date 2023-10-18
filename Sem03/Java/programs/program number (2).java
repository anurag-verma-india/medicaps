import java.util.Scanner;

public class if_else_two_numbers_comparision {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int num1 = s.nextInt();
        System.out.print("Enter second number: ");
        int num2 = s.nextInt();

        // System.out.println(num1 < num2);
        if (num1 > num2) {
            System.out.println("The first number is greater");
        } else if (num1 < num2) {
            System.out.println("The second number is greater");
        } else {
            System.out.println("Both numbers are equal");
        }
    }
}
