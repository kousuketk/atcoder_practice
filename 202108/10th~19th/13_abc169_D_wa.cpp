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
  ll N; cin >> N;
  int cnt = 0;
  ll tmp_N = N;
  ll last_i = 1;
  for(ll i = 2; i*i <= N; i++) {
    if(tmp_N % i == 0) {
      tmp_N = tmp_N/i;
      last_i = i;
      cnt++;
      cout << i << endl;
    }
  }
  if(tmp_N > last_i) cnt++;
  cout << cnt << endl;
}

// そもそも問題の条件を満たせていない