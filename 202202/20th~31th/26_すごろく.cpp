#include <bits/stdc++.h>
using namespace std;

// https://algo-method.com/tasks/323

bool dp[1010]; // マスiに行けるか
int main() {
	int N, M; cin >> N >> M;
    vector<int> vec(M);
    for(int i = 0; i < M; i++) cin >> vec[i];
    dp[0] = true;  // スタート
    // 全てのvecの要素(M)に対して、マスをなめていく(N)→O(MN)
    for(int i = 0; i < M; i++) {
        int d = vec[i];
        for(int j = 0; j <= N; j++) {
            if(j-d < 0) continue;
            if(dp[j-d]) dp[j] = true;
        }
    }
    if(dp[N]) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}