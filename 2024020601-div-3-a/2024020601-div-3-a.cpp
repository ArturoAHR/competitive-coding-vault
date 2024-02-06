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
 * A. Make it White
 * https://codeforces.com/contest/1927/problem/A
 */

using namespace std;

int t, n;
string strip;

void solve() {
  cin >> n >> strip;

  int leftBlack = -1, rightBlack = -1;
  for (int i = 0; i < n; i++) {
    if (strip[i] == 'B' && leftBlack == -1)
      leftBlack = i;

    if (strip[n - 1 - i] == 'B' && rightBlack == -1)
      rightBlack = n - 1 - i;
  }

  cout << rightBlack - leftBlack + 1 << '\n';
}

int main() {
  fast_io();

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}