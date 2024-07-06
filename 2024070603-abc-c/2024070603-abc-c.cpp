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
 * C - Make Them Narrow
 * https://atcoder.jp/contests/abc361/tasks/abc361_c
 */

using namespace std;

int n, k;
vector<int> a;

int main() {
  fast_io();

  cin >> n >> k;

  a = vector<int>(n);

  for (int &v : a) {
    cin >> v;
  }

  sort(all(a));

  int ans = INT_MAX;
  for (int i = 0; i <= k; i++) {
    ans = min(ans, a[n - 1 - k + i] - a[i]);
  }

  cout << ans << '\n';
}