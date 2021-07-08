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
  int N, Y; cin >> N >> Y;
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= (N-i); j++) {
      // i, j, (N-i-j)
      ll sum = 10000*i + 5000*j + 1000*(N-i-j);
      if(sum == Y) {
        cout << i << " " << j << " " << (N-i-j) << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}