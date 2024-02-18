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
 * Urns and Disks
 * https://codeforces.com/group/OPrRXQFy1X/contest/505321/problem/D
 */

using namespace std;

int n, m, q;

vector<ll> urns;

void splitDisk(int i, int v) {
  if (v == 1) {
    urns[i] += 1;
    return;
  }

  splitDisk(i != 0 ? i - 1 : i + 1, v - 1);
  splitDisk(i != n - 1 ? i + 1 : i - 1, v - 1);
}

int main() {
  fast_io();

  cin >> n >> m;

  urns = vector<ll>(n, 0);

  for (int i = 0; i < m; i++) {
    int x, c;
    cin >> x >> c;
    splitDisk(x - 1, c);
  }

  cin >> q;

  for (int i = 0; i < q; i++) {
    if (i > 0)
      cout << ' ';
    int t;
    cin >> t;
    cout << urns[t - 1] % 100;
  }
  cout << '\n';
}