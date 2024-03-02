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
 * D - Diversity of Scores
 * https://atcoder.jp/contests/abc343/tasks/abc343_d
 */

using namespace std;

int n, t;
vector<ll> s;
map<ll, int> m;

void printMap() {
  for (auto v : m) {
    cout << v.first << ' ' << v.second << '\n';
  }

  cout << '\n';
}

int main() {
  fast_io();

  cin >> n >> t;

  s = vector<ll>(n, 0);

  m[0] = sz(s);

  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;

    a--;

    m[s[a]]--;

    if (m[s[a]] == 0) {
      m.erase(s[a]);
    }

    s[a] += b;
    m[s[a]]++;

    cout << sz(m) << '\n';
  }
}