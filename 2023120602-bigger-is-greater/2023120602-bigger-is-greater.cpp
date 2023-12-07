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
 * Bigger is Greater
 * https://www.hackerrank.com/challenges/bigger-is-greater/problem
 */

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void swap(char &a, char &b) {
  char tmp = a;
  a = b;
  b = tmp;
}

string biggerIsGreater(string w) {
  vector<char> word;

  for (char c : w) {
    word.push_back(c);
  }

  vector<char> suffixMaximumArray(w.length());

  char mx = word[sz(word) - 1];
  for (int i = sz(word) - 1; i >= 0; i--) {
    if (mx < w[i]) {
      mx = w[i];
    }

    suffixMaximumArray[i] = mx;
  }

  int swapIndexA = -1, swapIndexB = -1;
  for (int i = sz(word) - 1; i >= 0; i--) {
    if (word[i] < suffixMaximumArray[i]) {
      swapIndexA = i;
      break;
    }
  }

  if (swapIndexA == -1)
    return "no answer";

  int nextBiggerThanA = INT_MAX;
  for (int i = swapIndexA + 1; i < sz(word); i++) {
    if (nextBiggerThanA >= word[i] && word[i] > word[swapIndexA]) {
      swapIndexB = i;
      nextBiggerThanA = word[i];
    }
  }

  swap(word[swapIndexA], word[swapIndexB]);

  sort(word.begin() + swapIndexA + 1, word.end());

  string result = "";
  for (char c : word) {
    result += c;
  }

  return result;
}

int main() {
  char *outputPath = getenv("OUTPUT_PATH");
  ofstream fout(outputPath);

  string T_temp;
  getline(cin, T_temp);

  int T = stoi(ltrim(rtrim(T_temp)));

  for (int T_itr = 0; T_itr < T; T_itr++) {
    string w;
    getline(cin, w);

    string result = biggerIsGreater(w);
    if (outputPath == nullptr)
      cout << result << '\n';

    fout << result << "\n";
  }

  fout.close();

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
