package solution
//http://www.geeksforgeeks.org/find-two-missing-numbers-set-2-xor-based-solution/

import (
)

func FindTwoMissing(nums []int) []int {
	n := len(nums)
  k := n+1

	for i, _ := range nums {
		actual_val := nums[i] % k
    //fmt.Println(actual_val)
		nums[actual_val-1] = nums[actual_val-1] + k
	}

	dup, miss := -1, -1
	for i, _ := range nums {
		aux_val := nums[i] / k
		if 2 == aux_val {
			dup = i + 1
		}
		if 0 == aux_val {
			miss = i + 1
		}
	}

  // Unmodify the input array
  for i, _ := range nums {
    nums[i] = nums[i]%k
  }


	return []int{dup, miss}
}
