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

int memo[10000];
bool visited[10000];

int fib(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(visited[n]) return memo[n];
  return memo[n] = fib(n-1) + fib(n-2);
}

int main() {
  int N;
  cin >> N;
  cout << fib(N) << endl;
}