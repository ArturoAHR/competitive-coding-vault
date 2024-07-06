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
 * B - Intesection of Cuboids
 * https://atcoder.jp/contests/abc361/tasks/abc361_b
 */

using namespace std;

struct Point {
  int x, y, z;

  bool operator<(const Point &p) { return x < p.x && y < p.y && z < p.z; }
};

int a[6];
int b[6];

int main() {
  fast_io();

  for (int &v : a) {
    cin >> v;
  }

  for (int &v : b) {
    cin >> v;
  }

  Point pa = Point{a[0], a[1], a[2]}, pb = Point{a[3], a[4], a[5]},
        pc = Point{b[0], b[1], b[2]}, pd = Point{b[3], b[4], b[5]};

  if (pa < pd && pc < pb) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}