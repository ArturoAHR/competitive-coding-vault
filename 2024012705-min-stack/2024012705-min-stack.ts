/*
 * 155. Min Stack
 * https://leetcode.com/problems/min-stack/description/
*/

class MinStack {
  stack: number[];
  minStack: number[];

  constructor() {
    this.stack = []
    this.minStack = [];
  }

  push(val: number): void {
    this.stack.push(val);

    const minStackTopValue = this.minStack[this.minStack.length - 1] ?? 2 ** 31 - 1;

    if (minStackTopValue > val) {
      this.minStack.push(val)
    }
    else {
      this.minStack.push(minStackTopValue)
    }
  }

  pop(): void {
    this.stack.pop();
    this.minStack.pop();
  }

  top(): number {
    return this.stack[this.stack.length - 1];
  }

  getMin(): number {
    return this.minStack[this.minStack.length - 1];
  }
}