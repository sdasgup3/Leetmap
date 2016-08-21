This page is about solving coding questions mostly asked in interviews.The problem/analysis/solutions mentioned in the post are categorized and can be used as a quick summary of useful algorithms. 


- [Array](http://codingpuzzle.blogspot.com/)
- [Hash Table](http://codingpuzzle.blogspot.com/)
- [Linked List](http://codingpuzzle.blogspot.com/)
- [Math](http://codingpuzzle.blogspot.com/search/label/Math)
- [Two Pointers](http://codingpuzzle.blogspot.com/)
- [String](http://codingpuzzle.blogspot.com/)
- [Divide and Conquer](http://codingpuzzle.blogspot.com/)
- [Binary Search](http://codingpuzzle.blogspot.com/search/label/binarytree)
- [Dynamic Programming](http://codingpuzzle.blogspot.com/)
- [Backtracking](http://codingpuzzle.blogspot.com/)
- [Stack](http://codingpuzzle.blogspot.com/)
- [Heap](http://codingpuzzle.blogspot.com/)
- [Greedy](http://codingpuzzle.blogspot.com/)
- [Sort](http://codingpuzzle.blogspot.com/)
- [Bit Manipulation](http://codingpuzzle.blogspot.com/)
- [Tree](http://codingpuzzle.blogspot.com/)
- [Depth-first Search](http://codingpuzzle.blogspot.com/)
- [Breadth-first Search](http://codingpuzzle.blogspot.com/)
- [Union Find](http://codingpuzzle.blogspot.com/)
- [Graph](http://codingpuzzle.blogspot.com/)
- [Design](http://codingpuzzle.blogspot.com/)
- [Topological Sort](http://codingpuzzle.blogspot.com/)
- [Trie](http://codingpuzzle.blogspot.com/)
- [Binary Indexed Tree](http://codingpuzzle.blogspot.com/)
- [Segment Tree](http://codingpuzzle.blogspot.com/)
- [Binary Search Tree](http://codingpuzzle.blogspot.com/)
- [Recursion](http://codingpuzzle.blogspot.com/)
- [Brainteaser](http://codingpuzzle.blogspot.com/)
- [Memoization](http://codingpuzzle.blogspot.com/)

### Cheatsheet
- Using ```std::vector```is too slow than static arrays.
```
vector<vector<bool>> table (n, vector<bool> (n, false)); //avoid using this
bool table[n][n];
memset(table,false,sizeof(table));
```
- ```std::stack``` access member functions
```
stack::pop()  //pop deletes but returns nothing 
stack::top(); // Use this sequesnce instead
statck::pop();
```

- ```std::queue```  access member functions

```
queue::front(), queue::back() // Access the front and back of the queue
queue::push(); // insert element at the back, i.e. after the element accessed by back
queue::pop();  //removes the front element as  accessed by front();

/* As before pop deletes but returns nothing, so to access the elemnt before deleting it
** do the following
*/
queue::front();
queue::pop();

```
- ```std::string``` member funstions
```
string::substr(start, length); //  Ex. s = "codingpuzzle, s.substr(0,6) gives "coding" 
string::compare(string s); // returns 0,-1,1 as strlen function
string::push_back(char);
string::append(int n, char c);// append n consecutive copies of c
string::append(string/const char*);
res = s[0] + to_string(len-2) + s[len-1]; // Is valid as there exist a string class friend operator '+' to handle each pair
                                          //(w.r.t left assocoativity)
For comparision: string.compare(string) or string == string  

  - Splitting based on a dilimiter
#include<sstream>
#include<iterator>
  istringstream buffer(str);
    istream_iterator<string> begin(buffer);
    istream_iterator<string> end;
    vector<string> V(begin, end);


```

- ```std::map``` member funstions
```
map::erase(key); 
```

- ```std::unordered_set<T>``` member funstions
```
unordered_set::insert(<T>)
unordered_set::count(<T>)
```
