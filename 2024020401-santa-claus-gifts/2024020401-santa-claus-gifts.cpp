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
 * C. Santa Claus's Gifts
 * https://codeforces.com/group/OPrRXQFy1X/contest/502743/problem/C
 */

using namespace std;

struct Toy {
  int id, position;
  ll value;

  bool operator<(const Toy &other) const { return value < other.value; }
};

int n, m;
vector<ll> rangeSum;
vector<Toy> toys;
map<int, priority_queue<Toy>> toysInRange;

Toy getTopToyByToyId(int id) {
  if (toysInRange[id].size() == 0)
    return Toy{0, 0, 0};
  return toysInRange[id].top();
}

void calculateRangeSums() {
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll valueToAdd = toys[i].value;
    ll topValueWithAddedToyId = getTopToyByToyId(toys[i].id).value;

    if (topValueWithAddedToyId < valueToAdd) {
      // cout << "Reducing value to add by " << topValueWithAddedToyId << '\n';
      valueToAdd -= topValueWithAddedToyId;
      // cout << "Adding " << valueToAdd << '\n';
      sum += valueToAdd;
    } else {
      // cout << "Nothing added" << '\n';
    }

    toysInRange[toys[i].id].push(toys[i]);

    if (i >= m) {
      ll valueToSubtract = toys[i - m].value;
      ll topValueWithRemovedToyId = getTopToyByToyId(toys[i - m].id).value;

      if (valueToSubtract == topValueWithRemovedToyId) {
        ll nextTopValue = 0;

        while (toysInRange[toys[i - m].id].size() != 0) {
          Toy topValueCandidate = getTopToyByToyId(toys[i - m].id);

          if (topValueCandidate.position <= i - m) {
            toysInRange[toys[i - m].id].pop();
            continue;
          }

          nextTopValue = topValueCandidate.value;
          break;
        }

        // cout << "Reducing subtraction value by" << nextTopValue << '\n';
        valueToSubtract -= nextTopValue;
        // cout << "Subtracting " << valueToSubtract << '\n';
        sum -= valueToSubtract;
      }
    }

    rangeSum[i] = sum;
  }
}

int main() {
  fast_io();

  cin >> n >> m;

  m++;

  rangeSum = vector<ll>(n, -1);

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    toys.push_back({v, 0, i});
  }

  for (int i = 0; i < n; i++) {
    ll v;
    cin >> v;
    toys[i].value = v;
  }

  calculateRangeSums();

  ll mx = 0;
  for (int i = 0; i < n; i++) {
    if (mx < rangeSum[i])
      mx = rangeSum[i];
  }

  cout << mx << '\n';
}