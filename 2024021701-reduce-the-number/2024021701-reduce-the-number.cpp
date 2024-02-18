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
 * Reduce the Number
 * https://codeforces.com/group/OPrRXQFy1X/contest/505321/problem/B
 */

using namespace std;

struct Digit {
  char digit;
  bool deleted;
};

int n, k, removals = 0;
string s;
vector<Digit> digits;

void removeDigit(int i) {
  digits[i].deleted = true;
  removals++;
}

void removeNumberPeak(int i, int j) {
  if (i < 0)
    return;
  if (removals == k)
    return;

  if (digits[i].deleted)
    return removeNumberPeak(i - 1, j);

  if (digits[i].digit > digits[j].digit) {
    removeDigit(i);

    return removeNumberPeak(i - 1, j);
  }
}

void removeFromBack(int i) {
  if (i < 0) {
    return;
  }
  if (removals == k) {
    return;
  }
  if (digits[i].deleted) {
    return removeFromBack(i - 1);
  }

  removeDigit(i);

  return removeFromBack(i - 1);
}

int main() {
  fast_io();

  cin >> n >> k;
  cin >> s;

  for (char c : s) {
    digits.push_back({c, false});
  }

  for (int i = 0; i < n; i++) {
    if (i != n - 1 && s[i] > s[i + 1]) {
      removeNumberPeak(i, i + 1);
    }
  }

  removeFromBack(n - 1);

  for (Digit d : digits) {
    if (d.deleted)
      continue;

    cout << d.digit;
  }

  cout << '\n';
}