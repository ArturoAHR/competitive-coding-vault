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
 * A - Insert
 * https://atcoder.jp/contests/abc361/tasks/abc361_a
 */

using namespace std;

int n, k, x;
vector<int> a;

int main() {
  fast_io();

  cin >> n >> k >> x;

  a = vector<int>(n);

  for (int &v : a) {
    cin >> v;
  }

  a.insert(a.begin() + k, x);

  for (int i = 0; i < n + 1; i++) {
    if (i > 0)
      cout << ' ';
    cout << a[i];
  }
}