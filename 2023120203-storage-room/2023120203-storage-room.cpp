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
 * B. StORage room
 * https://codeforces.com/problemset/problem/1903/B
 */

using namespace std;

int t;

void solve() {
  int n;
  vector<vector<int>> a;
  vector<int> r;

  cin >> n;
  a = vector<vector<int>>(n, vector<int>(n));
  r = vector<int>(n, 0b111111111111111111111111111111);

  for (int i = 0; i < n; i++) {
    for (int &v : a[i]) {
      cin >> v;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;

      r[i] = r[i] & a[i][j];
    }
  }

  bool possible = true;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((r[i] | r[j]) != a[i][j] && i != j)
        possible = false;
    }
  }

  if (possible) {
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0)
        cout << " ";
      cout << r[i];
    }
    cout << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main() {
  fast_io();

  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}