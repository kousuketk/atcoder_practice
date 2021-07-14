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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  int M; cin >> M;
  vector<int> quest(M);
  rep(i,M) cin >> quest[i];
  for(int k = 0; k < M; k++) {
    bool flag = false;
    for(int i = 0; i < (1<<N); i++) {
      bitset<20> s(i);

      int sum = 0;
      for(int j = 0; j < N; j++) {
        if(s.test(j)) sum += vec[j];
      }
      if(sum == quest[k]) {
        cout << "yes" << endl;
        flag = true;
        break;
      }
    }
    if(!flag) cout << "no" << endl;
  }
}