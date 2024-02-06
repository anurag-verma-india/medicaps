import java.util.ArrayList;
import java.util.ListIterator;

public class ArrayList_printing {
    public static void main(String[] args) {
        ArrayList<String> list1 = new ArrayList<>();

        list1.add("a");
        list1.add("a");
        list1.add("a");

        //
        System.out.println("Using for each loop");
        int list1Index = 0;
        for (String s : list1) {
            System.out.println("list1 " + list1Index + ": " + s);
            list1Index += 1;
        }
        System.out.println();

        //
        System.out.println("Using for loop");
        for (int i = 0; i < list1.size(); i++) {
            System.out.println("list1 index " + i + ": " + list1.get(i));
        }
        System.out.println();

        //
        System.out.println("Using Iterator");
        ListIterator<String> list1_iterator = list1.listIterator();
        while (list1_iterator.hasNext()) {
            System.out.println("list1 index " + list1_iterator.nextIndex() + " :" + list1_iterator.next());
        }
    }
}
