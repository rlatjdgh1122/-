#include <iostream>
#include <vector>
using namespace std;

int dp[1001];
int score[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 0;
	int result = 0;
	cin >> t;

	//나보다 작은 애들중 길이가 가장 큰애들에서 + 1
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		score[i] = n;
	}
	for (int i = 0; i < t; ++i) {

		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (score[i] > score[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	for (int i = 0; i < t; ++i) {
		if (dp[i] > result)
			result = dp[i];
	}

	cout << result;
}
