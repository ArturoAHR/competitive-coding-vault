/*
 * String Encode and Decode
 * https://neetcode.io/problems/string-encode-and-decode
*/

class Solution {
  encode(strs: string[]) {
    if (strs.length === 0) return undefined;

    return strs.join('Ā');
  }

  decode(str: string | undefined) {
    if (str === undefined) return [];

    return str.split('Ā');
  }
}
