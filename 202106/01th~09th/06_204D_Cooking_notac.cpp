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
  int N;
  cin >> N;
  if(N == 1) {
    int a;
    cin >> a;
    cout << a << endl;
    return 0;
  }
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  sort(vec.begin(), vec.end(), greater<int>{});
  printVec(vec);
  ll a = vec[0];
  ll b = vec[1];
  for(int i = 2; i < N; i++) {
    if(a <= b) {
      a += vec[i];
    } else {
      b += vec[i];
    }
  }
  cout << max(a,b) << endl;
}