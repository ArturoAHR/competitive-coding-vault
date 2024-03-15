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
  Frequency Counter

  Statement:
  You are given a list of integer numbers. Your task is to write a program
  that prints each distinct number followed by its frequency in the list. The
  output should be sorted by the numbers in ascending order.

  Sample Input:
  8
  4 3 1 2 4 3 2 4

  Expected Output:
  1 1
  2 2
  3 2
  4 3
*/

using namespace std;

int n;
vector<int> a;
map<int, int> m;

int main() {
  fast_io();

  cin >> n;

  a = vector<int>(n);

  for (int &v : a) {
    cin >> v;
  }

  for (int i = 0; i < n; i++) {
    m[a[i]]++;
  }

  for (auto v : m) {
    cout << v.first << ' ' << v.second << '\n';
  }
}