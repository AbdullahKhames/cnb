import java.util.Arrays;

public class Heap<T> {
    private int totalSize;
    private int currentSize;
    // private List<T> entries;
    private T[] entries;
    @SuppressWarnings("unchecked")
    public Heap() {
        // this.entries = new ArrayList<T>(totalSize);
        totalSize = 10;
        currentSize = 0;
        entries = (T[])new Object[totalSize];
    }
    public void printHeapTree() {
        printHeapTree(0, 0);
    }

    // Recursive method to print the tree
    private void printHeapTree(int index, int depth) {
        if (index >= currentSize || entries[index] == null) return;

        // Right child first (so it appears on top in console)
        int rightIndex = 2 * index + 2;
        printHeapTree(rightIndex, depth + 1);

        // Print current node
        String indent = "    ".repeat(depth);
        System.out.println(indent + entries[index]);

        // Left child
        int leftIndex = 2 * index + 1;
        printHeapTree(leftIndex, depth + 1);
    }

    private int getLeftChildIndex(int index) {
        return 2 * index + 1;
    }
    private int getRightChildIndex(int index) {
        return 2 * index + 2;
    }
    private Integer getParentIndex(int index) {
        if (index == 0) {
            return null;
        }
        return (int) Math.floor((index - 1) / 2);
    }

    private boolean hasLeftChild(int index) {
        return getLeftChildIndex(index) < currentSize;
    }
    private boolean hasRightChild(int index) {
        return getRightChildIndex(index) < currentSize;
    }
    private boolean hasParent(int index) {
        Integer val = getParentIndex(index);
        return val != null && val >= 0;
    }

    private T getLeftChildValue(int index) {
        return this.entries[getLeftChildIndex(index)];
    }
    private T getRightChildValue(int index) {
        return this.entries[getRightChildIndex(index)];
    }
    private T getParentValue(int index) {
        Integer val = getParentIndex(index);
        return val != null ? this.entries[val] : null;
    }

    void swap(int firstIdx, int secondIdx) {
        T temp = this.entries[firstIdx];
        this.entries[firstIdx] = this.entries[secondIdx];
        this.entries[secondIdx] = temp;
    }


    void ensureCapacity() {
        if (currentSize == totalSize) {
            totalSize *= 2;
            this.entries = Arrays.copyOf(this.entries, totalSize);
        }
    }

    T peek() {
        if (currentSize == 0) {
            throw new IllegalArgumentException("no value found");
        }
        return this.entries[0];
    }
    T pool() {
        if (currentSize == 0) {
            throw new IllegalArgumentException("no value found");
        }
        T data = this.entries[0];
        this.entries[0] = this.entries[currentSize - 1];
        currentSize--;
        heapifyDown();
        return data;
    }
    void insert(T data) {
        ensureCapacity();
        this.entries[currentSize] = data;
        currentSize++;
        heapifyUp();
    }
    @SuppressWarnings("unchecked")
    void heapifyUp() {
        int index = currentSize - 1;
        Comparable parentNode = (Comparable) getParentValue(index);
        Comparable currentNode = (Comparable) this.entries[index];
        while (index >= 0 && hasParent(index) && currentNode.compareTo(parentNode) < 0) {
            Integer val = getParentIndex(index);
            if (val != null) {
                swap(val, index);
                index = val;
            } else {
                break;
            }
        }
    }

    @SuppressWarnings("unchecked")
    void heapifyDown() {
        int index = 0;
        int smallerChildIndex;
        Comparable rightNode;
        Comparable leftNode;
        while (hasLeftChild(index)) {
            smallerChildIndex = getLeftChildIndex(index);
            rightNode = (Comparable)getRightChildValue(index);
            leftNode = (Comparable)getLeftChildValue(index);
            if (hasRightChild(index) &&  rightNode.compareTo(leftNode) < 0) {
                smallerChildIndex = getRightChildIndex(index);
            }
            swap(index, smallerChildIndex);
            index = smallerChildIndex;
        }
    }

}
