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
  int n, x; cin >> n >> x;
  int count = 0;
  for(int i = 1; i < n-2; i++) {
    for(int j = i+1; j < n-1; j++) {
      int k = x - (i+j);
      if(k > j && k <= n) count++;
    }
  }
  cout << count << endl;
}