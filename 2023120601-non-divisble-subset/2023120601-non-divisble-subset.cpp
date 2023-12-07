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
 * Non-Divisible Subset
 * https://www.hackerrank.com/challenges/non-divisible-subset/problem
 */

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> modulusCount;

int nonDivisibleSubset(int k, vector<int> s) {
  if (k == 1)
    return 1;

  modulusCount = vector<int>(100, 0);

  for (int i = 0; i < sz(s); i++) {
    modulusCount[s[i] % k]++;
  }

  int sum = 0;
  for (int i = 1; i < (k + 1) / 2; i++) {
    sum += max(modulusCount[i], modulusCount[k - i]);
  }

  if (modulusCount[k / 2] && k % 2 == 0)
    sum++;
  if (modulusCount[0])
    sum++;

  return sum;
}

int main() {
  char *outputPath = getenv("OUTPUT_PATH");
  ofstream fout(outputPath);

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int k = stoi(first_multiple_input[1]);

  string s_temp_temp;
  getline(cin, s_temp_temp);

  vector<string> s_temp = split(rtrim(s_temp_temp));

  vector<int> s(n);

  for (int i = 0; i < n; i++) {
    int s_item = stoi(s_temp[i]);

    s[i] = s_item;
  }

  int result = nonDivisibleSubset(k, s);

  if (outputPath == nullptr)
    cout << result << '\n';

  fout << result << "\n";

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
