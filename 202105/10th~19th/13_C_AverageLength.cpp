#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> vec(N, vector<int>(2));
  vector<int> nums(N);
  for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    vec.at(i).at(0) = x;
    vec.at(i).at(1) = y;
    nums.at(i) = i;
  }
  double len = 0;
  int count = 0;
  do {
    for(int i = 0; i < N-1; i++) {
      int x1 = vec.at(nums.at(i)).at(0);
      int y1 = vec.at(nums.at(i)).at(1);
      int x2 = vec.at(nums.at(i+1)).at(0);
      int y2 = vec.at(nums.at(i+1)).at(1);
      
      len += sqrtf(pow((x1-x2), 2.0) + pow((y1-y2), 2.0));
    }
    count++;
  } while (next_permutation(nums.begin(), nums.end()));
  cout << fixed << setprecision(7) << len/count << endl;
}