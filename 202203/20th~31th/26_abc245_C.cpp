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
  int N, K; cin >> N >> K;
  vector<int> A(N);
  vector<int> B(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  bool flagA = true;
  bool flagB = true;
  bool flagAns = true;
  for(int i = 1; i < N; i++) {
    bool tmpA = false;
    bool tmpB = false;
    if(flagA) {
      int a = A[i-1];
      if(abs(a-A[i]) <= K) tmpA = true;
      if(abs(a-B[i]) <= K) tmpB = true;
    }
    if(flagB) {
      int b = B[i-1];
      if(abs(b-A[i]) <= K) tmpA = true;
      if(abs(b-B[i]) <= K) tmpB = true;
    }
    if(!tmpA && !tmpB) {
      flagAns = false;
      break;
    }
    flagA = tmpA;
    flagB = tmpB;
  }
  if(flagAns) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}