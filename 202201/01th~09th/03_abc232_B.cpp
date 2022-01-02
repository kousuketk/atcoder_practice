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
  string S, T; cin >> S >> T;
  int diff = (int)T[0] - (int)S[0];
  if(diff < 0) diff += 26;
  int N = S.size() - 1;
  bool ans = true;
  while(N > -1) {
    // Tにdiffを足していき、122を超えたら-'a'をして、S[N]と同じであるか
    int tmp = (int)S[N] + diff;
    if(tmp > 122) tmp = tmp - 26;
    if(tmp != (int)T[N]) {
      ans = false;
      break;
    }
    N--;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}