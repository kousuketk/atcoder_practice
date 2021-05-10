#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> vec(N, vector<int>(5));
  for(int i = 0; i < N; i++) {
    cin >> vec.at(i).at(0) >> vec.at(i).at(1) >> vec.at(i).at(2) 
        >> vec.at(i).at(3) >> vec.at(i).at(4);
  }
  int max_val = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      for(int k = j+1; k < N; k++) {
        int one = max({ vec.at(i).at(0), vec.at(j).at(0), vec.at(k).at(0)});
        int two = max({ vec.at(i).at(1), vec.at(j).at(1), vec.at(k).at(1)});
        int three = max({ vec.at(i).at(2), vec.at(j).at(2), vec.at(k).at(2)});
        int four = max({ vec.at(i).at(3), vec.at(j).at(3), vec.at(k).at(3)});
        int five = max({ vec.at(i).at(4), vec.at(j).at(4), vec.at(k).at(4)});
        int tmp = min({one, two, three, four, five});
        if(max_val < tmp) {
          max_val = tmp;
        }
      }
    }
  }
  cout << max_val << endl;
}