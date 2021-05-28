#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  cout << "";
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    cout << *itr << " "; 
  }
  cout << endl;
}

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> wei(N);
  vector<int> val(N);
  rep(i,N) cin >> wei[i] >> val[i];
  vector<int> box(M);
  rep(i,M) cin >> box[i];
  for(int i = 0; i < Q; i++) {
    int left, right;
    cin >> left >> right;
    vector<int> new_box;
    for(int j = 0; j < left-1; j++) {
      new_box.push_back(box[j]);
    }
    for(int j = right; j < M; j++) {
      new_box.push_back(box[j]);
    }
    sort(new_box.begin(), new_box.end());
    // new_boxに対して、最初の要素から、weiより大きければ, max(val)を取る
    int ans = 0;
    vector<bool> used(N);
    for(int j = 0; j < new_box.size(); j++) {
      int tmp_max = 0;
      int tmp_index = 0;
      for(int k = 0; k < N; k++) {
        if(new_box[j] >= wei[k] && tmp_max < val[k] && used[k] == false) {
          tmp_max = val[k];
          tmp_index = k;
        }
      }
      if(tmp_max > 0) {
        ans += tmp_max;
        used[tmp_index] = true;
      }
    }
    cout << ans << endl;
  }
}