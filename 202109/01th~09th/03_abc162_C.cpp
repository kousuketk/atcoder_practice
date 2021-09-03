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

int gcd(int x,int y){
  if(x<y) swap(x,y);
  //xの方が常に大きい
  int r;
  while(y>0){
    r=x%y;
    x=y;
    y=r;
  }
  return x;
}

int main() {
  int N; cin >> N;
  ll ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = 1; k <= N; k++) {
        int tmp = gcd(i,j);
        ans += gcd(tmp,k);
      }
    }
  }
  cout << ans << endl;
}