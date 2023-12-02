#include <bits/stdc++.h>
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define MOD 1000000007
typedef long long ll;
typedef double db;

/*
 * A. Domino piling
 * https://codeforces.com/problemset/problem/50/A
*/

using namespace std;

int m, n;

int main() {
	fast_io();
	cin >> m >> n;
	cout << m * n / 2 << '\n';
}