interface someInterface {
    int add(int num1, int num2);
}
interface someOtherInterface {
    String add(String num1, String num2);
}


public class lambda_expression_2 {
    public static void main(String[] args) {
        someInterface num = (int num1, int num2) -> (num1 + num2);
        someOtherInterface str = (String str1, String str2) -> (str1 + str2);
        System.out.println("Addition of 1 and 2 is: " + num.add(1, 2));
        System.out.println("Concatenation of \"a\" and \"b\" is: " + str.add("a", "b"));
    }
}