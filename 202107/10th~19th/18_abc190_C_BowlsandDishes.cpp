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
  int N, M, K; cin >> N >> M;
  vector<P> con(M);
  rep(i,M) cin >> con[i].first >> con[i].second;
  cin >> K;
  vector<P> vec(K);
  rep(i,K) cin >> vec[i].first >> vec[i].second;
  int ans = 0;
  for(int i = 0; i < (1<<K); i++) {
    bitset<16> s(i);

    map<int, int> mp = {};
    for(int j = 0; j < K; j++) {
      if(s.test(j)) {
        mp[vec[j].first] += 1;
      } else {
        mp[vec[j].second] += 1;
      }
    }

    // M個の条件を満たすか?(それぞれmpにあるか?)
    int sum = 0;
    for(int j = 0; j < M; j++) {
      if(mp[con[j].first] >= 1 && mp[con[j].second] >= 1) sum++;
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
}