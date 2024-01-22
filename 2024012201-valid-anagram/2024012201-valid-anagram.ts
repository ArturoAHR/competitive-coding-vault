/*
 * Valid Anagram
 * https://leetcode.com/problems/valid-anagram/description/
 */

const isAnagram = (s: string, t: string): boolean => {
  const hashMapS: { [key: string]: number } = {}
  const hashMapT: { [key: string]: number } = {}

  if (s.length !== t.length) return false;

  for (let i = 0; i < s.length; i++) {
    if (!hashMapS[s[i]]) hashMapS[s[i]] = 0;
    if (!hashMapT[t[i]]) hashMapT[t[i]] = 0;

    hashMapS[s[i]]++;
    hashMapT[t[i]]++;
  }

  const sCharacters = Object.keys(hashMapS).sort((a, b) => { return a.localeCompare(b) })
  const tCharacters = Object.keys(hashMapT).sort((a, b) => { return a.localeCompare(b) })

  for (let i = 0; i < Math.max(sCharacters.length, tCharacters.length); i++) {
    if (sCharacters[i] !== tCharacters[i] || hashMapS[sCharacters[i]] !== hashMapT[tCharacters[i]]) {
      return false;
    }
  }

  return true;
}