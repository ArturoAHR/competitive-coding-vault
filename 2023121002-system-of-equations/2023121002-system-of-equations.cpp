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
 * A. System of Equations
 * https://codeforces.com/problemset/problem/214/A
 */

using namespace std;

int n, m;

int main() {
  fast_io();
  cin >> n >> m;

  int count = 0;
  for (int a = 0; a < 1001; a++) {
    for (int b = 0; b < 1001; b++) {
      if (a * a + b == n && a + b * b == m)
        count++;
    }
  }

  cout << count << '\n';
}