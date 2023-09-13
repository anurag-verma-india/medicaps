import java.util.Scanner;

public class matrix_multiplication {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int first_matrix[][] = new int[2][2];
        int second_matrix[][] = new int[2][2];
        int multiplied_matrix[][] = new int[2][2];
        System.out.println("Enter the first matrix");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print("a[" + i + "][" + j + "] = ");
                first_matrix[i][j] = s.nextInt();
            }
        }
        System.out.println("\nEnter the second matrix");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print("b[" + i + "][" + j + "] = ");
                second_matrix[i][j] = s.nextInt();
            }
        }
        System.out.println("\nMultiplication of the two matrices are: ");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    multiplied_matrix[i][k] = multiplied_matrix[i][k] + (first_matrix[i][j] * second_matrix[j][i]);
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print(multiplied_matrix[i][j] + " ");
            }
            System.out.println("");
        }
    }
}
