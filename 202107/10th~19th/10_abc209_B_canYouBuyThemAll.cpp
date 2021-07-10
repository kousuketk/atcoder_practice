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
  int N, X; cin >> N >> X;
  int sum = 0;
  rep(i,N) {
    int tmp;
    cin >> tmp;
    if(i % 2 == 1) {
      sum += tmp-1;
    } else {
      sum += tmp;
    }
  }
  if(sum <= X) cout << "Yes" << endl;
  else cout << "No" << endl;
}