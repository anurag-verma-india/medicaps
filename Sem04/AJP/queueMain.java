import java.util.PriorityQueue;
import java.util.Iterator;
import java.util.HashSet;
import java.util.Set;

public class queueMain {
    public static void main(String args[]) {
        // a. Add items in the Queue
        PriorityQueue<String> queue1 = new PriorityQueue<String>();
        System.out.println("Adding items in the queue");
        queue1.add("Tomato");
        queue1.add("Potato");
        queue1.add("Jackfruit");
        System.out.println("Printing the elements of queue1: ");
        Iterator<String> itr = queue1.iterator();
        while (itr.hasNext()) {
            System.out.println(itr.next());
        }
        System.out.print("\n");

        // b. Insert items of one set in to other Queue
        PriorityQueue<String> queue2 = new PriorityQueue<String>();
        Set<String> set = new HashSet<>();

        set.add("Apple");
        set.add("Banana");
        set.add("Kiwi");

        System.out.println("Inserting items of one set in to other queue");
        set.forEach((S) -> {
            queue2.add(S);
        });

        System.out.println("Printing the elements of queue2: ");
        Iterator<String> itr2 = queue2.iterator();
        while (itr2.hasNext()) {
            System.out.println(itr2.next());
        }
        System.out.print("\n");

        // c. Remove items from the Queue
        System.out.println("Current top item: " + queue2.element());
        System.out.println("Removing items from the queue");
        queue2.remove();
        System.out.println("Now the top item is: " + queue2.element() + "\n");

        // d. Search the specified item in the Queue
        System.out.println("queue2 contains \"Banana\": " + queue2.contains("Banana"));
    }
}