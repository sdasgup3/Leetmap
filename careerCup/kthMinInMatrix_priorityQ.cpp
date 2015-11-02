#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

class node {
  public:
    node(int a, int b, int v):r(a), c(b), value(v) {}
  int  r;
  int c;
  int value;
};

void
print(std::vector<node> &H) {
  for(int i = 0 ; i < H.size(); i++) {
    std::cout << H[i].value << " " ; 
  }
  std::cout << "\n";
}

bool
operator<(const node &a, const node &b) {
  return a.value > b.value;
}

int
kthMin(std::priority_queue<node> &H, int arr[4][5], int r, int c, int k) {
  for(int i = 0 ; i < r; i++) {
    node *n = new node(i,0,arr[i][0]);
    H.push(*n);
  }

  int counter = 0;
  while(H.size()) {
    node p = H.top();
    H.pop();
    counter ++;
    std::cout << p.value << "\n";
    if(counter == k) {
      return p.value;
    }

    if((p.c + 1) < c) {
      node *n = new node(p.r, p.c+1, arr[p.r][p.c +1]);
      H.push(*n);
    }
  }

  if(H.size() == 0) {
    return -1;
  }
}

int main() {
  std::priority_queue<node> H;
  int r= 4;int c =5;
  int arr[4][5] = {
    {10, 20, 30, 40 , 60},
    {15, 25, 35, 45,  65},
    {24, 29, 37, 48,  68},
    {32, 33, 39, 50,  70}
  };

  int k = r*c;;
  std::cout << "kth min : " << kthMin(H, arr,  r,  c, k);

}





