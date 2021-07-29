#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N; cin >> N;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  bool flag = false;
  for(int i = 0; i < N-2; i++) {
    for(int j = i+1; j < N-1; j++) {
      for(int k = j+1; k < N; k++) {
        if(vec[i].first == vec[j].first && vec[i].first == vec[k].first) {
          flag = true;
          break;
        }
        if(vec[i].first == vec[j].first || vec[i].first == vec[k].first || vec[j].first == vec[k].first) continue;
        // 傾き
        int til_left = (vec[j].second-vec[i].second)*(vec[k].first-vec[i].first);
        int til_right = (vec[k].second-vec[i].second)*(vec[j].first-vec[i].first);
        if(til_left != til_right) continue;
        // 切片
        int cut_left = (vec[j].second-vec[i].second)*vec[i].first*(vec[k].first-vec[i].first);
        int cut_right = (vec[k].second-vec[i].second)*vec[i].first*(vec[j].first-vec[i].first);
        if(cut_left != cut_right) continue;
        flag = true;
      }
      if(flag) break;
    }
    if(flag) break;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}