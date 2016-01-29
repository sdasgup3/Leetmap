/*
  there are several words in a file. Sort the words based on occurences.
  If more thsn one word is having the same occurence then sort it alphabetically
   */

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>

using namespace std;

void 
printvec(vector<pair<string, int> > v) {
  int len = v.size();

  for(int i = 0; i < len; i ++) {
    cout << v[i].first << ":" << v[i].second << "\n";
  }
  cout << "\n" ;
}


int partition(vector<pair<string, int> > &vec, int start, int end)
{
   int low = start;
   int high = end;
   pair<string, int> pivot = vec[start];

   while(low < high) {

    while(vec[low].second <= pivot.second && low <= end) {
      if(vec[low].second == pivot.second) {
        if(vec[low].first.compare(pivot.first) <= 0 ) {
          low++;
        } else {
          break;
        }
      } else {
        low ++;
      }
    }

    while(vec[high].second > pivot.second) {
      high --;
    }

    if(low < high) {
      pair<string, int> temp = vec[low];
      vec[low] = vec[high];
      vec[high] = temp;
    }
   }

   pair<string, int> temp = vec[high];
   vec[high] = pivot;
   vec[start] = temp;
   return high;

}

void 
sort(vector<pair<string, int> > &vec, int start, int end) {

  if(start <= end) {
    int pivot = partition(vec, start, end);
    sort(vec, start, pivot-1);
    sort(vec, pivot+1, end);
  }
}


int 
main() {
  ifstream fin("file2.txt");
  map<string, int> M;
  vector<pair<string, int> > arr;



  while(EOF != fin.peek()) {
    string str;
    fin >> str;
    M[str]++;
    cout << str << endl;
  }

  map<string, int>::iterator itb = M.begin();
  map<string, int>::iterator ite = M.end();

  for(; itb != ite; itb++) {
    arr.push_back(*itb);
  }

  sort(arr, 0 , arr.size()-1);
  printvec(arr);


  return 0;
}
