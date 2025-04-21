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

class StackArrayBased {
    #data;
    #top;
    constructor() {
        this.#data = [];
        this.#top = -1;
    }
    push(value) {
        this.#data.push(value);
        ++this.#top;
    }
    pop() {
        if (this.#top < 0) {
            return null;
        }
        const value = this.#data.splice(this.#top, 1)[0];
        --this.#top;
        return value;
    }
    peek() {
        if (this.#top < 0) {
            return null;
        }
        return this.#data[this.#top];
    }
    isEmpty() {
        return this.#top < 0;
    }
    print() {
        let res = '';
        for (let i = this.#top; i >= 0; --i) {
            res += this.#data[i] + ' -> ';
        }
        res += 'null';
        console.log(res);
    }
    size () {
        return this.#top + 1;
    }
}
export { Stack, StackArrayBased };
