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


## General

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



