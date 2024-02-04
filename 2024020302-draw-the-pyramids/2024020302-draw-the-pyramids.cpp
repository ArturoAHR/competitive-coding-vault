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
 * B. Draw the Pyramids
 * https://codeforces.com/group/OPrRXQFy1X/contest/502743/problem/B
 */

using namespace std;

struct Position {
  int x, y;
};

enum Direction {
  DOWN_LEFT = 0,
  DOWN_RIGHT = 1,
};

int h, w, n;
vector<Position> peaks;
vector<vector<char>> canvas;
vector<int> highestCovered;

int dx[2] = {-1, 1};
int dy[2] = {1, 1};

void drawPyramidSide(int x, int y, int direction, char wallCharacter) {
  if (x < 0 || x >= w || y < 0 || y >= h)
    return;
  if (highestCovered[x] <= y)
    return;

  canvas[y][x] = wallCharacter;
  highestCovered[x] = y;

  return drawPyramidSide(x + dx[direction], y + dy[direction], direction,
                         wallCharacter);
}

int main() {
  fast_io();

  cin >> h >> w >> n;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    peaks.push_back({x, h - 1 - y});
  }

  canvas = vector<vector<char>>(h, vector<char>(w, '.'));
  highestCovered = vector<int>(w, w);

  for (int i = 0; i < n; i++) {
    int x = peaks[i].x, y = peaks[i].y;

    if (highestCovered[x] <= y)
      continue;

    canvas[y][x] = '^';

    highestCovered[x] = y;

    drawPyramidSide(x + dx[DOWN_LEFT], y + dy[DOWN_LEFT], DOWN_LEFT, '/');
    drawPyramidSide(x + dx[DOWN_RIGHT], y + dy[DOWN_RIGHT], DOWN_RIGHT, '\\');
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << canvas[i][j];
    }
    cout << '\n';
  }
}