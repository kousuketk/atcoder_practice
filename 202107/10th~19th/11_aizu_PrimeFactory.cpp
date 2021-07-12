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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N; cin >> N;
  vector<int> vec;
  int tmp_N = N;
  for(int i = 2; i*i <= N; i++) {
    while(tmp_N % i == 0) {
      vec.push_back(i);
      tmp_N = tmp_N/i;
    }
  }
  if(N != 1) vec.push_back(N);
  printVec(vec);
}