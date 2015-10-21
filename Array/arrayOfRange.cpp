#include<iostream>
#include<vector>


bool
operator<=(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.first <= b.first;
}

bool
operator<(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.first < b.first;
}

bool
operator>(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.first > b.first;
}

void
swap(std::pair<int, int> &a, std::pair<int, int> &b)
{
  std::pair<int, int> temp = a;
  a = b;
  b= temp;
}

int partition(std::vector<std::pair<int, int>> &v, int start, int end)
{
  std::pair<int, int> pivot = v[start];
  int first = start;
  int last = end;

  while(first < last) {
    while(v[last] > pivot && last >= 0) {// last >= 0 is redun 
      last --;
    }
    while(v[first] <= pivot && first <= end) {
      first++;
    }

    if(first < last) {
      swap(v[first], v[last]);
    }
  }
  swap(v[last], v[start]);
  return last;
}

void
Qsort(std::vector<std::pair<int, int>> &v, int start, int end )
{
  int len = end - start + 1;

  if(len > 1) {
    int q = partition(v, start, end);
    Qsort(v, start, q-1);
    Qsort(v, q+1, end);
  }
}

int main()
{
  std::vector<std::pair<int, int>> v;
  /*
  v.push_back(std::pair<int, int>(7,21));
  v.push_back(std::pair<int, int>(20,21));
  v.push_back(std::pair<int, int>(3,5));
  v.push_back(std::pair<int, int>(2,6));
  */
  v.push_back(std::pair<int, int>(15,20));
  v.push_back(std::pair<int, int>(11,15));
  v.push_back(std::pair<int, int>(9,10));
  v.push_back(std::pair<int, int>(4,10));
  v.push_back(std::pair<int, int>(3,8));
  v.push_back(std::pair<int, int>(2,5));
  v.push_back(std::pair<int, int>(4,20));
  v.push_back(std::pair<int, int>(2,20));

  Qsort(v, 0, v.size()-1);

  for(int  i = 0 ; i < v.size(); i++) {
    std::cout<< " (" <<v[i].first << " "<< v[i].second << ") " ;
  }
  std::cout<< "\n";

  std::vector<std::pair<int, int>> res;
  res.push_back(v[0]);
  for(int  i = 1 ; i < v.size(); i++) {
    int j;
    for( j = 0; j < res.size(); j++) {
      if(v[i].first == res[j].first && v[i].second > res[j].second ) {
        res[j] = v[i];
        break;
      }
      if(v[i].second <= res[j].second) {
        break;
      }
    }
    if(j == res.size()) {
      res.push_back(v[i]);
    }
  }

  for(int  i = 0 ; i < res.size(); i++) {
    std::cout<< " (" <<res[i].first << " "<< res[i].second << ") " ;
  }
  std::cout<< "\n";
  return 0;
}
