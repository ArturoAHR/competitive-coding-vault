#include <bits/stdc++.h>
#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define MOD 1000000007
typedef long long ll;
typedef double db;

/*
  Grouped Anagrams
  Statement:
  You are given a list of words. Your task is to group words that are anagrams
  of each other and output the groups in increasing order based on the first
  word in each group lexicographically.

  Sample Input:
  7
  listen
  silent
  enlist
  google
  banana
  anagram
  nagaram

  Expected Output:
  anagram nagaram
  banana
  google
  listen silent enlist
*/

using namespace std;

int n;
set<string> keys;
multimap<string, string> mm;

int main() {
  fast_io();

  cin >> n;

  for (int i = 0; i < n; i++) {
    string str;

    cin >> str;

    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());

    keys.insert(sortedStr);

    mm.insert({sortedStr, str});
  }

  for (auto keyIt = keys.begin(); keyIt != keys.end(); keyIt++) {
    auto range = mm.equal_range((*keyIt));

    bool firstElement = true;
    for (auto strIt = range.first; strIt != range.second; strIt++) {
      if (!firstElement)
        cout << ' ';
      cout << strIt->second;
      firstElement = false;
    }
    cout << '\n';
  }
}