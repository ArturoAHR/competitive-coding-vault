#include <bits/stdc++.h>
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define MOD 1000000007
typedef long long ll;
typedef double db;

/*
 * A. Halloumi Boxes
 * https://codeforces.com/problemset/problem/1903/A
*/

using namespace std;

int t, n, k;
vector<int> a;

void solve() {
	cin >> n >> k;
	a = vector<int>(n);
	
	for(int &i : a) {
		cin >> i;
	}
 
  bool ordered = true;
  int mx = 0;

	for (int i = 0; i < a.size(); i++) {
		if(mx <= a[i]) {
			mx = a[i];
		}
		else {
			ordered = false;
		}
	}

	if(k >= 2 || ordered) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	fast_io();
	cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
}