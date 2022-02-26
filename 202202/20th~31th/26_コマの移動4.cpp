#include <bits/stdc++.h>
using namespace std;
// https://algo-method.com/tasks/335

int INF = 111111111;
int dp[110][110];
int main() {
	int N; cin >> N;
    vector<vector<int>> vec(N, vector<int>(N));
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> vec[i][j];
    for(int i = 0; i < 110; i++) for(int j = 0; j < 110; j++) dp[i][j] = INF;
    dp[0][N-1] = vec[0][N-1]; // スタート
    for(int i = 0; i < N; i++) {
        for(int j = N-1; j >= 0; j--) {
            if(j+1 < N) dp[i][j] = min(dp[i][j], dp[i][j+1]+vec[i][j]);
            if(i-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+vec[i][j]);
        }
    }
    cout << dp[N-1][0] << endl;
	return 0;
}