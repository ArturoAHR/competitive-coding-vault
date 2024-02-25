#include <bits/stdc++.h>
#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define sz(x) (ll) x.size()
#define all(x) begin(x), end(x)
#define MOD 1000000007
typedef long long ll;
typedef double db;

/*
 * Fibonacci Divisors
 * https://codeforces.com/group/OPrRXQFy1X/contest/505321/problem/A
 */

using namespace std;

ll t, k, x, l, r;
vector<ll> memo(93, -1);

ll f(ll i) {
  if (memo[i] != -1)
    return memo[i];

  ll fv = f(i - 1) + f(i - 2);
  memo[i] = fv;

  return fv;
}

void solve() {
  cin >> k >> x >> l >> r;

  ll divisibleFibonacciIndex = 0;
  for (ll i = 1; i < sz(memo); i++) {
    if (memo[i] % k == 0) {
      divisibleFibonacciIndex = i;
      break;
    }
  }

  ll count = (r / divisibleFibonacciIndex) - (l / divisibleFibonacciIndex) +
             (l % divisibleFibonacciIndex == 0);

  cout << count << '\n';
}

int main() {
  fast_io();

  memo[0] = 0;
  memo[1] = 1;
  f(sz(memo) - 1);

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}