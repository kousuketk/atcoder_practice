#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int M, N;
  cin >> M;
  vector<vector<int>> vec_m(M - 1, vector<int>(2));
  int mx, my;
  cin >> mx >> my;
  for(int i = 0; i < M-1; i++) {
    int x, y;
    cin >> x >> y;
    x -= mx;
    y -= my;
    vec_m.at(i).at(0) = x;
    vec_m.at(i).at(1) = y;
  }
  cin >> N;
  vector<vector<int>> vec_n(N, vector<int>(2));
  for(int i = 0; i < N; i++) {
    cin >> vec_n.at(i).at(0);
    cin >> vec_n.at(i).at(1);
  }
  // vec_nのそれぞれに対して(for, n)、それぞれの星がvec_mに対応するか調べる(for, n)
  for(int i = 0; i < N; i++) {
    int nx = vec_n.at(i).at(0);
    int ny = vec_n.at(i).at(1);
    vector<vector<int>> vec_tmp(N-1, vector<int>(2));
    for(int j = 0; j < N; j++) {
      if(j=i) {
        continue;
      }
      vec_tmp.at(j).at(0) = vec_n.at(j).at(0) - nx;
      vec_tmp.at(j).at(1) = vec_n.at(j).at(1) - ny;
    }
    // それぞれに対してのvec_tmpが完成した。
    // vec_mのx,yが全て、vec_tmpに入っていれば。nx-mx, ny-myを返す。
    for(int j = 0; j < M-1; j++) {
      int x, y;
      x = vec_m.at(i).at(0);
      y = vec_m.at(i).at(1);
      for(int k = 0; k < N-1; k++) {

      }
    }
  }





  vector<int> A(N);
  vector<int> B(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  long long sum = 0;
  for(int i = 0; i < N; i++) {
    sum += abs(A.at(i) - B.at(i));
    sum += abs(A.at(i) - A.at(N >> 1));
    sum += abs(B.at(i) - B.at(N >> 1));
  }
  cout << sum << endl;
}