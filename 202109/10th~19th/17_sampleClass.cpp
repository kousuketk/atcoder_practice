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

class Car {
  public:
    int r;
    int g;
    int b;
  
  int Sum() {
    return r+g+b;
  }
};

int main() {
  Car c;
  c.r = 500;
  c.g = 20;
  c.b = 30;
  int sum = c.Sum();
  cout << sum << endl;
}

// g++ -o a contests/A.cpp
// ./a