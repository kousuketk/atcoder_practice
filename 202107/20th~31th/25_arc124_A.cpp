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
const ll MOD = 998244353;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N, K; cin >> N >> K;
  vector<int> vec(N+1);
  rep(i,K) {
    char ch; cin >> ch;
    int tmp; cin >> tmp;
    if(ch == 'L') {
      vec[tmp] = -1;
      // tmp~Nまでを++
      rep(j,N-tmp) {
        if(vec[tmp+j+1] != -1) vec[tmp+j+1]++;
      }
    } else {
      vec[tmp] = -1;
      // 1~tmpまでを++
      rep(j,tmp) {
        if(vec[j+1] != -1) vec[j+1]++;
      }
    }
  }
  ll ans = 1;
  rep(i,N) {
    if(vec[i+1] == -1) ans = ans*1;
    else ans = (ans * vec[i+1]) % MOD;
  }
  cout << ans << endl;
}