#include<iostream>
#include<fstream>

bool lastKLines(std::string fileName, int k)
{
  std::ifstream file(fileName.c_str());
  if(false == file.is_open()) {
    return false;
  }

  std::string A[k];
  int size = 0;

  while(EOF != file.peek()) {
    std::getline(file, A[size%k]);
    size = (size + 1);
  }


  int start  = size > k ? size %k : 0;
  int count = std::min(k,size);

  for(int i = 0; i <  count; i ++) {
    std::cout << A[start] << std::endl;
    start = (start +1)%k;
  }

  return true;
}


int main(int argc, char** argv)
{
  int k = atoi(argv[1]);
  std::string S("input.txt");
  lastKLines(S, k);

  return 0;
}
