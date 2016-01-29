#include<iostream>
#include<map>

using namespace std;


int main() {

  map<string, int> M;
  string str;

  while(getline(cin, str)) {
    M[str]++;
  }

  map<string, int>::iterator itb = M.begin();
  map<string, int>::iterator ite = M.end();

  for(; itb != ite; itb++) {
    cout << (*itb).first << "\n";
  }

}

