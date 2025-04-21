class LinkedListNode {
  constructor(value) {
    this.value = value;
    this.next = null;
    this.prev = null;
  }
}

class LinkedListIterator {
    constructor(head) {
        this.current = head;
    }
    hasNext() {
        return this.current !== null && this.current.next !== null;
    }
    data() {
        if (this.current) {
            return this.current.value;
        }
        return null; // or throw an error, depending on your use case
    }
    next() {
        if (this.current) {
            this.current = this.current.next;
        }
        return this;
    }
    currentNode() {
        return this.current;
    }
}

class LinkedList {
    constructor(uniqe = false) {
        this.uniqe = uniqe;
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    begin() {
        return new LinkedListIterator(this.head);
    }
    printList() {
        let result = '';
        let current;
        for (var it = this.begin(); it.currentNode(); it.next()) {
            current = it.currentNode();
            if (current) {
                result += current.value + ' -> ';
            }
        }

        result += 'null';
        console.log(result);
    }
    find(value) {
        let current;
        for (var it = this.begin(); it.currentNode(); it.next()) {
            current = it.currentNode();
            if (current.value === value) {
                return current; // Return the node if found
            }
        }
        return null; // or throw an error, depending on your use case
    }
    findParent(value) {
        let current;
        let parent = null;
        for (var it = this.begin(); it.currentNode(); it.next()) {
            current = it.currentNode();
            if (current.value === value) {
                return parent; // Return the parent node if found
            }
            parent = current; // Update parent to current node
        }
        return null; // or throw an error, depending on your use case
    }
    insertLast(value) {
        if (this.uniqe && this.isExist(value)) {
            console.log('Value already exists in the list');
            return;
        }
        const newNode = new LinkedListNode(value);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }
        this.size++;
    }
    inserFirst(value) {
        if (this.uniqe && this.isExist(value)) {
            console.log('Value already exists in the list');
            return;
        }
        const newNode = new LinkedListNode(value);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
        this.size++;
    }
    inserAfter(value, newValue) {
        if (this.uniqe && this.isExist(value)) {
            console.log('Value already exists in the list');
            return;
        }
        const newNode = new LinkedListNode(newValue);
        var targertNode = this.find(value);
        if (targertNode) {
            newNode.next = targertNode.next;
            newNode.prev = targertNode;
            targertNode.next = newNode;
            if (newNode.next) {
                newNode.next.prev = newNode;
            } else {
                this.tail = newNode; // Update tail if inserting at the end
            }
            this.size++;
        } else {
            console.log('Target node not found');
        }
    }
    insertBefore(value, newValue) {
        if (this.uniqe && this.isExist(value)) {
            console.log('Value already exists in the list');
            return;
        }
        const newNode = new LinkedListNode(newValue);
        var targertNode = this.find(value);
        if (targertNode) {
            newNode.next = targertNode;
            newNode.prev = targertNode.prev;
            targertNode.prev = newNode;
            if (newNode.prev) {
                newNode.prev.next = newNode;
            } else {
                this.head = newNode; // Update head if inserting at the beginning
            }
            this.size++;
        } else {
            console.log('Target node not found');
        }
    }
    deleteNode(value) {
        var targertNode = this.find(value);
        if (targertNode) {
            if (targertNode === this.head && targertNode === this.tail) {
                this.head = null;
                this.tail = null;
            }
            if (targertNode.prev) {
                targertNode.prev.next = targertNode.next;
            } else {
                this.head = targertNode.next; // Update head if deleting the first node
            }
            if (targertNode.next) {
                targertNode.next.prev = targertNode.prev;
            } else {
                this.tail = targertNode.prev; // Update tail if deleting the last node
            }
            this.size--;
        } else {
            console.log('Target node not found');
        }
    }
    deleteHead() {
        if (this.head) {
            const nodeToDelete = this.head;
            this.head = this.head.next;
            if (this.head) {
                this.head.prev = null;
            } else {
                this.tail = null; // List is now empty
            }
            this.size--;
            return nodeToDelete;
        } else {
            console.log('List is empty');
        }
    }
    isExist(value) {
        let current = this.find(value);
        return current != null; // Return false if not found
    }
}

export default LinkedList;
