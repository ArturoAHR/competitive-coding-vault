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
 * C - Many Replacement
 * https://atcoder.jp/contests/abc342/tasks/abc342_c
 */

using namespace std;

int n, q;
char c, d;
string s;
vector<char> z;

int main() {
  fast_io();

  cin >> n >> s >> q;

  z = vector<char>(26);

  for (int i = 0; i < sz(z); i++) {
    z[i] = 'a' + i;
  }

  for (int i = 0; i < q; i++) {
    cin >> c >> d;

    for (int j = 0; j < sz(z); j++) {
      if (z[j] == c)
        z[j] = d;
    }
  }

  for (int i = 0; i < sz(s); i++) {
    cout << z[s[i] - 'a'];
  }

  cout << '\n';
}