#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
#define N 10


int main()
{
  typedef std::unordered_map<long int, std::vector<std::pair<int, int>>> MAP;

  MAP m;
  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < N ; j++) {
      long int k = std::pow(i,3) + std::pow(j,3);
      std::vector<std::pair<int, int>> &v = m[k];
      v.push_back(std::pair<int, int>(i,j));
    }
  }

  MAP::iterator iS = m.begin();
  MAP::iterator iE = m.end();
  for( ; iS != iE  ; iS++) {
    std::vector<std::pair<int, int>> &v = (*iS).second;
    if(v.size() > 1) {
      for(int k = 0; k < v.size(); k++) {
        std::cout << " ( "<< v[k].first << ", " << v[k].second << " ) ";
      }
      std::cout << "\n";
    }
  }
}
