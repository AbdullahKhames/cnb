import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MyHashSet {
    private List<List<Integer>> entries;
    private int currentSize;
    private int totalSize;
    Hashing<Integer> hasher = new Hashing<>();

    public MyHashSet() {
        totalSize = 100;
        currentSize = 0;
        entries = new ArrayList<>(totalSize);
        for (int i = 0; i < totalSize; i++) {
            entries.add(new LinkedList<>());
        }
    }
    
    private int getKeyIndex(int key) {
        int hashVal = hasher.hashKey(key);
        return hashVal % totalSize;
    }
    public void add(int key) {
        System.out.println("------------------------add method -------------------------------");
        int index = getKeyIndex(key);
        if (entries.get(index).isEmpty()) {
            System.out.println("empty bucket");
            currentSize++;
            entries.get(index).add(key);
        } else {
            System.out.println("non empty bucket");
            List<Integer> bucket = entries.get(index);
            int idx = -1;
            for (int i = 0; i < bucket.size(); i++) {
                if (key == bucket.get(i)) {
                    idx = i;
                }
            }
            if (idx == -1) {
                bucket.add(key);
            }
        }
    }
    
    public void remove(int key) {
        System.out.println("------------------------remove method -------------------------------");

        int index = getKeyIndex(key);
        if (entries.get(index).isEmpty()) {
            System.out.println("empty bucket");
        } else {
            System.out.println("non empty bucket");
            List<Integer> bucket = entries.get(index);
            int idx = -1;
            for (int i = 0; i < bucket.size(); i++) {
                if (key == bucket.get(i)) {
                    idx = i;
                }
            }
            if (idx != -1) {
                bucket.remove(idx);
                if (bucket.isEmpty()) {
                    currentSize--;
                }
            }
        }
    }
    
    public boolean contains(int key) {
        System.out.println("------------------------contains method -------------------------------");

        int index = getKeyIndex(key);
        if (entries.get(index).isEmpty()) {
            System.out.println("empty bucket");
            return false;
        } else {
            System.out.println("non empty bucket");
            List<Integer> bucket = entries.get(index);
            for (Integer integer : bucket) {
                if (key == integer) {
                    return true;
                }
            }
            return false;
        }
    }

}
