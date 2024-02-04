import java.util.ArrayList;

public class array_list_example {
    public static void main(String[] args) {
        ArrayList<String> list1 = new ArrayList<>();
        
        //
        System.out.println(".add() method");
        list1.add("1");
        list1.add("2");
        System.out.println("list1: "+list1+"\n");
        
        System.out.println("Creating list2 and adding \"0\" to it");
        ArrayList<String> list2 = new ArrayList<>();
        list2.add("0");
        System.out.println("list2: "+list2);
        //
        System.out.println("adding whole list2 to list1 at 0 index");
        list1.addAll(0, list2);
        System.out.println("list1: "+list1+"\n");
        
        //
        System.out.println("Adding to the start of list1");
        list1.addFirst("First string");
        System.out.println("list1: "+list1+"\n");
        
        
        //
        System.out.println("Adding to the end of list1");
        list1.addLast("Last String");
        System.out.println("list1: "+list1+"\n");
        
        //
        System.out.print("Does list1 contain 1: ");
        System.out.println(list1.contains("1")+"\n");
        
        //
        System.out.println("Cloning list1 in list3");
        ArrayList <String> list3 = (ArrayList<String>) list1.clone();
        System.out.println("list3: "+list3+"\n");
        
        //
        System.out.println("Clearing list2");
        list2.clear();
        System.out.println("list2: "+list2+"\n");
        
        //
        System.out.print("list1 contains 1: ");
        System.out.println(list1.contains("1")+"\n");
        
        //
        System.out.print("list1 contains whole list3: ");
        System.out.println(list1.containsAll(list3)+"\n");
        
        //
        System.out.print("Does list1 equal list3: ");
        System.out.println(list1.equals(list3)+"\n");

        //
        System.out.println("Value at index 2 in list1: "+list1.get(2)+"\n");
    }
}
