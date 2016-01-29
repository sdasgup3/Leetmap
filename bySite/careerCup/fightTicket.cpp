#include<iostream>
#include<vector>
#include<map>


void
findItenary(std::vector<std::pair<int, int>> &Passes,int &start, int &dest){

  std::map<int, int> M;

  for(int i = 0 ; i < Passes.size(); i++) {

    M[Passes[i].first] -= 1; 
    M[Passes[i].second] += 1; 
  }

  std::map<int, int>::iterator IS = M.begin();
  std::map<int, int>::iterator IE = M.end();

  int both_as_src_dest = 0 ;
  for(; IS != IE; IS++) {
    if((*IS).second < 0 ) {
      start = (*IS).first;
    } else if((*IS).second > 0) {
      dest = (*IS).first;
    } else {
      both_as_src_dest++;
    }
  }
  if(both_as_src_dest == M.size()) {
    std::cerr << "Cycle Detected\n";
  }

}

int main()
{

  std::vector<std::pair<int, int>> Passes;
  int start, dest;

  Passes.push_back(std::pair<int, int> (3,4));
  Passes.push_back(std::pair<int, int> (3,7));
  Passes.push_back(std::pair<int, int> (4,5));
  Passes.push_back(std::pair<int, int> (2,3));
  Passes.push_back(std::pair<int, int> (1,2));
  Passes.push_back(std::pair<int, int> (5,3));
  findItenary(Passes, start, dest);
  std::cout << "Start : " << start << " " << "End : " << dest << "\n";

  Passes.clear();
  Passes.push_back(std::pair<int, int> (4,5));
  Passes.push_back(std::pair<int, int> (3,4));
  Passes.push_back(std::pair<int, int> (2,3));
  Passes.push_back(std::pair<int, int> (2,3));
  Passes.push_back(std::pair<int, int> (1,2));
  Passes.push_back(std::pair<int, int> (3,6));
  Passes.push_back(std::pair<int, int> (6,2));
  findItenary(Passes, start, dest);
  std::cout << "Start : " << start << " " << "End : " << dest << "\n";
}
