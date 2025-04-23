import LinkedList from './linkedlist.js';
import { Stack, StackArrayBased } from './stack.js';
import Heap from './heap.js';
import PriorityQueue from './priorityQueue.js';
// const stack = new StackArrayBased();
// console.log("isEmpty " + stack.isEmpty());


// stack.push(1);
// stack.push(2);
// stack.push(3);
// stack.push(4);

// console.log("isEmpty " + stack.isEmpty());
// console.log("size " + stack.size());

// console.log("peek " + stack.peek());
// console.log("pop " + stack.pop());
// console.log("size " + stack.size());

// stack.print();

// const heap = new Heap();
// heap.insert(24);
// heap.insert(32);
// heap.insert(16);
// heap.insert(45);
// heap.insert(20);
// heap.insert(53);
// heap.insert(14);
// heap.insert(27);

// heap.print();
// heap.draw();

// console.log("pop " + heap.pop());
// heap.draw();


var queue = new PriorityQueue();
queue.enqueue(5, 24);
queue.enqueue(5, 32);
queue.enqueue(3, 16);
queue.enqueue(3, 45);
queue.enqueue(1, 20);
queue.enqueue(1, 53);
queue.enqueue(2, 14);
queue.enqueue(2, 27);

queue.print();
queue.draw();

while(queue.hasData()){
  var result = queue.dequeue();
  console.log(result[0] + "[" + result[1]+ "]");
}
