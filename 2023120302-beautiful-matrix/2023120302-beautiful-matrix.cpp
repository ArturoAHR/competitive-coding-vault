#include <bits/stdc++.h>

/*
 * A. Beautiful Matrix
 * https://codeforces.com/problemset/problem/263/A
 */

using namespace std;

int main() {
  int m[5][5];

  for (int i = 0; i < 5; i++) {
    for (int &v : m[i]) {
      cin >> v;
    }
  }

  int r, c;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (m[i][j]) {
        r = i;
        c = j;
      }
    }
  }

  int rt = 2, ct = 2;

  cout << abs(rt - r) + abs(ct - c) << '\n';
}