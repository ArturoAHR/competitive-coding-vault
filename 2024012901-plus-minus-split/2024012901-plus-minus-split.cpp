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
 * B. Plus-Minus Split
 * https://codeforces.com/problemset/problem/1919/B
 */

using namespace std;

int t, n;
string s;

void solve() {
  cin >> n;
  cin >> s;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += s[i] == '+' ? 1 : -1;
  }

  cout << abs(sum) << '\n';
}

int main() {
  fast_io();

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}