#include <bits/stdc++.h>
using namespace std;

bool dp[110][1100];
int main() {
    int N, M; cin >> N >> M;
    dp[0][0] = true;
    for(int i = 0; i < N; i++) {
        int w; cin >> w;
        for(int j = 0; j <= M; j++) {
            if(dp[i][j]) dp[i+1][j] = true;
            if(j-w >= 0 && dp[i][j-w]) dp[i+1][j] = true;
        }
    }
    if(dp[N][M]) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}