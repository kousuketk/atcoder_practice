#include <bits/stdc++.h>
using namespace std;

int INF = 111111111;
int dp[110][110]; // aのi番目, bのｊ番目までをマッチさせたときの最小値
int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> vec(N, vector<int>(M));
    for(int i=0;i<N;i++)for(int j=0;j<M;j++) cin >> vec[i][j];
    for(int i=0;i<110;i++)for(int j=0;j<110;j++) dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dp[i+1][j+1] = min({dp[i][j], dp[i+1][j], dp[i][j+1]}) + vec[i][j];
        }
    }
    cout << dp[N][M] << endl;
	return 0;
}

// https://algo-method.com/tasks/316