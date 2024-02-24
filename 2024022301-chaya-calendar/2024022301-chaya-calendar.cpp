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
 * B. Chaya Calendar
 * https://codeforces.com/contest/1932/problem/B
 */

using namespace std;

int t, n;
vector<int> a;

void solve() {
  cin >> n;

  a = vector<int>(n);

  for (int &v : a) {
    cin >> v;
  }

  int res = a[0];
  for (int i = 1; i < sz(a); i++) {
    int multiplier = (res / a[i]) + 1;
    res = a[i] * multiplier;
  }

  cout << res << '\n';
}

int main() {
  fast_io();

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}