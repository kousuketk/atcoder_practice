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

int N;
vector<int> vec;
void resolve() {
  if(vec[N-1] - vec[N-2] >= 2) {  // 先手の勝ち
    cout << "Alice" << endl;
    return;
  }
  int rest = vec[N-1] - (N-1);
  if(rest % 2 == 0) cout << "Bob" << endl;  // 先手の負け
  else cout << "Alice" << endl;
  return;
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  resolve();
}