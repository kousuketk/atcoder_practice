#include <iostream>
#include <cmath>
#include <limits>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<vector<int>> route_vec(N, vector<int>(2));
  for(int i = 0; i < N; i++) {
    cin >> route_vec.at(i).at(0) >> route_vec.at(i).at(1);
  }

  vector<int> A(N);
  for(int i = 0; i < N; i++) A.at(i) = i;
  long double all_route_len = 0;
  long double count = 0;
  do {
    long double one_route_len = 0;
    for(int i = 0; i < N-1; i++) {
      one_route_len += sqrt(
        pow(route_vec.at(A.at(i)).at(0) - route_vec.at(A.at(i+1)).at(0), 2) + 
        pow(route_vec.at(A.at(i)).at(1) - route_vec.at(A.at(i+1)).at(1), 2)
      );
    }
    all_route_len += one_route_len;
    count += 1;
  } while(next_permutation(A.begin(), A.end()));
  cout << fixed << setprecision(10) << all_route_len/count << endl;
  return 0;
}