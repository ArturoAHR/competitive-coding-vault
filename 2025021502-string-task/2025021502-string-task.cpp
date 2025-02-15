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
 * A. String Task
 * https://codeforces.com/problemset/problem/118/A
 */

using namespace std;

string str, res = "";
vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

bool is_vowel(char c) {
  for (char vowel : vowels) {
    if (vowel == tolower(c))
      return true;
  }
  return false;
}

int main() {
  fast_io();

  cin >> str;

  for (char c : str) {

    char letter = c;

    if (is_vowel(c)) {
      continue;
    }

    if (letter < 'a') {
      letter = tolower(letter);
    }

    res += '.';
    res += letter;
  }

  cout << res << '\n';
}