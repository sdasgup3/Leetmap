This page is about solving coding questions mostly asked in interviews.The problem/analysis/solutions mentioned in the post are categorized and can be used as a quick summary of useful algorithms. 


- [Array]()
- [Hash Table]()
- [Linked List]()
- [Math]()
- [Two Pointers]()
- [String]()
- [Divide and Conquer]()
- [Binary Search](http://codingpuzzle.blogspot.com/search/label/binarytree)
- [Dynamic Programming]()
- [Backtracking]()
- [Stack]()
- [Heap]()
- [Greedy]()
- [Sort]()
- [Bit Manipulation]()
- [Tree]()
- [Depth-first Search]()
- [Breadth-first Search]()
- [Union Find]()
- [Graph]()
- [Design]()
- [Topological Sort]()
- [Trie]()
- [Binary Indexed Tree]()
- [Segment Tree]()
- [Binary Search Tree]()
- [Recursion]()
- [Brainteaser]()
- [Memoization]()

### Cheatsheet
- Using std::vectoris too slow than static arrays.
```
vector<vector<bool>> table (n, vector<bool> (n, false)); //avoid using this
bool table[n][n];
memset(table,false,sizeof(table));
```
- std::stack access member functions
```
stack::pop()  //pop deletes but returns nothing 
stack::top(); // Use this sequesnce instead
statck::pop();
```

- std::queue access member functions

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
- std::string member funstions
```
string::substr(start, length); //  Ex. s = "codingpuzzle, s.substr(0,6) gives "coding" 
```
```
