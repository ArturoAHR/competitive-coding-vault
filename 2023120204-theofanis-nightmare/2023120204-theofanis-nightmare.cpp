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
 * C. Theofanis' Nightmare
 * https://codeforces.com/problemset/problem/1903/C
 */

using namespace std;

int t, n;
vector<ll> a, suf;

void solve() {
  cin >> n;

  a = vector<ll>(n);
  suf = vector<ll>(n + 1, 0);

  for (ll &v : a) {
    cin >> v;
  }

  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }

  ll ans = suf[0];

  for (int i = 1; i < n; i++) {
    if (suf[i] > 0)
      ans += suf[i];
  }

  cout << ans << '\n';
}

int main() {
  fast_io();

  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}