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
 * A. Anton and Danik
 * https://codeforces.com/problemset/problem/734/A
 */

using namespace std;

int n, anton = 0, danik = 0;
string games;

int main() {
  fast_io();

  cin >> n;
  cin >> games;

  for (char c : games) {
    if (c == 'A')
      anton++;
    if (c == 'D')
      danik++;
  }

  if (anton > danik)
    cout << "Anton" << '\n';
  if (anton < danik)
    cout << "Danik" << '\n';
  if (anton == danik)
    cout << "Friendship" << '\n';
}