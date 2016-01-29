#include<iostream>
#include<cstring>
#include<algorithm>
#include"../utils.h"


void
merge(std::string str[], std::string s1[], int n1, std::string s2[], int n2) {
  int ptr1 = 0 , ptr2 = 0, ptr=0;

  while(ptr1 != n1 && ptr2 != n2) {
    if(s1[ptr1].compare(s2[ptr2]) < 0 ) {
      str[ptr++] = s1[ptr1++];
    } else {
      str[ptr++] = s2[ptr2++];
    }
  }

  if(ptr1 == n1) {
    while(ptr2 != n2) {
      str[ptr++] = s2[ptr2++];
    }
  }
  if(ptr2 == n2) {
    while(ptr1 != n1) {
      str[ptr++] = s1[ptr1++];
    }
  }
}

void
mergesort(std::string str[], int n) 
{
  if(1 == n) {
    return;
  }

  int n1 = n/2;
  int n2 = n - n1;
  std::string s1[n1];
  std::string s2[n2];

  for(int i = 0 ; i < n1; i ++) {
    s1[i]  = str[i];
  }
  for(int i = 0 ; i < n2; i ++) {
    s2[i]  = str[n1+i];
  }
  mergesort(s1, n1);
  mergesort(s2, n2);
  merge(str, s1, n1,s2,n2);
}


int main() {

  std::string str[] = {"123", "456", "789", "321", "654", "987", "231", "789"};
  int size = sizeof(str)/sizeof(str[0]);

  for(int i = 0 ; i < size; i++) {
    std::cout << str[i] << " ";
  }
  std::cout << " \n";

  mergesort(str, size);
  for(int i = 0 ; i < size; i++) {
    std::cout << str[i] << " ";
  }
  std::cout << " \n";

}
