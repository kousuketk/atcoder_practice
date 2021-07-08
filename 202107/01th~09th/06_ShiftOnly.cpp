#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N; cin >> N;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  int count = 0;
  while(true) {
    bool flag = true;
    for(int i = 0; i < N; i++) {
      if(vec[i] % 2 == 1) flag = false;
    }
    if(!flag) break;
    for(int i = 0; i < N; i++) {
      vec[i] = vec[i]/2;
    }
    count++;
  }
  cout << count << endl;
}