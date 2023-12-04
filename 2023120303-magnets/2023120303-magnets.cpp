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
 * A. Magnets
 * https://codeforces.com/problemset/problem/344/A
 */

using namespace std;

int n, r = 1;
vector<string> a;

int main() {
  fast_io();

  cin >> n;

  a = vector<string>(n);

  for (string &v : a) {
    cin >> v;
  }

  for (int i = 1; i < n; i++) {
    if (a[i - 1] != a[i])
      r++;
  }

  cout << r << '\n';
}