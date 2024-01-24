/*
 * Product of Array Except Self
 * https://leetcode.com/problems/product-of-array-except-self/description/
*/

const productExceptSelf = (nums: number[]): number[] => {
  let amountOfZeroes = 0;
  let product = 1;
  let productWithoutZeros = 1;

  for (const num of nums) {
    if (num !== 0) {
      productWithoutZeros *= num;
    }
    else {
      amountOfZeroes++;
    }

    product *= num;
  }

  const result = [];

  for (const num of nums) {
    let resultNum = 0;
    if (num !== 0) resultNum = product / num
    if (num === 0 && amountOfZeroes === 1) {
      resultNum = productWithoutZeros;
    }

    result.push(resultNum);
  }

  return result;
};