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
  vector<int> vec(10);
  vec[0] = 1;
  for(int i = 1; i < 10; i++) {
    vec[i] = vec[i-1]*(i+1);
  }
  reverse(vec.begin(), vec.end());
  ll ans = 0;
  for(int i = 0; i < 10; i++) {
    int tmp = N / vec[i];
    ans += tmp; 
    N = N - vec[i]*tmp;
  }
  cout << ans << endl;
}