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
 * C. Choose the Different Ones!
 * https://codeforces.com/contest/1927/problem/C
 */

using namespace std;

int t, n, m, k;
vector<int> a, b;

string solve() {
  int amountA = 0, amountB = 0;
  set<int> setA, setB;

  cin >> n >> m >> k;

  a = vector<int>(n);
  b = vector<int>(m);

  for (int &v : a) {
    cin >> v;
  }

  for (int &v : b) {
    cin >> v;
  }

  for (int i = 0; i < n; i++)
    setA.insert(a[i]);
  for (int i = 0; i < m; i++)
    setB.insert(b[i]);

  for (int i = 0; i < k; i++) {
    int currentNumber = i + 1;
    bool numberWasFound = false;

    if (setA.count(currentNumber)) {
      amountA++;
      numberWasFound = true;
    }

    if (setB.count(currentNumber)) {
      amountB++;
      numberWasFound = true;
    }

    if (!numberWasFound) {
      return "NO";
    }
  }

  if (amountA < k / 2 || amountB < k / 2) {
    return "NO";
  }

  return "YES";
}

int main() {
  fast_io();

  cin >> t;

  for (int i = 0; i < t; i++) {
    cout << solve() << '\n';
  }
}