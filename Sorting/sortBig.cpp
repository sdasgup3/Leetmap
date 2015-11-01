#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>


void
readnext(std::ifstream  &in, std::vector<int> &V) {
  int i = 0, data;
  while(EOF != in.peek() && i < 500) {
    in >> data;
    V.push_back(data);
    i++;
  }
}

void
dumpfile(std::ofstream &out, std::ifstream &in) {
  int data;
  while(in.peek() != EOF) {
    in >> data;
    out << data;
  }
}

void
dumpvector(std::ofstream &out, std::vector<int> V) {
  int data;

  for(int k = 0 ; k < V.size(); k++) {
    out << V[k];
  }
}
void
merge(std::ofstream &out, std::ifstream  &in1, std::ifstream  &in2) {
  std::vector<int> V1;
  std::vector<int> V2;
  std::vector<int> V;

  readnext(in1, V1);
  readnext(in2, V2);


  int ptr1 = 0, ptr2 = 0;
  while(true) {
    if(ptr1 == V1.size()) {  
      V1.clear();
      ptr1 = 0;
      readnext(in1, V1);
      if(0 == V1.size()) {
        dumpvector(out, V2);
        dumpfile(out, in2);
        break;
      }
    }

    if(ptr2 == V2.size()) {  
      V2.clear();
      ptr2 = 0;
      readnext(in2, V2);
      if(0 == V2.size()) {
        dumpvector(out, V1);
        dumpfile(out, in1);
        break;
      }
    }

    if(ptr1 <  V1.size() && ptr2 < V2.size()) {
      if(V1[ptr1] <= V2[ptr2]) {
        V.push_back(V1[ptr1]);
        ptr1++;
      } else {
        V.push_back(V2[ptr2]);
        ptr2++;
      }

      if(V.size() == 500) {
        for(int k = 0 ; k < V.size(); k++) {
          out << V[k] << "\n";
        }
        V.clear();
      }
    }
  }
}


int main()
{
  std::ifstream file("textfile.txt");
  std::ofstream out1("out_1.txt");
  std::ofstream out2("out_2.txt");

  if(file.is_open() == false ||
      out1.is_open() == false || out2.is_open() == false) {
    return 1;
  }

  std::vector<int> V;

  int i = 0, data;
  while(EOF != file.peek() && i < 1000) {
    file >> data;
    V.push_back(data);
    i++;
  }

  std::sort(V.begin(), V.end());
  for(int k = 0 ; k < V.size(); k++) {
    out1 << V[k] << "\n";
  }
  V.clear();

  i = 0;
  while(EOF != file.peek() && i < 1000) {
    file >> data;
    V.push_back(data);
    i++;
  }
  std::sort(V.begin(), V.end());
  for(int k = 0 ; k < V.size(); k++) {
    out2 << V[k] << "\n";
  }
  V.clear();

  file.close();
  out1.close();
  out2.close();


  std::ifstream in1("out_1.txt");
  std::ifstream in2("out_2.txt");
  std::ofstream out("out.txt");
  merge(out, in1, in2);

  in1.close();
  in2.close();
  out.close();


}
