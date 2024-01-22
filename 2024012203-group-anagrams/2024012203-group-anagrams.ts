/*
 * Group Anagrams
 * https://leetcode.com/problems/group-anagrams/
*/

const getHashCode = (str: string) => {
  const hashMap: { [key: string]: number } = {};

  for (let i = 0; i < str.length; i++) {
    if (!hashMap[str[i]]) hashMap[str[i]] = 0;

    hashMap[str[i]]++;
  }

  const sortedEntries = Object.entries(hashMap).sort((a, b) => {
    return a[0].localeCompare(b[0]);
  })

  const hashCode = sortedEntries.reduce((hashCode, currentCharacterEntry) => {
    const [character, occurrences] = currentCharacterEntry;

    return `${hashCode}${character}${occurrences}`
  }, '')

  return hashCode
}

const groupAnagrams = (strs: string[]): string[][] => {
  const groupedAnagrams: string[][] = [];

  const hashCodeIndexes: { [key: string]: number } = {};

  for (let i = 0; i < strs.length; i++) {
    const hashCode = getHashCode(strs[i]);

    if (hashCodeIndexes[hashCode] === undefined) {
      hashCodeIndexes[hashCode] = groupedAnagrams.length;
      groupedAnagrams.push([])
    }

    groupedAnagrams[hashCodeIndexes[hashCode]].push(strs[i]);
  }

  return groupedAnagrams;
}