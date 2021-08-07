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
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      for(int k = j+1; k < N; k++) {
        // i+j > kならok
        if(vec[i] == vec[j] || vec[i] == vec[k] || vec[j] == vec[k]) continue;
        vector<int> tmp(3);
        tmp[0] = vec[i];
        tmp[1] = vec[j];
        tmp[2] = vec[k];
        sort(ALL(tmp));
        if((tmp[0]+tmp[1]) > tmp[2]) ans++;
      }
    }
  }
  cout << ans << endl;
}