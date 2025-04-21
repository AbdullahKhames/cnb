import LinkedList from './linkedlist.js';

class Stack {
    #list;
    constructor(unique) {
        this.#list = new LinkedList(unique ?? false);
    }

    push(value) {
        this.#list.inserFirst(value);
    }

    pop() {
        if (this.#list.size === 0) {
            return null;
        }
        const headNode = this.#list.deleteHead(); 
        return headNode?.value ?? null;
    }

    peek() {
        if (this.#list.size === 0) {
            return null;
        }
        return this.#list.head.value;
    }

    isEmpty() {
        return this.#list.size <= 0;
    }

    size() {
        return this.#list.size;
    }
    print() {
        this.#list.printList();
    }
}
export default Stack;
