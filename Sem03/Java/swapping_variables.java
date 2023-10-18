import java.util.Scanner;

public class swapping_variables {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int var1 = 0;
        int var2 = 0;

        System.out.print("Enter first number: ");
        var1 = s.nextInt();
        System.out.print("Enter second number: ");
        var2 = s.nextInt();

        System.out.println("Before swap \n var1: " + var1+"\n var2: "+var2+"\n");

        var1 = var1 + var2;
        var2 = var1 - var2;
        var1 = var1 - var2;

        System.out.println("Aftere swap \n var1: " + var1+"\n var2: "+var2+"\n");
    }
}
