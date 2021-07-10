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
  int flag = 0;
  int count = 0;
  for(int i = 1; i < N; i++) {
    if(vec[i-1] == vec[i]) continue;
    if(flag == 0) {
      if(vec[i-1] < vec[i]) flag = 1;
      else flag = 2;
    } else if(flag == 1) {
      if(vec[i-1] > vec[i]) {
        // 単調非減少のときに、減少したときはcount++して, flag=0
        count++;
        flag = 0;
      } 
    } else if(flag == 2) {
      if(vec[i-1] < vec[i]) {
        // 非増加のときに、増加したときはcount++して, flag=0
        count++;
        flag = 0;
      }
    }
  }
  cout << count+1 << endl;
}