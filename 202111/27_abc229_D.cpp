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
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

string S;
int K;
int N;
bool check(int mid) {  // mid以上連続させることができるか？
  if(N >= mid && K >= mid) return true;
  // 0~midまでの'.'の個数を出す
  int cnt_dot = 0;
  for(int i = 0; i < mid; i++) {
    if(S[i] == '.') cnt_dot++;
  }
  if(cnt_dot <= K) return true;
  int j = 0;
  for(int i = mid; i < N; i++) {
    if(S[i] == '.') cnt_dot++;
    if(S[j] == '.') cnt_dot--;
    if(cnt_dot <= K) return true;
    j++;
  }
  return false;
}

int main() {
  cin >> S;
  cin >> K;
  N = S.size();
  int left = 0;
  int right = N+1;
  while (left+1 < right) {
    int mid = (left+right)/2;
    if(check(mid)) left = mid;
    else right = mid;
  }
  cout << left << endl;
}