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
  ll count = 1;
  int i = 0;
  ll tmp = 1;
  while(true) {
    if(N < tmp) {
      tmp = tmp/2;
      i--;
      break;
    }
    tmp = tmp*2;
    i++;
  }
  // A→B*i→A*(N-tmp)
  cout << "A";
  rep(j,i) cout << "B";
  rep(j,N-tmp) cout << "A";
  cout << endl;
}

// 1000000000000000000