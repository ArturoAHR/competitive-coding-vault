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
 * E. Klever Permutation
 * https://codeforces.com/contest/1927/problem/E
 */

using namespace std;

int t, n, k;
vector<int> p;

void solve() {
  cin >> n >> k;

  p = vector<int>(n);

  p[0] = n;
  p[1] = 1;

  for (int i = 2; i < k; i++) {
    int gap = ((n - (i - 2)) / k) + 1 * ((n - (i - 2)) % k != 0);

    if (i % 2 == 0) {
      p[i] = p[i - 2] - gap;
    } else {
      p[i] = p[i - 2] + gap;
    }
  }

  for (int i = k; i < n; i++) {
    int delta = i % 2 == 0 ? -1 : 1;
    p[i] = p[i - k] + delta;
  }

  for (int i = 0; i < n; i++) {
    if (i > 0)
      cout << ' ';
    cout << p[i];
  }
  cout << '\n';
}

int main() {
  fast_io();

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}