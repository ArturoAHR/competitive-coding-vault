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
 * B. Power Sequence
 * https://codeforces.com/contest/1397/problem/B
 */

using namespace std;

int n;
vector<ll> a;

int main() {
  fast_io();

  cin >> n;

  a = vector<ll>(n);

  for (ll &v : a)
    cin >> v;

  sort(all(a));

  ll f1sum = 0;
  for (int i = 0; i < sz(a); i++) {
    f1sum += a[i] - 1;
  }

  ll min = 1e18;
  for (ll i = 1; i; i++) {
    ll p = 1, sum = 0, valid = true;
    for (int j = 0; j < sz(a); j++, p *= i) {
      if (p > (a[n - 1] + f1sum)) {
        valid = false;
        break;
      }

      sum += abs(a[j] - p);
    }

    if (!valid)
      break;

    if (sum < min)
      min = sum;
  }

  cout << min << '\n';
}