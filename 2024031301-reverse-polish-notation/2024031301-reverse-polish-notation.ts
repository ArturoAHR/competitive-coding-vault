/*
 * 150. Evaluate Reverse Polish Notation
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/


const solveExpression = (operator: string, stack: number[]) => {
  const operand2 = +stack.pop()!, operand1 = +stack.pop()!;

  let result = 0;
  switch (operator) {
    case "+":
      result = operand1 + operand2;
      break;
    case "-":
      result = operand1 - operand2;
      break;
    case "*":
      result = operand1 * operand2;
      break;
    case "/":
      result = Math.trunc(operand1 / operand2);
      break;
  }

  stack.push(result);
}

const evalRPN = (tokens: string[]): number => {
  const stack: number[] = [];

  for (let i = 0; i < tokens.length; i++) {
    if (["+", "-", "*", "/"].includes(tokens[i])) {
      solveExpression(tokens[i], stack);
    } else {
      stack.push(+tokens[i]);
    }
  }

  return stack[0];
}