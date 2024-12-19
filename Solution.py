from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # Initialize count to track how many elements have been removed
        count = 0
        # Initialize i to 0, the starting index for iterating through the list
        i = 0
        # n is the length of the list, will be used to track the current length
        n = len(nums)

        # Iterate through the list while i is less than n (the current length of nums)
        while i < n:
            # Check if the current element is equal to the value to be removed
            while i < n and nums[i] == val:
                # Shift all elements after the current one to the left by 1
                # This effectively removes the element at index i
                for j in range(i+1, n): 
                    nums[j-1] = nums[j]
                # Reduce n by 1 since we effectively removed an element
                n -= 1
            # If the current element is not equal to 'val', move to the next index
            i += 1

        # Return the new length of the list after removal
        return n