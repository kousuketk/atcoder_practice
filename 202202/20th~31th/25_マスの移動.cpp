#include <bits/stdc++.h>
using namespace std;

int dp[110];  //i番目までいくのに最短距離
int main() {
	int N; cin >> N;
	vector<int> vec(N);
	for(int i = 0; i < N; i++) cin >> vec[i];
	for(int i = 0; i < N; i++) {
		if(i == 0) {
			dp[i] = 0;
		} else if(i == 1) {
			dp[i] = vec[i];
		} else {
			dp[i] = min(dp[i-2]+vec[i]*2, dp[i-1]+vec[i]);
		}
	}
	cout << dp[N-1] << endl;
	return 0;
}