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
  vector<P> s(N);
  vector<P> t(N);
  rep(i,N) {
    int a, b; cin >> a >> b;
    s[i] = P(a, b);
  }
  rep(i,N) {
    int a, b; cin >> a >> b;
    t[i] = P(a, b);
  }
  for(int i = 0; i < N; i++) {
    int a = s[i].first; 
    int b = s[i].second;
    for(int j = 0; j < N; j++) {
      int c = 0, d = 0;
      //t[j]をs[i]にする、移
      // s[i], t[j]を(0,0)にして
    }
  }
}