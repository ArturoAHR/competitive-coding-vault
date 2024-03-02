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
 * A - Wrong Answer
 * https://atcoder.jp/contests/abc343/tasks/abc343_a
 */

using namespace std;

int a, b;

int main() {
  fast_io();

  cin >> a >> b;

  cout << (a + b + 1) % 10 << '\n';
}