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
 * A. Bear and Big Brother
 * https://codeforces.com/problemset/problem/791/A
 */

using namespace std;

int a, b, years = 0; // 1 <= a <= b <= 10;

int main() {
  fast_io();

  cin >> a >> b;

  while (a <= b) {
    a *= 3;
    b *= 2;
    years++;
  }

  cout << years << '\n';
}