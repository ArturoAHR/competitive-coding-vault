/*
 * Top K Frequent Elements
 * https://leetcode.com/problems/top-k-frequent-elements/description/
*/

const topKFrequent = (nums: number[], k: number): number[] => {
  const frequencies = new Map<number, number>()

  for (const num of nums) {
    if (!frequencies.has(num)) {
      frequencies.set(num, 0);
    }

    frequencies.set(num, frequencies.get(num)! + 1);
  }

  const sortedEntries = Array.from(frequencies.entries()).sort(([_aKey, aValue], [_bKey, bValue]) => {
    return bValue - aValue;
  })

  return sortedEntries.splice(0, k).map(([key, _value]) => key)
}