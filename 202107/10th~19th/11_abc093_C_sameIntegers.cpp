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
  vector<int> vec(3);
  rep(i,3) cin >> vec[i];
  sort(vec.begin(), vec.end());
  int count = 0;
  // まず差を1以下にする
  if(vec[2] - vec[0] >= 2) {
    int tmp = (vec[2]-vec[0])/2;
    count += tmp;
    vec[0] += 2*tmp;
  }
  if(vec[2] - vec[1] >= 2) {
    int tmp = (vec[2]-vec[1])/2;
    count += tmp;
    vec[1] += 2*tmp;
  }
  // ループで合わせてく
  while(true){
    sort(vec.begin(), vec.end());
    if(vec[0] == vec[2]) break;
    vec[0] += 1;
    vec[1] += 1;
    count++;
  }
  cout << count << endl;
}