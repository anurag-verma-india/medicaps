import java.util.Scanner;

public class array_average {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int sum = 0;
        // int a[] = { 1, 2, 3, 4, 5 };
        int arr[] = new int[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter a["+ i +"] = ");
            arr[i] = s.nextInt();
            sum += arr[i];
        }
        System.out.println("Average of the given values is " + sum / 5);
    }
}