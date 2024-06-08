#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 0;
	int result = -1001;
	cin >> t;

	vector<int> score(t);
	vector<int> dp(t);

	for (int i = 0; i < t; ++i) {
		cin >> score[i];
	}

	result = score[0];
	dp[0] = score[0];
	for (int i = 1; i < t; ++i) {

		dp[i] = max(dp[i - 1] + score[i], score[i]);
		result = max(dp[i], result);
	}
	cout << result;
}