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

bool done[1000];
int memo[1000];

int fib(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(done[n]) return memo[n];
  int res = memo[n-1] + memo[n-2];
  done[n] = true;
  return memo[n] = res;
}

int main() {
  int N;
  cin >> N;
  cout << fib(N) << endl;
}