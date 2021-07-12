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
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  sort(vec.begin(), vec.end());
  int count = 0;
  int i = 0;
  while(i < N) {
    // (upper_bound - lower_bound)が奇数→+1, 偶数→0
    auto itr_low = lower_bound(ALL(vec), vec[i]);
    auto itr_upper = upper_bound(ALL(vec), vec[i]);
    if((itr_upper - itr_low) % 2 == 1) count++;
    i += itr_upper - itr_low;
  }
  cout << count << endl;
}