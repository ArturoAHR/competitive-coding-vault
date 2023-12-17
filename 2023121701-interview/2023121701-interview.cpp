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
 * A. Interview
 * https://codeforces.com/problemset/problem/631/A
 */

using namespace std;

int n;
vector<int> a, b;

int main() {
  fast_io();

  cin >> n;
  a = vector<int>(n);
  b = vector<int>(n);

  for (int &v : a) {
    cin >> v;
  }

  for (int &v : b) {
    cin >> v;
  }

  int sum = 0, ra = 0, rb = 0;
  for (int i = 0; i < n; i++) {
    ra |= a[i];
    rb |= b[i];
  }

  sum = ra + rb;

  cout << sum << '\n';
}