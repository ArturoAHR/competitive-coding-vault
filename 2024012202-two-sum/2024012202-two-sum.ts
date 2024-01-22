/*
 * Two Sum
 * https://leetcode.com/problems/two-sum/description/
*/

function twoSum(nums: number[], target: number): number[] {
  const sortedNums = nums.map((num, index) => ({ num, index })).sort((a, b) => a.num - b.num)

  let i = 0, j = sortedNums.length - 1;
  while (i < j) {
    const sum = sortedNums[i].num + sortedNums[j].num;
    if (sum === target) return [sortedNums[i].index, sortedNums[j].index];
    if (sum < target) i++;
    if (sum > target) j--;
  }

  return [-1, -1]
};