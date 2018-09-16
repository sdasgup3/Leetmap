### 296. Best Meeting Point
Find median of a 2D grid  = (median of rows, median of colms )

### 453. Minimum Moves to Equal Array Elements
arr[] = [1,2,3]
find min numberof moves "incr all except one" to make all elemens equal

incr all execpt one == (A)decr the one that you dnt want to incr and then (B)incr all

123 -->  (A) 122 + (B) 233 --> (A)232 + (B)343 -> (A)333 + (B)444 

number of moves == (A) + (B) == (A) == number of moves to decr one 

to make all equal all the numbers need to be decr to the min of all of them

### 462. Minimum Moves to Equal Array Elements II
Now u have +1 and -1 as moves for any element applying one at a time
Idea is to find the median

## Union Find

A union–find data structure or merge–find set, is a data structure that keeps
track of a set of elements partitioned into a number of disjoint
(nonoverlapping) subsets. It supports following useful operations:
```
 function MakeSet(x)
     x.parent := x
 function Find(x)
     if x.parent == x
        return x
     else
        return Find(x.parent)
 function Union(x, y)
     xRoot := Find(x)
     yRoot := Find(y)
     xRoot.parent := yRoot
```
Note that in the initial set is on size n, each union reduces the set size by -1
so after m union operations, the final number of sets = n  - m

### 323. Number of Connected Components in an Undirected Graph
```
n = 5
E = 
     0\          3
     | \         |
     1 -2        4
```
E = [(0-1)(2-1)(2-1)(3-4)]

MakeSet(x) = x
         0 1 2 3 4
arr[] =  0 1 2 3 4

edge 0-1:
rep\_x = Find(0)
rep\_y = Find(1)

as they are diff
  rep\_x = Find(0)
  rep\_y = Find(1)
  rep\_y.parent = rep\_x
  number of connected componets = 5 - 1

         0 1 2 3 4
arr[] =  0 0 2 3 4

edge 2-1:
rep of 2 = 2
rep of 1 = 0

as they are diff
  rep\_x = 2
  rep\_y = 0
  rep\_y.parent = 2
  number of connected componets = 3

         0 1 2 3 4
arr[] =  2 0 2 3 4

edge 2-0:
rep of 2 = 2
rep of 0 = 2

they are same

edge 3-4:
...
number of connected componets = 2

### 261 Graph Valid Tree
Return true is a graph is a tree else return false
While doing union find, if an edge has both its endpoints have the same rep, then return false
Also at the end the # connected components shouls be 1


## Combinatorics

### 357. Count Numbers with Unique Digits
Count unique digits x  in therange from 0 <=  x < 10^n, where n  is given 
n=3
So we have to find # unique 1 digits (10) + # unique 2 digits (9*9) + # unique 3 digits (9*9*8)

## Bits
  - Count the nums of 1's  in N
    - Method 1

      ```
      Count[n] : Number of 1 bits
      Count[0] = 0;

      if n is odd; Count[n] = Count[n-1] + 1
      else Count[n] = Count[n/2]

      ```
    
    - Find the range 2 ^ x to 2^ (x+1) - 1  where n falls
      ```
        N  Count
        0   0
        1   1
      1 0  Count(0) + 1
      1 1  Count(1) + 1
    1 0 0  Count(0) + 1
    1 0 1  Count(1) + 1
    1 1 0  Count(2) + 1
    1 1 1  Count(3) + 1

      ```

## Sorting
### sort function
#### 451. Sort Characters By Frequency

The sort function on argument a and b returns true if a is less than b in the strct ordering. Here we can have the frequency counted in a map and use that map in sorting function.

```
sortFn(char a, char b) {
  if count[a] > count[b] // In this problem we need descending order
    return true

  return false;    
}
```
bbaaa: Here whenever a is conpared with b a will be ahead of b in strict ordering as count[a] > count[b]. 
bb
|
V
aa

abab: Here count[a] == count[b] so the prev function will return false. So no swapping will happen
so abab will return abab. 
So we need to tell what to do when the count[a] == count[b]

```
sortFn(char a, char b) {
  if count[a] > count[b] // In this problem we need descending order
    return true

  if(count[a] == count[b] && a < b) 
    return true

  return false;    
}
```

### Using counting sort

#### 451. Sort Characters By Frequency
#### 347. Top K Frequent Elements

arr[] = bcaccbdd

M[b] = 2
M[d] = 2
M[a] = 1
M[c] = 3

Here the key is the count and the max count possible is size of the arr

for x : arr
  int n = M[x] 
  char c = x;
  countingarr[n] = string(n, c)

Index:          0 1 2       3
counting arr:   0 a bbdd    ccc

Now depending on sorting order traverse this counting arr

## Array

### 189. Rotate Array
Rotate arr[n] by k elements
reverse first n-k
reverse last k
reverse first n

## List  
### 61. Rotate List
[1,2,3,4,5,6,7]
roate right by 3 : [5,6,7, 1,2,3,4] 

make a cicle
        1 2 3 
       7     4 
         6 5

traverse from head till 7 - 3 = 4th node and do 4->next = null and 5 is the new head 
         
Related : rotae left by 4 = roate right by 7 - 4 = 3 =   [5,6,7, 1,2,3,4]

## 96. Unique Binary Search Trees
Let m = n and F[m]: Num of unique BST possible with n number of nodes (1.2.3....n)
for m = n+1
  F(m) = F(m-1)*F[0] + F[m-2]*F(1) + ... + F(0)F[m-1]

  n = 1: 1
  n = 2:   1  (1,0)   2 (0,1) 
            \        /
            2       1 
  
  n=3:      1         1         (2,0)
              \2       \ 3
               \        /
                 3     2

               2  (1,1)
               /\
              1  3  
                  
            2 more for (0,2)
            



## General

### Binary Search
Consider the following binary search for finding the nearest member of hearter to K;
  ```
 int find\_nearest\_heater(vector<int> &heaters, int first, int last, int k) {

      while(first < last) {
        if(last == first  +1) {
          return abs(k - heaters[first]) < abs(heaters[last] - k) ? heaters[first] : heaters[last];
        }
        int mid = first + (last - first)/2;
        if(heaters[mid] == k) {
          return heaters[mid];

        } else if(heaters[mid] > k) {
          last = mid;
        } else {
          first = mid;
        }
      }
      
      return heaters[first];
    }
```
Here when we do first = mid or mast = mid as opposted to m+1 or m-1 resp; then there are chances
of inf loop

Index: 0 1 2
first = 0 
last 2
mid = 1

first = 1
last = 2
mid = 1

first = 1
last = 2
mid = 1
........ loop

But on the lower side:
Index: 0 1 2
first = 0 
last 2
mid = 1

first = 0
last = 1
mid = 0

first = 0
last = 0
mid = 0
........ the main loop break unless we write first <= last

With first = m+1 or last = mid -1 ; the loop will break in either cases if first < last or first <= last





### Counting sort
Only applicable when we know the max length of the sorting key

For example, to sort 
arr[] = 3 3 2 1

Here the keys are the values and if we know the maxlimit of that

Index:          0 1 2 3
counting ar:    0 1 1 2
Prefixadd:      0 1 2 4

for x : arr
  oupur\_arr[Prefixadd[x]] = x
  Prefixadd[x] --;



### Find median of 2D grid 
  (median of rows, median of cols) may not be a member of the pints set to begin with
  P = [(1,2) , (2,3) , (3,1)]
  med\_r = 2 
  med\_c = 2 
  but no points like 2,2


### BST
  left <= root < right

### DFS
  dfs on graph

  ```
dfs(int node) {
  visited[node] = true;
  for (ngh : neighbors[node]) {
    dfs(ngh);
  }
  dfs\_num[node] = total\_count --;

  dfs(0);
```
  While doing dfs on Tree we do not ned the visited info as there is no way to
  arrive the same node using 2 different paths

### Tree
  - Flatten a tree into a linked list
  ```
         1
        / \
       2   5
      / \   \
     3   4   6

   while(root)  
     root_l = root->left;
     root_r = root->right;

     root->left = NULL;
     root->right = root_l;
     last = find_the_rightmost_non_null_node(root_l);
     last->right = root_r;
      
     root= root->right;

  ```


### REcursion

- The following is a solution to return a bool in a particular scenaruio of recurtion.
The expection is only we get a false we should stop the recuion and return
  One solution: to use a global value res which will store a bool value;

    ```
    class Solution {
private:
    TreeNode *prev;
    bool res;
  public:
    void traverse(...) {
      traverse(...);
      if(res == true) { // is res is already false, do not revert it
        //some computaton that might evaluate a bool
        res = ...
      }
      traverse(..);
    }

    bool func(arg) {
      //it has to return bool
      bool = true;
      traverse(...);    

      return res;
    }
};
```
  Other solution: 

    ```
    class Solution {
private:
    TreeNode *prev;
    bool res;
  public:
    void traverse(...) {
      if(!traverse(...)) {
        return false;
      }
      //some computaton that might evaluate a bool
      res = ...
      return res;
      if(!traverse(..)) {
        return false;
      }

      return true;
    }

    bool func(arg) {
      //it has to return bool
      bool = true;
      traverse(...);    

      return res;
    }
};
