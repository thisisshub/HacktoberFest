/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.size = 0;
    this.queue = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) { 
    this.queue[this.size] = x;
    this.size++;
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    if (this.size==0) return null;
    let result = this.queue[this.size-1];
    this.queue[this.size-1] = null;
    this.size-=1;
    return result; 
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    if (this.size==0) return null;
    return this.queue[this.size-1];    
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.size == 0;    
};