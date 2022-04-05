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

int N;
long long A, B;
vector<long long> vec;
bool check(long long x) {
  vector<long long> tmp_vec(N);
  rep(i,N) tmp_vec[i] = vec[i] - x*B;
  ll a = A-B;
  ll cnt = 0;
  rep(i,N) {
    if(tmp_vec[i] > 0) cnt += ceil((double)tmp_vec[i]/(double)a);
  }
  return cnt <= x;
}

int main() {
  cin >> N;
  cin >> A >> B;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  long long ng = 0;
  long long ok = 1000000100;
  while(ng+1 < ok) {
    long long mid = (ng+ok)/2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}