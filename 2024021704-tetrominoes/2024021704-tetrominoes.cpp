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
 * Tetrominoes
 * https://codeforces.com/group/OPrRXQFy1X/contest/505321/problem/C
 */

using namespace std;

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

const char VISITED = 'V';
const char INVALID = 'I';
const char BLOCK = '#';
const char SPACE = '.';

char tetrominoTypes[7] = {'O', 'I', 'T', 'S', 'Z', 'L', 'J'};

vector<vector<string>> oRotations = {
    {"##", "##"},
    {"##", "##"},
    {"##", "##"},
    {"##", "##"},
};

vector<vector<string>> iRotations = {
    {
        "#",
        "#",
        "#",
        "#",
    },
    {"####"},
    {
        "#",
        "#",
        "#",
        "#",
    },
    {"####"},
};

vector<vector<string>> tRotations = {
    {".#.", "###"},
    {".#", "##", ".#"},
    {"###", ".#."},
    {"#.", "##", "#."},
};

vector<vector<string>> sRotations = {
    {".##", "##."},
    {"#.", "##", ".#"},
    {".##", "##."},
    {"#.", "##", ".#"},
};

vector<vector<string>> zRotations = {
    {"##.", ".##"},
    {".#", "##", "#."},
    {"##.", ".##"},
    {".#", "##", "#."},
};

vector<vector<string>> lRotations = {{
                                         "#.",
                                         "#.",
                                         "##",
                                     },
                                     {"###", "#.."},
                                     {
                                         "##",
                                         ".#",
                                         ".#",
                                     },
                                     {"..#", "###"}};

vector<vector<string>> jRotations = {{
                                         ".#",
                                         ".#",
                                         "##",
                                     },
                                     {"###", "..#"},
                                     {
                                         "##",
                                         "#.",
                                         "#.",
                                     },
                                     {"#..", "###"}};

vector<vector<vector<string>>> tetrominoSchematics = {
    oRotations, iRotations, tRotations, sRotations,
    zRotations, lRotations, jRotations};

int t, r, c;
vector<vector<char>> image;

void printImage() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << image[i][j];
    }
    cout << '\n';
  }
}

bool isOutOfBounds(int x, int y) { return x < 0 || r <= x || y < 0 || c <= y; }

bool isSurroundedByBlocks(int x, int y) {
  for (int i = 0; i < 8; i++) {
    int nextX = x + dx[i], nextY = y + dy[i];
    if (isOutOfBounds(nextX, nextY))
      continue;

    if (image[nextX][nextY] == BLOCK)
      return true;
  }
  return false;
}

void invalidateShape(int x, int y) {
  if (isOutOfBounds(x, y))
    return;
  if (image[x][y] != BLOCK && image[x][y] != VISITED)
    return;

  image[x][y] = INVALID;

  for (int i = 0; i < 8; i++) {
    invalidateShape(x + dx[i], y + dy[i]);
  }
}

void revertVisitedBlocks(int x, int y, int rotation) {
  vector<string> tetrominoSchematic = tetrominoSchematics[t][rotation];

  int offset = 0;
  for (int i = 0; i < sz(tetrominoSchematic); i++) {
    if (tetrominoSchematic[0][i] == BLOCK)
      break;
    offset++;
  }

  y -= offset;

  for (int i = x; i < x + sz(tetrominoSchematic); i++) {
    for (int j = y; j < y + sz(tetrominoSchematic[i - x]); j++) {
      if (isOutOfBounds(i, j))
        continue;

      if (image[i][j] == VISITED)
        image[i][j] = BLOCK;
    }
  }
}

bool matchShape(int x, int y, int rotation) {
  vector<string> tetrominoSchematic = tetrominoSchematics[t][rotation];

  int offset = 0;
  for (int i = 0; i < sz(tetrominoSchematic); i++) {
    if (tetrominoSchematic[0][i] == BLOCK)
      break;
    offset++;
  }

  y -= offset;

  for (int i = x; i < x + sz(tetrominoSchematic); i++) {
    for (int j = y; j < y + sz(tetrominoSchematic[i - x]); j++) {
      if (isOutOfBounds(i, j))
        return false;

      if (image[i][j] != tetrominoSchematic[i - x][j - y]) {
        return false;
      }

      if (image[i][j] == BLOCK)
        image[i][j] = VISITED;
    }
  }

  for (int i = x; i < x + sz(tetrominoSchematic); i++) {
    for (int j = y; j < y + sz(tetrominoSchematic[i - x]); j++) {
      if (image[i][j] == VISITED && isSurroundedByBlocks(i, j)) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  fast_io();

  char givenTetrominoType;

  cin >> givenTetrominoType;

  for (int i = 0; i < 7; i++) {
    if (givenTetrominoType == tetrominoTypes[i]) {
      t = i;
      break;
    }
  }

  cin >> r >> c;

  vector<string> givenImage(r);
  for (int i = 0; i < r; i++) {
    cin >> givenImage[i];
  }

  image = vector<vector<char>>(r, vector<char>(c));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      image[i][j] = givenImage[i][j];
    }
  }

  int count = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (image[i][j] == BLOCK) {
        bool matches = false;
        for (int k = 0; k < 4; k++) {
          matches = matches || matchShape(i, j, k);
          revertVisitedBlocks(i, j, k);
        }

        if (matches) {
          count++;
        }

        invalidateShape(i, j);
      }
    }
  }

  cout << count << '\n';
}