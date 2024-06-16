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
 * A. green_gold_dog, array and permutation
 * https://codeforces.com/contest/1867/problem/A
 */

using namespace std;

struct Element {
  int value, position;

  bool operator<(const Element &e) { return value > e.value; }
};

int t, n;
vector<int> b;
vector<Element> a;

void solve() {
  cin >> n;

  a = vector<Element>(n);
  b = vector<int>(n);

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a[i] = {v, i};
  }

  sort(all(a));

  for (int i = 0; i < n; i++) {
    b[a[i].position] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    if (i > 0)
      cout << ' ';
    cout << b[i];
  }
  cout << '\n';
}

int main() {
  fast_io();

  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}