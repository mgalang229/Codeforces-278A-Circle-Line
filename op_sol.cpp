#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int f[100 + 2] = {0};
	// this is the algorithm for getting the distances from 
	// the 1st station to every other station including 1 full travel
	for (int i = 2; i < n + 2; i++) {
		int d;
		cin >> d;
		// store the sum of the previous distance and the current distance
		// to get the total distance of the 1st station up to the i-th station
		f[i] = f[i - 1] + d;
	}
	int s, t;
	// swap 's' and 't' to correct the order
	cin >> s >> t;
	if (s > t) {
		swap(s, t);
	}
	// get the distance between 's' and 't' stations by using them as an index
	int distance = f[t] - f[s];
	// f[n + 1] - distance is the formula for finding the distance
	// using the other way around the circle
	cout << min(distance, (f[n + 1] - distance)) << '\n';
	return 0; 
}
