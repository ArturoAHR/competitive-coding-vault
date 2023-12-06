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
 * Crossword Puzzle
 * https://www.hackerrank.com/challenges/crossword-puzzle/problem
 */

using namespace std;

struct Position {
  int x, y;
  Position operator+(Position pos) { return {x + pos.x, y + pos.y}; }
  Position operator-(Position pos) { return {x - pos.x, y - pos.y}; }
  bool operator==(Position pos) { return (x == pos.x && y == pos.y); }
  bool operator<(Position pos) const {
    return x < pos.x || (x == pos.x && y < pos.y);
  }
  friend std::ostream &operator<<(std::ostream &os, const Position &pos) {
    os << pos.x << ' ' << pos.y;
    return os;
  }
  bool isWithinCrossword() { return 0 <= x && x <= 9 && 0 <= y && y <= 9; }
};

struct WordLink {
  int intersectingSpaceId, position, intersectingSpacePosition;
};

struct CrosswordWord {
  bool used;
  string word;
};

struct CrosswordSpace {
  Position start, end;
  vector<char> content;
  vector<WordLink> links;
};

string ltrim(const string &);
string rtrim(const string &);

enum Direction { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<char>> crossword = vector<vector<char>>(10, vector<char>(10));
vector<CrosswordWord> words;
vector<CrosswordSpace> crosswordSpaces;

void printCrossword() {}

void printCrosswordSpaces() {
  for (int i = 0; i < sz(crosswordSpaces); i++) {
    cout << i << '\n';

    for (int v : crosswordSpaces[i].content) {
      cout << (char)v;
    }
    cout << '\n';

    cout << crosswordSpaces[i].start << ' ' << crosswordSpaces[i].end << '\n';
    for (int j = 0; j < sz(crosswordSpaces[i].links); j++) {
      cout << crosswordSpaces[i].links[j].intersectingSpaceId << ' '
           << crosswordSpaces[i].links[j].intersectingSpacePosition << '\n';
    }
  }
}

void addWordLinks(CrosswordSpace &currentCrosswordSpace,
                  Position linkPosition) {
  int intersectingCrosswordSpaceIndex = -1;
  for (int i = 0; i < sz(crosswordSpaces); i++) {
    if (crosswordSpaces[i].start.x <= linkPosition.x &&
        linkPosition.x <= crosswordSpaces[i].end.x &&
        crosswordSpaces[i].start.y <= linkPosition.y &&
        linkPosition.y <= crosswordSpaces[i].end.y) {
      intersectingCrosswordSpaceIndex = i;
      break;
    }
  }

  CrosswordSpace *intersectingCrosswordSpace =
      &crosswordSpaces[intersectingCrosswordSpaceIndex];

  WordLink currentSpaceLink, intersectingSpaceLink;

  currentSpaceLink.intersectingSpaceId = intersectingCrosswordSpaceIndex;
  intersectingSpaceLink.intersectingSpaceId = sz(crosswordSpaces);

  currentSpaceLink.position =
      abs(currentCrosswordSpace.start.x - linkPosition.x) +
      abs(currentCrosswordSpace.start.y - linkPosition.y);

  currentSpaceLink.intersectingSpacePosition =
      abs(intersectingCrosswordSpace->start.x - linkPosition.x) +
      abs(intersectingCrosswordSpace->start.y - linkPosition.y);

  intersectingSpaceLink.position =
      abs(intersectingCrosswordSpace->start.x - linkPosition.x) +
      abs(intersectingCrosswordSpace->start.y - linkPosition.y);

  intersectingSpaceLink.intersectingSpacePosition =
      abs(currentCrosswordSpace.start.x - linkPosition.x) +
      abs(currentCrosswordSpace.start.y - linkPosition.y);

  currentCrosswordSpace.links.push_back(currentSpaceLink);
  intersectingCrosswordSpace->links.push_back(intersectingSpaceLink);
}

void addCrosswordSpace(Position origin, int direction) {

  CrosswordSpace newCrosswordSpace;
  newCrosswordSpace.start = origin;

  Position currentPosition = origin;
  char currentPositionCharacter = crossword[origin.y][origin.x];
  while (currentPosition.isWithinCrossword() &&
         currentPositionCharacter != '+') {
    currentPositionCharacter = crossword[currentPosition.y][currentPosition.x];
    switch (currentPositionCharacter) {
    case 'x': // Intentional Fallthrough
      addWordLinks(newCrosswordSpace, currentPosition);
    case '-':
      newCrosswordSpace.content.push_back(' ');
      newCrosswordSpace.end = currentPosition;
      crossword[currentPosition.y][currentPosition.x] = 'x';
      currentPosition.x += dx[direction];
      currentPosition.y += dy[direction];
    }
  }

  crosswordSpaces.push_back(newCrosswordSpace);
}

bool resolveCrosswordSpaces(int currentSpace = 0) {
  if (currentSpace == sz(crosswordSpaces))
    return true;

  for (int i = 0; i < sz(words); i++) {
    if (words[i].used)
      continue;

    string currentWord = words[i].word;

    if (currentWord.length() != sz(crosswordSpaces[currentSpace].content))
      continue;

    bool collides = false;
    for (int j = 0; j < sz(crosswordSpaces[currentSpace].links); j++) {
      WordLink currentWordLink = crosswordSpaces[currentSpace].links[j];

      char intersectingCharacter =
          crosswordSpaces[currentWordLink.intersectingSpaceId]
              .content[currentWordLink.intersectingSpacePosition];

      if (intersectingCharacter != ' ' &&
          intersectingCharacter != currentWord[currentWordLink.position]) {
        collides = true;
      }
    }

    if (collides)
      continue;

    words[i].used = true;
    for (int j = 0; j < currentWord.length(); j++) {
      crosswordSpaces[currentSpace].content[j] = currentWord[j];
    }

    bool result = resolveCrosswordSpaces(currentSpace + 1);

    if (result)
      return true;

    words[i].used = false;
    for (int j = 0; j < currentWord.length(); j++) {
      crosswordSpaces[currentSpace].content[j] = ' ';
    }
  }

  return false;
}

vector<string> crosswordPuzzle(vector<string> inputCrossword,
                               string inputWords) {
  string currentWord = "";
  for (int i = 0; i < sz(inputWords); i++) {
    if (inputWords[i] == ';') {
      words.push_back(CrosswordWord{used : false, word : currentWord});
      currentWord = "";
      continue;
    }

    currentWord += inputWords[i];
  }

  words.push_back(CrosswordWord{used : false, word : currentWord});

  for (int y = 0; y < sz(inputCrossword); y++) {
    for (int x = 0; x < sz(inputCrossword[y]); x++) {
      crossword[y][x] = inputCrossword[y][x];
    }
  }

  for (int y = 0; y < sz(crossword); y++) {
    for (int x = 0; x < sz(crossword[y]); x++) {
      if (crossword[y][x] == '-' || crossword[y][x] == 'x') {
        Position nextPositionDown{x, y + dy[DOWN]},
            nextPositionRight{x + dx[RIGHT], y};
        if (nextPositionDown.isWithinCrossword() &&
            crossword[nextPositionDown.y][nextPositionDown.x] == '-') {
          addCrosswordSpace(Position{x, y}, DOWN);
        }
        if (nextPositionRight.isWithinCrossword() &&
            crossword[nextPositionRight.y][nextPositionRight.x] == '-') {
          addCrosswordSpace(Position{x, y}, RIGHT);
        }
      }
    }
  }

  resolveCrosswordSpaces();

  for (int i = 0; i < sz(crosswordSpaces); i++) {
    Position currentPosition = crosswordSpaces[i].start;
    Position positionDelta = crosswordSpaces[i].start - crosswordSpaces[i].end;
    int direction = positionDelta.x != 0 ? RIGHT : DOWN;

    for (int j = 0; j < sz(crosswordSpaces[i].content); j++) {
      crossword[currentPosition.y][currentPosition.x] =
          crosswordSpaces[i].content[j];

      currentPosition.x += dx[direction];
      currentPosition.y += dy[direction];
    }
  }

  vector<string> result(sz(crossword), "");
  for (int y = 0; y < sz(crossword); y++) {
    for (int x = 0; x < sz(crossword[y]); x++) {
      result[y] += crossword[y][x];
    }
  }

  return result;
}

int main() {
  char *outputPath = getenv("OUTPUT_PATH");
  ofstream fout(outputPath);

  vector<string> crossword(10);

  for (int i = 0; i < 10; i++) {
    string crossword_item;
    getline(cin, crossword_item);

    crossword[i] = crossword_item;
  }

  string words;
  getline(cin, words);

  vector<string> result = crosswordPuzzle(crossword, words);
  if (outputPath != nullptr) {
    for (size_t i = 0; i < result.size(); i++) {
      fout << result[i];

      if (i != result.size() - 1) {
        fout << "\n";
      }
    }

    fout << "\n";

    fout.close();
  } else {
    for (size_t i = 0; i < result.size(); i++) {
      cout << result[i];

      if (i != result.size() - 1) {
        cout << "\n";
      }
    }

    cout << "\n";
  }

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
