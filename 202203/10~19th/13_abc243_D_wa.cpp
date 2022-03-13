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
  int N;
  unsigned long long X; cin >> N >> X;
  string S; cin >> S;
  rep(i,N) {
    if(S[i] == 'U') X = X / 2;
    if(S[i] == 'L') X = 2*X;
    if(S[i] == 'R') X = 2*X + 1;
  }
  cout << X << endl;
}

// 途中に桁数が非常に大きくなってしまうことがある.
// 最終的な値は10^18以内で保証されているので、stack等を使って、間のものを消去する