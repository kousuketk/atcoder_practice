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
  string S; cin >> S;
  int Q; cin >> Q;
  int rev = -1;
  rep(i,Q) {
    int t; cin >> t;
    if(t == 1) {
      rev = rev*(-1);
    } else {
      int f; cin >> f;
      char c; cin >> c;
      if(f == 1 && rev == -1 || f == 2 && rev == 1) S = c + S;
      else S = S + c;
    }
  }
  if(rev == 1) reverse(ALL(S));
  cout << S << endl;
  return 0;
}

// c++などは普通の文字列型の先頭についかする操作の計算量は悪いため、dequeueで対応する