#include<iostream>
#include<cstring>
#include"../utils.h"


int 
search(std::string arr[], int size, std::string k) {

  int start = 0;
  int end = size-1;

  while(start <= end) {
    int mid = (start + end)/2;


    if(arr[mid] == "" ) { //Mid correction
      int left = mid-1;
      int right = mid+1;
      while(true) {
        if(left >= start) {
          if(0 == arr[left].compare("")) {
            left --;
          } else {
            mid = left;
            break;
          }
        }
        if(right <= end) {
          if(0 == arr[right].compare("")) {
            right ++;
          } else {
            mid = right;
            break;
          }
        }

        if(left < start && right > end) {
          return -1;
        }
      }
    }

    if(0==arr[mid].compare(k)) {
      return mid;
    } else if(arr[mid].compare(k) < 0 ) {
      start= mid+1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}


int main()
{
  std::string arr[] = {"at", "", "", "", "ball", "", "", "", "cat", "", "", "dad", "", ""};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  for(int i = 0; i < size ; i++) {
    if(arr[i].compare("") == 0 ) {
      continue;
    }
    std:: cout << arr[i] << " " << search(arr, size, arr[i]) << "\n";
  }

    std:: cout << "za" << " " << search(arr, size, "za") << "\n";
    std:: cout << "aa" << " " << search(arr, size, "aa") << "\n";
}
