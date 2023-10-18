import java.util.Scanner;

public class student_inheritance {
    public static void main(String[] args) {
  	    result s1= new result();
        s1.percentage();
        
        sports s2 = new sports();
        s2.percentage();
    }
}

class student {
    Scanner s = new Scanner(System.in);
    String name;
    String enrollment_num;
    student() {
        input();
    }
    void input() {
        System.out.print("Enter student's name: ");
        name = s.nextLine();
        System.out.print("Enter student's enrollment number: ");
        enrollment_num = s.nextLine();
    }
}

class result extends student{
    int[]marks = new int[5];
    int sum = 0;
    void percentage() {
        System.out.println("Final exam result of " + name + " is " + (sum)/5 + "%\n");
    }
    result() {
        super();
        input_subject_marks();
    }
    void input_subject_marks() {
        String[] subjects = {"Physics", "Chemistry", "Maths", "Hindi", "Physical Education"};
        for(int i=0; i<5; i++) {
            System.out.print("Enter marks of "+subjects[i]+ ": ");
            marks[i]= s.nextInt();
            sum+=marks[i];
        }
    }
}

class sports extends student {
    int[]score = new int[3];
    int sum = 0;
    void percentage() {
        System.out.println("Final sports result of " + name + " is " + (sum)/3 + "%\n");
    }
    sports() {
        super();
        input_sport_score();
    }
        void input_sport_score() {
            String[] games = {"Cricket", "Football", "Volleyball"};
            for(int i=0; i<3; i++) {
                System.out.print("Enter score of "+games[i]+ ": ");
                score[i]= s.nextInt();
                sum+=score[i];
            }
    }
}