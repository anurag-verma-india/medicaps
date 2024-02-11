import java.util.Set;
import java.util.HashSet;

public class sets_implementation {
    public static void main(String args[]) {
        Set<String> set1 = new HashSet<>();
        Set<String> set2 = new HashSet<>();

        //
        set1.add("Item1");
        set1.add("Item2");
        set1.add("Item3");
        System.out.println("set1: " + set1 + "\n");

        //
        set2.addAll(set1);
        System.out.println("set1: " + set1);
        System.out.println("set2: " + set2);
        System.out.println();

        //
        System.out.println("Removing Item3 from set1");
        set1.remove("Item3");
        System.out.println("set1: " + set1 + "\n");

        //
        System.out.println("set1 contains \"Item1\": " + set1.contains("Item1") + "\n");
    }
}
// System.out.println("Size of set1: "+set1.size()+"\n");