#include <bits/stdc++.h>
using namespace std;

// https://algo-method.com/tasks/353

bool dp[100][50100]; // i番目を見た時、差をjにできるか
// trueの要素に対して、差の絶対値と和を考慮する
int main() {
    int N; cin >> N;
    vector<int> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];
    dp[0][0] = true; // スタート
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= 50000; j++) {
            if(dp[i][j]) {
                // i-1番目までで、取りうる差に対して、差の絶対値と和を取る
                dp[i+1][abs(j-W[i])] = true;
                dp[i+1][j+W[i]] = true;
            }
        }
    }
    int ans;
    for(int j = 0; j <= 50000; j++) {
        if(dp[N][j]) {
            ans = j;
            break;
        }
    }
    cout << ans << endl;
	return 0;
}