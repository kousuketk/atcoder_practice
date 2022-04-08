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

// N個の正の整数a0, a1, ....aN-1と、正の整数Wが与えられる。
// 何個か選んで総和をWにすることができるか？(bit全探索で解く)
int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  for(int i = 0; i < (1<<N); i++) {
    bitset<20> bits(i);
    int val = 0;
    rep(i,N) {
      if(!bits.test(i)) continue;
      val += vec[i];
    }
    if(val == W) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}