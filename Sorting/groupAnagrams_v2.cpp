#include<iostream>
#include<cstring>
#include<algorithm>
#include"../utils.h"


int compareStr(std::string a, std::string b) {
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return strcmp(a.c_str(), b.c_str());
}

int partition(std::string str[], std::vector<int> &index, int start, int end) {
  int low = start;
  int high = end;
  std::string pivot = str[start];

  while(low <= high) {
    while(low <= end && compareStr(str[low],pivot) <= 0) {
      low ++;
    }
    while(high >= 0 && compareStr(str[high],pivot) > 0) {
      high --;
    }

    if(low  < high) {
      swap<std::string>(&str[low], &str[high]);
      swap<int>(&index[low], &index[high]);
    }
  }

  swap<std::string>(&str[start], &str[high]);
  swap<int>(&index[start], &index[high]);
  return high;
}

void
Qsort(std::string str[], std::vector<int > &index,  int start, int end) {
  if(start >= end) {
    return;
  }
  int q = partition(str, index, start, end);
  Qsort(str, index, start, q-1);
  Qsort(str, index, q+1, end);
}


void
groupAnagrams(std::string str[], int n) {
  std::vector<int> index(n);
  std::vector<std::string> V;

  for(int i = 0 ; i < n ;  i++) {
    V.push_back(str[i]);
  }

  for(int i = 0 ; i < n ;  i++) {
    std::sort(str[i].begin(), str[i].end());
    index[i] = i;
  }
  Qsort(str, index, 0, n-1);
  for(int i = 0 ; i < n; i++) {
    std::cout << V[index[i]] << " ";
  }
}

int main() {

  std::string str[] = {"123", "456", "789", "321", "654", "987", "231", "789"};
  int size = sizeof(str)/sizeof(str[0]);

  for(int i = 0 ; i < size; i++) {
    std::cout << str[i] << " ";
  }
  std::cout << " \n";

  groupAnagrams(str, size);

}
