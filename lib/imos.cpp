#include <iostream>
#include <vector>

std::vector<int> getCumSum(std::vector<int> baseImos){
  int baseSize = baseImos.size();
  std::vector<int> cumSum(baseSize, 0);
  
  cumSum[0] = baseImos[0];
  for(int i=1; i<baseSize; ++i){
    cumSum[i] = cumSum[i-1] + baseImos[i];
  }
  return cumSum;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  
  int w = 10;
  int n, blockPos, len;
  std::cin >> n;
  std::vector<int> base(w+1, 0);
  for(int i=0; i<n; ++i){
    std::cin >> blockPos >> len;
    ++base[blockPos];
    --base[blockPos+len];
  }
  
  std::vector<int> depth(getCumSum(base));
  for(int i=0; i<w; ++i){
    std::cout << depth[i] << " ";
  }
  std::cout << "\n";
  return 0;
}