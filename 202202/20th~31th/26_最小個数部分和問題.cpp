// https://algo-method.com/tasks/311

#include <bits/stdc++.h>
using namespace std;
int INF = 11111111;
int dp[110][10100]; // i番目にjにできる最小の個数
int main() {
    int N, M; cin >> N >> M;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    for(int i = 0; i < 110; i++) for(int j = 0; j < 10100; j++) dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= M; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j-vec[i] >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i][j-vec[i]]+1);
        }
    }
    if(dp[N][M] != INF) cout << dp[N][M] << endl;
    else cout << -1 << endl;
	return 0;
}