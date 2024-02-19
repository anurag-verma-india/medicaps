interface someInterface<T> {
    T add(T num1, T num2);
}

public class lambda_expression {
    public static void main(String[] args) {
        someInterface<Integer> num = (Integer num1, Integer num2) -> (num1 + num2);
        someInterface<String> str = (String str1, String str2) -> (str1 + str2);
        System.out.println("Addition of 1 and 2 is: " + num.add(1, 2));
        System.out.println("Concatenation of \"a\" and \"b\" is: " + str.add("a", "b"));
    }
}