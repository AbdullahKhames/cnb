import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MyHashMap {
    private class Entry{
        private int key;
        private int value;
        
        public Entry(int key, int value) {
            this.key = key;
            this.value = value;
        }
        public int getKey() {
            return key;
        }
        public void setKey(int key) {
            this.key = key;
        }
        public int getValue() {
            return value;
        }
        public void setValue(int value) {
            this.value = value;
        }

        
    }
    private List<List<Entry>> entries;
    private int currentSize;
    private int totalSize;
    Hashing<Integer> hasher = new Hashing<>();
    public MyHashMap() {
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
    public void put(int key, int value) {
        System.out.println("------------------------put method -------------------------------");
        int index = getKeyIndex(key);
        if (entries.get(index).isEmpty()) {
            System.out.println("empty bucket");
            currentSize++;
            entries.get(index).add(new Entry(key, value));
        } else {
            System.out.println("non empty bucket");
            List<Entry> bucket = entries.get(index);
            int idx = -1;
            for (int i = 0; i < bucket.size(); i++) {
                if (key == bucket.get(i).getKey()) {
                    idx = i;
                }
            }
            if (idx == -1) {
                bucket.add(new Entry(key, value));
            } else {
                bucket.get(idx).setValue(value);
            }
        }
    }
    
    public int get(int key) {
        System.out.println("------------------------get method -------------------------------");

        int index = getKeyIndex(key);
        if (entries.get(index).isEmpty()) {
            System.out.println("empty bucket");
            return -1;
        } else {
            System.out.println("non empty bucket");
            List<Entry> bucket = entries.get(index);
            for (Entry entry : bucket) {
                if (key == entry.getKey()) {
                    return entry.getValue();
                }
            }
            return -1;
        }
    }
    
    public void remove(int key) {
        System.out.println("------------------------remove method -------------------------------");

        int index = getKeyIndex(key);
        if (entries.get(index).isEmpty()) {
            System.out.println("empty bucket");
        } else {
            System.out.println("non empty bucket");
            List<Entry> bucket = entries.get(index);
            int idx = -1;
            for (int i = 0; i < bucket.size(); i++) {
                if (key == bucket.get(i).getKey()) {
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
}
