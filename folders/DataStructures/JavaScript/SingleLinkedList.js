// Node Class
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

// LinkedList class
class LinkedList {
  constructor() {
    this.head = null;
  }

  isEmpty() {
    return this.head === null;
  }

  getLength() {
    let tempNode = this.head;
    let length = 0;
    while (tempNode !== null) {
      tempNode = tempNode.next;
      length += 1;
    }
    return length;
  }

  print() {
    if (this.isEmpty()) {
      return "Linked List is Empty.";
    }
    let tempNode = this.head;
    let str = "";
    const seperator = " -> ";
    while (tempNode !== null) {
      str += `${tempNode.data}${seperator}`;
      tempNode = tempNode.next;
    }
    str += "null";
    return str;
  }

  insertAtPosition(data, position) {
    if (position < 0) {
      throw Error("Invalid position.");
    }
    let tempNode = this.head;
    let previousNode = null;
    while (position !== 0 && tempNode !== null) {
      position -= 1;
      previousNode = tempNode;
      tempNode = tempNode.next;
    }
    if (position !== 0) { // if the position is not zero, after the loop ends, 
      // it means that the tempNode is null. 
      // So the given position is more than the length of the linked list.
      // So it is an Invalid position.
      throw Error("Invalid Position.");
    }
    let newNode = new Node(data);
    newNode.next = tempNode;
    if (previousNode !== null) {
      previousNode.next = newNode;
    } else {
      // if previousNode is null, then the code in loop didn't run
      // which means the position is 0 or the head is null. So we update the head.
      this.head = newNode;
    }
  }

  insertAtBegining(data) {
    let tempNode = new Node(data);
    tempNode.next = this.head;
    this.head = tempNode;
  }

  insertAtLast(data) {
    if (this.isEmpty()) {
      this.insertAtBegining(data);

    } else {
      let tempNode = new Node(data);
      let traverseNode = this.head;
      while (traverseNode.next !== null) {
        traverseNode = traverseNode.next;
      }
      traverseNode.next = tempNode;
    }
  }

  deleteAtPosition(position) {
    if (this.isEmpty()) {
      throw Error("Empty Linked List.");
    }
    if (position < 0) {
      throw Error("Invalid Position.");
    }
    let traverseNode = this.head;
    let previousNode = null;
    while (position !== 0 && traverseNode.next !== null) {
      position -= 1;
      previousNode = traverseNode;
      traverseNode = traverseNode.next;
    }
    if (position !== 0) {
      throw Error("Invalid Position.")
    }
    if (previousNode === null) {
      // if previousNode is null, then the code in loop didn't run
      // which means the position is 0. So we update the head.
      this.head = this.head.next;
    } else {
      previousNode.next = traverseNode.next;
    }
    traverseNode.next = null;
    return traverseNode;
  }

  deleteAtBegining() {
    if (this.isEmpty()) {
      throw Error("Empty Linked List.");
    }
    let tempNode = this.head;
    this.head = this.head.next;
    tempNode.next = null;
    return tempNode;
  }

  deleteAtEnd() {
    if (this.isEmpty()) {
      throw Error("Empty Linked List.");
    }
    let traverseNode = this.head;
    let previousNode = null;
    while (traverseNode.next !== null) {
      previousNode = traverseNode;
      traverseNode = traverseNode.next;
    }
    if (previousNode !== null) {
      previousNode.next = null;
    }
    if (this.head === traverseNode) {
      this.head = null;
    }
    traverseNode.next = null;
    return traverseNode;
  }
}


// Usage
ll = new LinkedList();
ll.insertAtPosition(1, 0); // 1 -> null
ll.insertAtLast(2); // 1 -> 2 -> null
ll.insertAtBegining(0); // 0 -> 1 -> 2 -> null
console.log(`${ll.print()}`); // prints "0 -> 1 -> 2 -> null"
ll.deleteAtPosition(0);
console.log(`${ll.print()}`); // 1 -> 2 -> null

ll.insertAtLast(3); // 1 -> 2 -> 3-> null
ll.insertAtPosition(4, ll.getLength()); // 1 -> 2 -> 3 -> 4 -> null

console.log(`${ll.print()}`); // prints "1 -> 2 -> 3 -> 4 -> null"
console.log(`Length = ${ll.getLength()}`); // prints "Length = 4"

ll.deleteAtPosition(ll.getLength() - 1); // 1 -> 2 -> 3 -> null
console.log(`${ll.print()}`); // prints "1 -> 2 -> 3 -> null"

ll.deleteAtBegining(); // 2 -> 3 -> null
console.log(`${ll.print()}`); // prints "2 -> 3 -> null"

ll.deleteAtEnd(); // 2 -> null
console.log(`${ll.print()}`); // prints "2 -> null"