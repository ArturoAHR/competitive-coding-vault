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
 * D. Find the Different Ones!
 * https://codeforces.com/contest/1927/problem/D
 */

using namespace std;

int t, n, q;
vector<int> a;
vector<int> differentElementRangeSum;

int binarySearch(int searchedElement, int l, int r) {
  int lo = l, hi = r, mid = (lo + hi) / 2, res = -1;
  while (lo <= hi) {
    mid = (lo + hi) / 2;

    if (differentElementRangeSum[mid] >= searchedElement) {
      res = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return res;
}

void query(int l, int r) {
  if (differentElementRangeSum[r] - differentElementRangeSum[l] == 0) {
    cout << "-1 -1" << '\n';
    return;
  }

  int i = l, j = binarySearch(differentElementRangeSum[l] + 1, l, r);

  cout << i + 1 << ' ' << j + 1 << '\n';
}

void solve() {

  cin >> n;

  a = vector<int>(n);
  differentElementRangeSum = vector<int>(n, 0);

  for (int &v : a) {
    cin >> v;
  }

  for (int i = 1; i < n; i++) {
    differentElementRangeSum[i] = differentElementRangeSum[i - 1];

    if (a[i] != a[i - 1])
      differentElementRangeSum[i]++;
  }

  cin >> q;

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    query(l - 1, r - 1);
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