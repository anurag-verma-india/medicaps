import java.util.Scanner;

public class star_pattern {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter number of lines in star: ");
        int num_of_lines = s.nextInt();
        for (int i = 1; i <= num_of_lines; i++) {  
            for(int k = num_of_lines - i + 1; k>0; k-- ) {
                System.out.print(" ");
            }
            for(int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.print("\n");
        }
    }
}
