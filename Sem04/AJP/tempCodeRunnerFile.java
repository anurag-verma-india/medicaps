import java.util.HashMap;
import java.util.Map;

public class Map_Basic {
    public static void main(String[] args) {
        Map<String, Integer> map1 = new HashMap<>();

        // a
        System.out.println("Inserting values in map1:");
        map1.put("a", 1);
        map1.put("b", 2);
        map1.put("c", 3);
        for (Map.Entry<String, Integer> ent : map1.entrySet()) {
            System.out.println(ent.getKey() + ": " + ent.getValue());
        }
        System.out.print("\n");
        // System.out.println(ent.getValue());

        // b
        System.out.println("Removing \"c\" from map1: ");
        map1.remove("c");
        for (Map.Entry<String, Integer> ent : map1.entrySet()) {
            System.out.println(ent.getKey() + ": " + ent.getValue());
        }
        System.out.print("\n");

        // c
        System.out.println("Does map1 contain \"a\": " + map1.containsKey("a") + "\n");

        // d
        System.out.println("Value of \"a\" in map1: " + map1.get("a") + "\n");

        // e
        System.out.println("Inserting all values of map1 into map2: ");
        Map<String, Integer> map2 = new HashMap<>();
        map2.putAll(map1);
        for (Map.Entry<String, Integer> ent : map2.entrySet()) {
            System.out.println(ent.getKey() + ": " + ent.getValue());
        }
        System.out.print("\n");

        // f    
        System.out.println("Keys and Values of map1 and map2: ");
        System.out.println("map1: ");
        for (Map.Entry<String, Integer> ent : map1.entrySet()) {
            System.out.println(ent.getKey() + ": " + ent.getValue());
        }
        System.out.println("map2: ");
        for (Map.Entry<String, Integer> ent : map2.entrySet()) {
            System.out.println(ent.getKey() + ": " + ent.getValue());
        }
        System.out.print("\n");
    }
}
