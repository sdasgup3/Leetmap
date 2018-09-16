Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

solution:

1 . Store the value nums[1] in the map along with its index i.
2. Search map with target - nums[i]

Note: We cannot store target - nums[i] because we do not know the index of that index in the curent iteration.

[2, 7, 11, 15]

target = 9
M = []
1 iter. Search for 7 --> not found
M[2->0]

2 iter. Search for 2 --> found
return (1, M[2]) = (1,0)
