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
 * C - 343
 * https://atcoder.jp/contests/abc343/tasks/abc343_c
 */

using namespace std;

ll n;

bool isPalindrome(ll v) {
  string s = to_string(v);

  for (int i = 0; i <= sz(s) / 2; i++) {
    if (s[i] != s[sz(s) - i - 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  fast_io();

  cin >> n;

  ll sqrt3 = -1;

  for (ll i = 0; i < 1000000; i++) {
    ll v = i * i * i;
    if (v > n)
      break;
    sqrt3 = i;
  }

  for (ll i = sqrt3; i >= 0; i--) {
    ll v = i * i * i;

    if (v > n || !isPalindrome(v))
      continue;

    cout << v << '\n';

    break;
  }
}