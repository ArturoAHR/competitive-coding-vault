/*
 * 128. Longest Consecutive Sequence
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
*/

const longestConsecutive = (nums: number[]): number => {
  const numsHashSet = new Set(nums);

  let mx = 0;
  for (const num of numsHashSet) {
    if (numsHashSet.has(num - 1)) continue;

    let consecutiveNumbers = 0;
    let currentConsecutiveNumber = num;

    while (numsHashSet.has(currentConsecutiveNumber)) {
      consecutiveNumbers++;
      currentConsecutiveNumber++;
    }

    if (consecutiveNumbers > mx) mx = consecutiveNumbers
  }

  return mx;
}

