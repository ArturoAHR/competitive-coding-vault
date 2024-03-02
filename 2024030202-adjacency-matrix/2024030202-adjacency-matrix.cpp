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
 * B - Adjacency Matrix
 * https://atcoder.jp/contests/abc343/tasks/abc343_b
 */

using namespace std;

int n;
vector<vector<int>> adj;

int main() {
  fast_io();

  cin >> n;

  adj = vector<vector<int>>(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v;
      cin >> v;

      if (v) {
        adj[i].push_back(j + 1);
      }
    }
  }

  for (int i = 0; i < sz(adj); i++) {
    for (int j = 0; j < sz(adj[i]); j++) {
      if (j > 0)
        cout << ' ';
      cout << adj[i][j];
    }
    cout << '\n';
  }
}