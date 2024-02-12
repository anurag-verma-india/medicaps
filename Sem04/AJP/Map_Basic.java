import java.util.HashMap;
import java.util.Map;

public class Map_Basic {
    public static void main(String[] args) {
        Map<String, Integer> map1 = new HashMap<>();

        // a
        map1.put("a", 1);
        map1.put("b", 2);
        map1.put("c", 3);

        for(Map.Entry<String, Integer> ent: map1.entrySet()) {
            System.out.print(""+ent.getKey()+": ");
            System.out.println(ent.getValue());
        }
        System.out.println("");
        
        // b
        map1.remove("a");
        for(Map.Entry<String, Integer> ent: map1.entrySet()) {
            System.out.print(""+ent.getKey()+": ");
            System.out.println(ent.getValue());
        }
        System.out.println("");

        // c
        System.out.println(map1.containsKey("a"));
    }
}
