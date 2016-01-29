#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

bool lastKLines(string fileName, int k)
{
  ifstream file(fileName.c_str());
  if(false == file.is_open()) {
    return false;
  }

  string A[k];
  int size = 0;

  while(EOF != file.peek()) {
    getline(file, A[size%k]);
    size = size+1;
  }

  int start, entries;
  if(size <= k) {
    start = 0;
    entries = size;
  } else {
    start = (size)%k;
    entries = k;
  }

  for(int i = 0 ; i < entries; i++) {
    cout << A[start%k] << "\n";
    start++;
  }
}


int main(int argc, char** argv)
{
  int k = atoi(argv[1]);
  string S("input.txt");
  lastKLines(S, k);

  return 0;
}
