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
  int count = 0;
  rep(i,N+1) {
    // 10進法
    int ten = i;
    bool flag_ten = false;
    while(ten) {
      if(ten % 10 == 7) {
        count++;
        flag_ten = true;
        break;
      }
      ten = ten/10;
    }
    if(flag_ten) continue;
    // 8進法
    int eight = i;
    while(eight) {
      if(eight % 8 == 7) {
        count++;
        break;
      }
      eight = eight/8;
    }
  }
  cout << (N-count) << endl;
}