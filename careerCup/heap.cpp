#include<iostream>
#include<vector>
#include<cmath>

void
swap(int* a, int*b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void
print(std::vector<int> &H) {
  for(int i = 0 ; i < H.size(); i++) {
    std::cout << H[i] << " " ; 
  }
  std::cout << "\n";
}
void
insert(std::vector<int> &H, int data) {
  H.push_back(data);

  int c = H.size()-1;
  int p = std::ceil((float)c/2) -1;

  while(true) {
    if(p == -1) {
      break;
    }
    if(H[p] > H[c]) {
      swap(&H[c], &H[p]);
      c = p;
      p = std::ceil((float)c/2) -1;
    } else {
      break;
    }
  }
}

void
heapify( std::vector<int> &H) {
  if(H.size() == 0 ) return;

  int p = 0;
  int c1 = 2*p+1;
  int c2 = 2*p+2;

  while(true) {
    if(c1 > H.size()-1 && c2 > H.size()-1) {
      break;
    }
    int c;
    if(c2 > H.size()-1) {
      c = c1;
    } else {
      if(H[c1] <= H[c2]) {
        c = c1;
      } else {
        c = c2;
      }
    }

    //std::cout  << H[c] << " \n";
    if(H[p] > H[c]) {
      swap(&H[p], &H[c]);
      p = c;
      c1 = 2*p+1;
      c2 = 2*p+2;
    } else {
      break;
    }
  }
}

int 
extract( std::vector<int> &H) {
  if(H.size() == 0) {
    return -1;
  }
  swap(&H[0],&H[H.size()-1]);
  int ret = H.back();
  H.pop_back();

  heapify(H);

  return ret;
}

int main() {
  std::vector<int> H;
  insert(H,10);
  insert(H,20);
  insert(H,30);
  insert(H,40);
  insert(H,15);
  insert(H,25);
  insert(H,35);
  insert(H,45);
  insert(H,24);
  insert(H,29);
  insert(H,37);
  insert(H,48);
  insert(H,32);
  insert(H,33);
  insert(H,39);
  insert(H,50);
  print(H);

  while(H.size()) {
    std::cout << extract(H) << " " ;
  }
  std::cout << "\n";

}
