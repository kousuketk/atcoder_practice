#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> vec(N, vector<int>(5));
  vector<vector<int>> vec_reverse(5, vector<int>(N));
  for(int i = 0; i < N; i++) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    vec.at(i).at(0) = a;
    vec.at(i).at(1) = b;
    vec.at(i).at(2) = c;
    vec.at(i).at(3) = d;
    vec.at(i).at(4) = e;
    vec_reverse.at(0).at(i) = a;
    vec_reverse.at(1).at(i) = b;
    vec_reverse.at(2).at(i) = c;
    vec_reverse.at(3).at(i) = d;
    vec_reverse.at(4).at(i) = e;
  }

  vector<int> vec_person;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 3; j++) {
      int max_val = *max_element(vec_reverse.at(i).begin(), vec_reverse.at(i).end());
      auto itr = find(vec_reverse.at(i).begin(), vec_reverse.at(i).end(), max_val);
      int tmp = itr;
      vec_person.push_back(tmp);
      vec_reverse.at(i).erase(itr, itr+1);
    }
  }
  sort(vec_person.begin(), vec_person.end());
  vec_person.erase(unique(vec_person.begin(), vec_person.end()), vec_person.end());

  // vec_personの配列のvec_person.at(i)の順番に対してのみ全探索
  int max_val = 0;
  for(int i = 0; i < vec_person.size(); i++) {
    for(int j = i+1; j < vec_person.size(); j++) {
      for(int k = j+1; k < vec_person.size(); k++) {
        int one = max({ vec.at(vec_person(i)).at(0), vec.at(vec_person(j)).at(0), vec.at(vec_person(k)).at(0)});
        int two = max({ vec.at(vec_person(i)).at(1), vec.at(vec_person(j)).at(1), vec.at(vec_person(k)).at(1)});
        int three = max({ vec.at(vec_person(i)).at(2), vec.at(vec_person(j)).at(2), vec.at(vec_person(k)).at(2)});
        int four = max({ vec.at(vec_person(i)).at(3), vec.at(vec_person(j)).at(3), vec.at(vec_person(k)).at(3)});
        int five = max({ vec.at(vec_person(i)).at(4), vec.at(vec_person(j)).at(4), vec.at(vec_person(k)).at(4)});
        int tmp = min({one, two, three, four, five});
        if(max_val < tmp) {
          max_val = tmp;
        }
      }
    }
  }
  cout << max_val << endl;
}