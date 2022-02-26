#include <bits/stdc++.h>
using namespace std;

int dp[510][10010]; // i番目まで見たとき、jを作るのにi番目の要素が必要な個数
int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    vector<int> B(N);
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];
    for(int i=0;i<510;i++)for(int j=0;j<10010;j++) dp[i][j]=-1;
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= M; j++) {
            if(dp[i][j] >= 0) dp[i+1][j] = max(dp[i+1][j], 0);
            if(j-A[i] >= 0 && dp[i+1][j-A[i]] >= 0 && dp[i+1][j-A[i]] < B[i]) {
                dp[i+1][j] = dp[i+1][j-A[i]]+1;
            }
        }
    }
    if(dp[N][M] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}

// https://algo-method.com/submissions/331674