import java.util.ArrayList;

public class array_list_example {
    public static void main(String[] args) {
        ArrayList<String> list1 = new ArrayList<>();
        ArrayList<String> list2 = new ArrayList<>();
        
        list2.add("0");
        list1.add("1");
        list1.add("2");
        list1.addAll(0, list2);
        list1.addFirst("First string");
        list1.addLast("Last String");
        System.out.println(list1.contains("1"));

        ArrayList <String> list3 = (ArrayList<String>) list1.clone();

        list2.clear();
        System.out.print("list1: ");
        System.out.println(list1);
        
        System.out.print("list2: ");
        System.out.println(list2);
        
        System.out.print("list3: ");
        System.out.println(list3);
    }
}
