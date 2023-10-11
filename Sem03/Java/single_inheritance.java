import java.util.Scanner;

abstract class vehicle {
    String colour;
    int number_of_wheels;
};

class car extends vehicle {
    public int number_of_brakes = 1;
};

class single_inheritance {
    public static void main(String[] args) {
        car c1 = new car();
        System.out.println("Number of wheels: " + c1.number_of_wheels);
    }
}
