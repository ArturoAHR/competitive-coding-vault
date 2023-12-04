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
 * The Grid Search
 * https://www.hackerrank.com/challenges/the-grid-search/problem
 */

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string gridSearch(vector<string> G, vector<string> P) {
  int gridRows = sz(G), patternRows = sz(P), gridColumns = sz(G[0]),
      patternColumns = sz(P[0]);

  ll prime = 29, patternHash = 0;
  ll primePow[1000], gridRowHash[gridRows][gridColumns];

  // Hashes are computed in O(n^2) using a rolling hash technique.
  // https://brilliant.org/wiki/rabin-karp-algorithm/

  // Precompute powers of prime number
  primePow[0] = 1;
  for (int i = 1; i < 1000; i++) {
    primePow[i] = (primePow[i - 1] * prime) % MOD;
  }

  // Compute pattern hash
  for (int i = 0; i < patternRows; i++) {
    ll rowHash = 0;
    for (int j = 0; j < patternColumns; j++) {
      rowHash = (rowHash * prime + (P[i][j] - '0')) % MOD;
    }

    patternHash = (patternHash * prime + rowHash) % MOD;
  }

  // Compute grid rows hash
  for (int i = 0; i < gridRows; i++) {
    ll rowHash = 0;
    for (int j = 0; j < gridColumns; j++) {
      rowHash = (rowHash * prime + (G[i][j] - '0')) % MOD;

      if (j >= patternColumns) {
        rowHash =
            (MOD + rowHash -
             ((G[i][j - patternColumns] - '0') * primePow[patternColumns]) %
                 MOD) %
            MOD;
      }

      gridRowHash[i][j] = rowHash;
    }
  }

  // Compute grid sub-matrix hash and match with pattern hash
  for (int j = 0; j < gridColumns; j++) {
    ll subMatrixHash = 0;
    for (int i = 0; i < gridRows; i++) {
      subMatrixHash = (subMatrixHash * prime + gridRowHash[i][j]) % MOD;

      if (i >= patternRows) {
        subMatrixHash =
            (MOD + subMatrixHash -
             (gridRowHash[(i - patternRows)][j] * primePow[patternRows]) %
                 MOD) %
            MOD;
      }

      if (subMatrixHash == patternHash) {
        return "YES";
      }
    }
  }

  return "NO";
}

int main() {
  char *outputPath = getenv("OUTPUT_PATH");

  ofstream fout(outputPath);

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));

    int R = stoi(first_multiple_input[0]);

    int C = stoi(first_multiple_input[1]);

    vector<string> G(R);

    for (int i = 0; i < R; i++) {
      string G_item;
      getline(cin, G_item);

      G[i] = G_item;
    }

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input =
        split(rtrim(second_multiple_input_temp));

    int r = stoi(second_multiple_input[0]);

    int c = stoi(second_multiple_input[1]);

    vector<string> P(r);

    for (int i = 0; i < r; i++) {
      string P_item;
      getline(cin, P_item);

      P[i] = P_item;
    }

    string result = gridSearch(G, P);

    if (outputPath == nullptr)
      cout << result << "\n";
    else
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

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
