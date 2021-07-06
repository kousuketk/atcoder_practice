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
  int a, b, c; cin >> a >> b >> c;
  int x; cin >> x;
  ll count = 0;
  for(int i = 0; i <= a; i++) {
    for(int j = 0; j <= b; j++) {
      for(int k = 0; k <= c; k++) {
        int sum = i*500 + j*100 + k*50;
        if(sum == x) count++;
      }
    }
  }
  cout << count << endl;
}