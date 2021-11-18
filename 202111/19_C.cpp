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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  // i番目をすべて解きコンプリートボーナスを獲得して貪欲法
  int D, G; cin >> D >> G;
  vector<P> vec(D);
  int ans = 0;
  rep(i,D) {
    int p, c; cin >> p >> c;
    vec[i] = P(p,c);
    ans += p;
  }
  for(int tmp = 0; tmp < (1<<D); tmp++) {
    bitset<10> bit(tmp);

    int score = 0;
    int cnt = 0;
    for(int i = 0; i < D; i++) {
      if(bit.test(i)) {
        score += 100*(i+1)*vec[i].first + vec[i].second;
        cnt += vec[i].first;
      }
    }
    if(score >= G) {
      ans = min(ans, cnt);
    } else {
      // 貪欲法で入れていく
      bool flag = false;
      for(int i = D-1; i >= 0; i--) {
        if(!bit.test(i)) {
          for(int j = 1; j < vec[i].first; j++) {
            score += 100*(i+1);
            cnt += 1;
            if(score >= G) {
              flag = true;
              break;
            }
          }
          break;
        }
      }
      if(flag) ans = min(ans, cnt);
    }
  }
  cout << ans << endl;
}