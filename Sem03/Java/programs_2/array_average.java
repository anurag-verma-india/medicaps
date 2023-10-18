import java.util.Scanner;

public class array_average {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int c = 0;
        // int a[] = { 1, 2, 3, 4, 5 };
        int a[] = new int[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter a["+ i +"] = ");
            a[i] = s.nextInt();
            c += a[i];
        }
        System.out.println("Average of the given values is " + c / 5);
    }
}