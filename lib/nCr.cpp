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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
void comb(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

// aCbを前処理O(N^2), クエリO(1)で答える
int main() {
  // int L; cin >> L;
  // L -= 12;

  // int a = 12-1+L;
  // int b = 11;
  int a, b; cin >> a >> b;
  vector<vector<ll>> v(a+1, vector<ll>(a+1, 0));
  comb(v);
  cout << v[a][b] << endl;
  // v[a][b]でaCbを取得できる
}