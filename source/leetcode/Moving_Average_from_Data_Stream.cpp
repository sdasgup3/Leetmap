/*
LeetCode 346 - Moving Average from Data Stream

http://www.bubufx.com/detail-1431945.html
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

#include<iostream>
#include<queue>
using namespace std;

class MovingAverage1 {

    private:
    vector<int> V;
    int posn, w, s;
    
    double average;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        V.reserve(size);
        posn = 0;
        average = 0;
        w = size;
        s = 0;
    }
    
    double next(int val) {
        
        if(s < w) {
            average = (average*s + val)/ (s +1);
            s++;
        } else {
            average = (average*s - V[posn] + val)/ (w);
            
        }
        V[posn] = val;
        posn  = (posn+1)%w;
        
        return average;
    }
};

class MovingAverage {

  private:
    int window;
    queue<int> Q;
    int sum;

  public:
    MovingAverage(int s) : window(s), sum(0) {}

    double next(int num) {

      if(0 == window) {
        return -1;
      }

      sum += num;
      Q.push(num);

      if(Q.size() > window) {
        sum -= Q.front();
        Q.pop();
      }
      return (double)sum / Q.size();
    }
};


int main ()
{
  MovingAverage *m = new MovingAverage(3);
  cout << m->next(1) << endl;
  cout << m->next(10) << endl; 
  cout << m->next(3) << endl;
  cout << m->next(5) << endl;

}
