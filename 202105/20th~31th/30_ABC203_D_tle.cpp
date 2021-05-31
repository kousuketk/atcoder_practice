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
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N, K;
  cin >> N >> K;
  ll count_N = (N-K+1)*(N-K+1);
  ll vec[N][N];
  rep(i,N)rep(j,N) cin >> vec[i][j];
  ll mas = K*K;
  ll num = K*K - (K*K/2 + 1);
  vector<ll> centor(count_N);
  for(ll i = 0; i < count_N; i++) {
    ll a = i;
    ll b = 0;
    while(a+K-1 > N-1) {
      a -= N-1;
      b++;
    }
    // (a, b)から(a+k-1, b+k-1)を見て、num番目を配列に入れる
    vector<int> tmp(mas);
    for(int j = 0; j < mas; j++) {
      int aa = j;
      int bb = 0;
      while(aa > K-1) {
        aa -= K;
        bb++;
      }
      tmp[j] = vec[b+bb][a+aa];
    }
    sort(tmp.begin(), tmp.end());
    centor[i] = tmp[num];
  }
  sort(centor.begin(), centor.end());
  cout << centor[0] << endl;
}