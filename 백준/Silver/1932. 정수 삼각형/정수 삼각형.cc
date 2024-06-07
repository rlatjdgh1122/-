#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t = 0;
	int result = 0;
	cin >> t;

	vector<vector<int>> score(t, vector<int>(501));
	vector<vector<int>> dp(t, vector<int>(501));

	for (int i = 0; i < t; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> score[i][j];
		}
	}

	dp[0][0] = dp[0][1] = score[0][0];

	for (int i = 1; i < t; ++i) { //층
		for (int j = 0; j <= i; ++j) //호
		{
			if (j == 0) { //맨앞에 있는 친구들
				dp[i][0] = dp[i - 1][0] + score[i][0];
			}
			else if (j == i) //끝에있는 친구들
			{
				dp[i][j] = dp[i - 1][j - 1] + score[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + score[i][j];
			}
		}
	}

	for (int i = 0; i < t; ++i)
		if (result < dp[t - 1][i]) {
			result = dp[t - 1][i];
		}

	cout << result;
}