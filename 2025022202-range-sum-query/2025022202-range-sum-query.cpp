#include <bits/stdc++.h>
#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

/*
 * Y. Range sum query
 * https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Y
 */

using namespace std;

int n, q;
vector<int64_t> a, sum;

int main() {
  fast_io();

  cin >> n >> q;

  a = vector<int64_t>(n);
  sum = vector<int64_t>(n + 1, 0);

  for (int64_t &v : a) {
    cin >> v;
  }

  for (int i = 0; i < (int)a.size(); i++) {
    sum[i + 1] = a[i] + sum[i];
  }

  int l, r;
  for (int i = 0; i < q; i++) {
    cin >> l >> r;

    cout << sum[r] - sum[l - 1] << '\n';
  }
}