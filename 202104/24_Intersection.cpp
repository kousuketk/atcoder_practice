#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for(int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  
  vector<int> result_vec;
  for(int i = A.at(0); i <= B.at(0); i++) {
    result_vec.push_back(i);
  }
  for(int i = 1; i < N; i++) {
    vector<int> tmp_vec;
    vector<int> intersection;
    for(int j = A.at(i); j <= B.at(i); j++) {
      tmp_vec.push_back(j);
    }
    set_intersection(result_vec.begin(), result_vec.end(), tmp_vec.begin(), tmp_vec.end(), back_inserter(intersection));
    result_vec = intersection;
  }
  cout << result_vec.size() << endl;
}