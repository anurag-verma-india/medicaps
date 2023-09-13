import java.util.Scanner;

public class matrix_addition {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a[][] = new int[2][2];
        int b[][] = new int[2][2];
        int sum[][] = new int[2][2];
        System.out.println("Enter the first matrix");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print("a[" + i + "][" + j + "] = ");
                a[i][j] = s.nextInt();
            }
        }
        System.out.println("\nEnter the second matrix");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print("b[" + i + "][" + j + "] = ");
                b[i][j] = s.nextInt();
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
        System.out.println("\nSum of the two matrices are: ");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print(sum[i][j] + " ");
            }
            System.out.println("");
        }
    }
}
