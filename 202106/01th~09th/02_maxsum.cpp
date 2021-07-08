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

int memo[10100];
bool visited[10100];
vector<int> vec;
int N;

int f(int n) {
  if(n >= N || n < 0) return 0;
  if(visited[n]) return memo[n];
  visited[n] = true;
  return memo[n] = max(f(n-1), f(n-1)+vec[n]);
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  cout << f(N-1) << endl;
}