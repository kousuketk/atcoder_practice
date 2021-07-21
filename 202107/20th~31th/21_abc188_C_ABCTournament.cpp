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
  int M = pow(2, N);
  vector<P> par(M); // first：スコア, second：番号
  rep(i,M) {
    int tmp; cin >> tmp;
    par[i].first = tmp;
    par[i].second = i;
  }
  vector<P> winner;
  int ans;
  rep(i,N) {
    if(i == N-1) {
      if(par[0] > par[1]) ans = par[1].second;
      else ans = par[0].second;
    }
    M = pow(2, N-i-1); // M：比較回数
    winner.resize(M); // winner：勝者(人数は比較回数と同じ)
    rep(j,M) {
      // par[j*2], par[j*2+1]を比較して、大きい方をwinner[j]にする
      if(par[j*2].first > par[j*2+1].first) {
        winner[j].first = par[j*2].first;
        winner[j].second = par[j*2].second;
      } else {
        winner[j].first = par[j*2+1].first;
        winner[j].second = par[j*2+1].second;
      }
    }
    par.resize(M); // winnerは次の参加者である
    rep(j,M) {
      par[j].first = winner[j].first;
      par[j].second = winner[j].second;
    }
  }
  cout << ans+1 << endl;
}

// N<=16
// 計算量O(N*2^N)  2^16=65,536