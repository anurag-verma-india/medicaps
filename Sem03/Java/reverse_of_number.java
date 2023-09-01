import java.util.Scanner;

public class reverse_of_number {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("\n\nEnter a number: ");
        int num = s.nextInt();
        int reverse = 0;
        while (num > 0) {
            reverse = reverse * 10;
            reverse += num % 10;
            // num = (num - (num % 10)) / 10;
            num = num / 10;
            // System.out.println(reverse);
            // System.out.println(num + " x " + i + " = " + num * i);
        }
        System.out.println("Reverse of the number is " + reverse + "\n\n");
    }
}
