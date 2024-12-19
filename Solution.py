from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # Initialize two pointers: `index` will iterate through the list,
        # and `actual_Index` will keep track of the position for valid elements.
        index, actual_Index = 0, 0

        # Iterate over all elements in the `nums` array using `index`
        for index in range(len(nums)):
            # If the current element is not equal to `val`, keep it in the array
            if nums[index] != val:
                # Move the valid element to the position indicated by `actual_Index`
                nums[actual_Index] = nums[index]
                # Increment `actual_Index` to point to the next position for valid elements
                actual_Index += 1

        # Return the new length of the array after removing all occurrences of `val`
        return actual_Index