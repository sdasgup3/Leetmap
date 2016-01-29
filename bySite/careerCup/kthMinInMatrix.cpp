#include<iostream>
#include<vector>
#include<cmath>

template<class node>
void
swap(node* a, node*b) {
  node temp = *a;
  *a = *b;
  *b = temp;
}

class node {
  public:
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
operator>(node a, node b) {
  return a.value > b.value;
}
bool
operator<=(node a, node b) {
  return a.value <= b.value;
}

template <class node>
void
insert(std::vector<node> &H, node data) {
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

template <class node>
void
heapify( std::vector<node> &H) {
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
      if((H[c1]) <= (H[c2])) {
        c = c1;
      } else {
        c = c2;
      }
    }

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

template <class node>
node 
extract( std::vector<node> &H) {
  swap(&H[0],&H[H.size()-1]);
  node ret = H.back();
  H.pop_back();

  heapify(H);

  return ret;
}

int
kthMin(std::vector<node> &H, int arr[4][5], int r, int c, int k) {
  for(int i = 0 ; i < r; i++) {
    node n = {i,0,arr[i][0]};
    insert(H, n);
  }

  int counter = 0;
  while(H.size()) {
    node p = extract(H);
    counter ++;
    std::cout << p.value << "\n";
    if(counter == k) {
      return p.value;
    }

    if((p.c + 1) < c) {
      node n = {p.r, p.c+1, arr[p.r][p.c +1]};
      insert(H,n);
    }
  }

  if(H.size() == 0) {
    return -1;
  }
}

int main() {
  std::vector<node> H;
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





