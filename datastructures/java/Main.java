public class Main{
    public static void main(String[] args) {
        MyHashSet obj = new MyHashSet();
        obj.add(1);
        obj.add(2);
        boolean param_3 = obj.contains(1);
        System.out.println(param_3);
        param_3 = obj.contains(3);
        System.out.println(param_3);
        obj.add(2);
        param_3 = obj.contains(2);
        System.out.println(param_3);
        obj.remove(2);
        param_3 = obj.contains(2);
        System.out.println(param_3);

        System.out.println("------------------------------------------------");
        System.out.println("------------------------------------------------");
        System.out.println("------------------------------------------------");
        MyHashMap myHashMap = new MyHashMap();
        myHashMap.put(1, 1); // The map is now [[1,1]]
        myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
        System.out.println(myHashMap.get(1));    // return 1, The map is now [[1,1], [2,2]]
        System.out.println(myHashMap.get(3));    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
        myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
        System.out.println(myHashMap.get(2));    // return 1, The map is now [[1,1], [2,1]]
        myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
        System.out.println(myHashMap.get(2));    // return -1 (i.e., not found), The map is now [[1,1]]

    }
}
