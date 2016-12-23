/* 
 * Problem Description
 Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
 * Solution
 store the elements in a queue
 so that when the window size is reached, then we can have the least frequent element detected in O(1) time 
 * Tags
 Queue
*/

#include"header.h"
class MovingAverage {
  private:
    int window, count;
    double sum;
    queue<int> Q;

public:
  MovingAverage(int w) {  
    window = w;
    count =  0;
    sum = 0.0;
  }

  double next(int n) {
    if(0 == window) {
      return 0;
    }

    Q.push(n);
    if(count != window) {
      count++;
      sum += n;
    } else {
      sum -= Q.front();
      Q.pop();
      sum += n;
    }
    return sum / count;
  }
private:

};


int main() {
  MovingAverage m = MovingAverage(3);
cout << m.next(1) << "\n";
cout << m.next(10) << "\n";
cout << m.next(3) << "\n";
cout << m.next(5) << "\n";


  return 0;
}
