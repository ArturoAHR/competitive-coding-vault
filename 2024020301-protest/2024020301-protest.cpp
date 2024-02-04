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
 * A. Protest
 * https://codeforces.com/group/OPrRXQFy1X/contest/502743/problem/A
 */

using namespace std;

struct Color {
  ll id;
  int quantity;

  bool operator<(const Color &other) const { return quantity < other.quantity; }
};

int n, q, s;

void solveType1() {
  set<ll> colorSet;

  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    colorSet.insert(a);
  }

  cout << colorSet.size() << '\n';
}

void solveType2() {
  vector<Color> colors;

  cin >> s;

  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;

    if (i == 0 || colors[colors.size() - 1].id != a) {
      colors.push_back({a, 0});
    }

    colors[colors.size() - 1].quantity++;
  }

  sort(all(colors));

  int amountOfColors = colors.size();
  int result = 0;

  while (amountOfColors > s) {
    result += colors[colors.size() - amountOfColors].quantity;
    amountOfColors--;
  }

  cout << result << '\n';
}

int main() {
  fast_io();

  cin >> n >> q;

  if (q == 1)
    solveType1();
  else
    solveType2();
}