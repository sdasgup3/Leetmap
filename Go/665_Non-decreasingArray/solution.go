package solution

import ()

func CheckPossibility(nums []int) bool {
	count := 0
	first_violation := -1

	for i := 0; i < len(nums)-1; i++ {
		if nums[i] <= nums[i+1] {
			continue
		}
		count++
		if count == 1 {
			first_violation = i
		} else {
			return false
		}
	}

	if 0 == count {
		return true
	}

	// count == 1
	i := first_violation
	if i+2 >= len(nums) || nums[i] <= nums[i+2] {
		return true
	}
	if i-1 < 0 || nums[i-1] <= nums[i+1] {
		return true
	}
	return false
}
