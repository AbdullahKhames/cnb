import LinkedList from './linkedlist.js';
import { Stack, StackArrayBased } from './stack.js';


const stack = new StackArrayBased();
console.log("isEmpty " + stack.isEmpty());


stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);

console.log("isEmpty " + stack.isEmpty());
console.log("size " + stack.size());

console.log("peek " + stack.peek());
console.log("pop " + stack.pop());
console.log("size " + stack.size());

stack.print();
