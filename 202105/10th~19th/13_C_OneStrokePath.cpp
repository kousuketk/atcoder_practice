#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using Graph = vector<vector<int>>;

void printVec(vector<int> &vec) {
  cout << "";
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    cout << *itr << " "; 
  }
  cout << endl;
}

int main() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);
  }
  vector<int> nums(N);
  rep(i, N) nums.at(i) = i;
  int count = 0;
  do {
    if(nums.at(0) != 0) continue;
    bool flag = false;
    for(int i = 0; i < N-1; i++) {
      flag = false;
      for(int nv: G[nums.at(i)]) {
        if(nums.at(i+1) == nv) flag = true;
      }
      if(!flag) break;
    }
    if(flag) {
      count++;
    }
  } while (next_permutation(nums.begin(), nums.end()));
  cout << count << endl;
}