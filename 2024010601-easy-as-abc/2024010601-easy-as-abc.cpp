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
 * A. Easy As ABC
 * https://codeforces.com/problemset/problem/1906/A
 */

using namespace std;

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

vector<vector<int>> visited = vector<vector<int>>(3, vector<int>(3, 0));
vector<string> combinations;
string m[3];
char comb[3];

void calculateComb(int x, int y, int pos = 0) {
  if (visited[x][y])
    return;

  comb[pos] = m[x][y];

  if (pos == 2) {
    string result = "";
    for (int i = 0; i < 3; i++)
      result += comb[i];
    combinations.push_back(result);
    return;
  }

  for (int i = 0; i < 8; i++) {
    int nextX = x + dx[i], nextY = y + dy[i];

    if (0 <= nextX && nextX < 3 && 0 <= nextY && nextY < 3) {

      visited[x][y] = 1;
      calculateComb(nextX, nextY, pos + 1);
      visited[x][y] = 0;
    }
  }
}

int main() {
  fast_io();

  for (int i = 0; i < 3; i++) {
    cin >> m[i];
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      calculateComb(i, j);
    }
  }

  string mn = "DDD";
  for (int i = 0; i < sz(combinations); i++) {
    if (mn > combinations[i])
      mn = combinations[i];
  }

  cout << mn << '\n';
}