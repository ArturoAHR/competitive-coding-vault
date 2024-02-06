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
 * B. Following the String
 * https://codeforces.com/contest/1927/problem/B
 */

using namespace std;

int t, n;
vector<int> a;
vector<int> letterCount;

char getNextLetter(int occurrences) {
  for (int i = 0; i < sz(letterCount); i++) {
    if (occurrences == letterCount[i]) {
      letterCount[i]++;
      return (char)('a' + i);
    }
  }
}

void solve() {
  cin >> n;

  a = vector<int>(n);
  letterCount = vector<int>(26, 0);

  for (int &v : a)
    cin >> v;

  string result = "";

  for (int i = 0; i < n; i++) {
    result += getNextLetter(a[i]);
  }

  cout << result << '\n';
}

int main() {
  fast_io();

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}