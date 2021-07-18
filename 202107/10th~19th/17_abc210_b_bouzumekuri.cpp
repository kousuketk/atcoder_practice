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
  string S; cin >> S;
  for(int i = 0; i < N; i++) {
    if(S[i] == '1') {
      if(i % 2 == 0) {
        cout << "Takahashi" << endl;
        return 0;
      } else {
        cout << "Aoki" << endl;
        return 0;
      }
    }
  }
}