#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(int mid, int c, vector<int>& nums) {
	int cP = 1, j = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] - nums[j] >= mid) {
			cP = cP + 1;
			if (cP == c) {		break;		}
			j = i;
		}
	}
	return cP == c;
}

int lmd(int c, vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int l = 0, r = 1e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (isPossible(mid, c, nums)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return r;
}


void solve() {
	int n;		cin >> n;
	int c;		cin >> c;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << lmd(c, nums) << endl;
}


int main() {
	int t;      cin >> t;
	while (t--) {		solve();		}
	return 0;
}
