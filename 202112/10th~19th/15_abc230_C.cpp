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
  ll N, A, B, P, Q, R, S; cin >> N >> A >> B >> P >> Q >> R >> S;
  ll min_k1 = max(1-A, 1-B);
  ll max_k1 = min(N-A, N-B);
  ll min_k2 = max(1-A, B-N);
  ll max_k2 = min(N-A, B-1);
  for(ll i = P; i <= Q; i++) {
    for(ll j = R; j <= S; j++) {
      // 最初の条件(k1)
      ll k1_a = i - A;
      ll k1_b = j - B;
      if(k1_a == k1_b && k1_a >= min_k1 && k1_a <= max_k1) {
        cout << "#";
        continue;
      }
      // 次の条件(k2)
      ll k2_a = i - A;
      ll k2_b = -(j - B);
      if(k2_a == k2_b && k2_a >= min_k2 && k2_a <= max_k2) {
        cout << "#";
        continue;
      }
      cout << ".";
    }
    cout << endl;
  }
  return 0;
}