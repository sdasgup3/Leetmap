/*
   *Problem
Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Example:

Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;

*Solution:
Optimizations: In this case a lot of redundant string are inswrted in the map whose
deadline is already expired. if those strings are referred then their deadlines will be updated.
But if not referred then, they will continue to clog the map
*Tags
Map
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Logger {
    private:
    unordered_map<string, int> M;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(0 == M.count(message)) {
            M[message] = timestamp;
            return true;
        } else {
            if(M[message] + 9 < timestamp) {
                M[message] = timestamp;
                return true;
            } else {
                return false;
            }
        }
    }
};


int main ()
{
  Logger *l = new Logger();

  cout << l->shouldPrintMessage(1, "foo") << endl; 
  cout << l->shouldPrintMessage(2, "bar") << endl; 
  cout << l->shouldPrintMessage(3, "foo") << endl; 
  cout << l->shouldPrintMessage(8, "bar") << endl; 
  cout << l->shouldPrintMessage(10, "foo") << endl; 
  cout << l->shouldPrintMessage(11, "foo") << endl; 
}
