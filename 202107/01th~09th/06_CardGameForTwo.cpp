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
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  sort(vec.begin(), vec.end(), greater<int>{});
  int alice = 0, bob = 0;
  rep(i,N) {
    if(i % 2 == 0) alice += vec[i];
    else bob += vec[i]; 
  } 
  cout << (alice - bob) << endl;
}