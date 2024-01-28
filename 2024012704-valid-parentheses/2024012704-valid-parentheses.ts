/*
 * 20. Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses/description/
*/

const isValid = (s: string): boolean => {
  const bracketStack = [];

  const openingBracketByClosingBracket = {
    ")": "(",
    "]": "[",
    "}": "{",
  }

  for (const bracket of s) {
    if (["(", "[", "{"].includes(bracket)) {
      bracketStack.push(bracket);
      continue;
    }

    if (bracketStack[bracketStack.length - 1] !== openingBracketByClosingBracket[bracket as keyof typeof openingBracketByClosingBracket])
      return false;

    bracketStack.pop()
  }

  if (bracketStack.length !== 0)
    return false;

  return true;
}
