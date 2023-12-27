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
 * A. Candies
 * https://codeforces.com/problemset/problem/1343/A
 */

using namespace std;

vector<int> tabbedPowerOf2;
int t, n;

int pow(int a, int b) {
  if (b == 0)
    return 1;

  return pow(a, b - 1) * a;
}

void solve() {
  cin >> n;

  for (int i = 2; i < sz(tabbedPowerOf2); i++) {
    if (n % (tabbedPowerOf2[i] - 1) == 0) {
      cout << n / (tabbedPowerOf2[i] - 1) << '\n';
      return;
    }
  }
}

int main() {
  fast_io();

  tabbedPowerOf2 = vector<int>(31);

  for (int i = 0; i < sz(tabbedPowerOf2); i++) {
    tabbedPowerOf2[i] = pow(2, i);
  }

  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}