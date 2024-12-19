- ## Approach 1:- Shifting

    - ### Intuition
        The task is to remove all occurrences of a specific value (`val`) from an array (`nums`). The goal is to modify the array in-place and return the new size of the array after removing the elements equal to `val`.

        The idea is to iterate through the array and shift the remaining elements to the left whenever an element equal to `val` is encountered. By doing this, we "remove" the element by overwriting it with the next valid element and reduce the size of the array accordingly.

    - ### Approach
        1. **Iterate through the array**: Use an index `i` to iterate through the array. If the current element is not equal to `val`, move forward.
        2. **Remove elements equal to `val`**: Whenever an element equal to `val` is found, shift all the subsequent elements to the left by one position, effectively removing the element from the array.
        3. **Update the size**: After shifting, decrease the size `n` to reflect that an element has been removed.
        4. **Return the new size**: Once all elements are processed, return the updated size of the array (`n`), which will represent the array without the `val` elements.

        - #### Example Walkthrough
            Given `nums = [3, 2, 2, 3]` and `val = 3`:

            - **Initial array**: `[3, 2, 2, 3]`
            - **First pass**:
                - At index 0, `nums[0] == 3`. Shift elements to the left: `[2, 2, 3]` (size `n` decreases to 3).
            - **Second pass**:
                - At index 1, `nums[1] == 2`, so continue to the next index.
                - At index 2, `nums[2] == 3`. Shift elements to the left: `[2, 2]` (size `n` decreases to 2).
            - **Final array**: `[2, 2]`
            - Return size `n = 2`.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution**
            ```cpp []
            class Solution {
            public:
                int removeElement(vector<int>& nums, int val) {
                    int n = nums.size();  // Get the size of the input array `nums`

                    // Iterate over the array using index `i`
                    for(int i = 0; i < n; ) {
                        // If the current element is equal to `val`, we need to remove it
                        while(i < n && nums[i] == val) {
                            // Shift all elements to the left by one position, starting from i+1
                            for(int j = i+1; j < n; ++j)
                                nums[j-1] = nums[j];  // Copy element from `nums[j]` to `nums[j-1]`
                            
                            --n;  // Decrease the size of the array since we've "removed" one element
                        }

                        ++i;  // Move to the next element
                    }

                    // Return the new size of the array after removal of elements
                    return n;
                }
            };
            ```

    - ### Time Complexity
        The time complexity of the given approach is **$O(n^2)$**, where **$n$** is the number of elements in the array. This is due to the nested loops:
        - The outer loop iterates through the array.
        - The inner loop shifts the elements when an element equal to `val` is found, which in the worst case could be **$O(n)$** for every such element.

        Thus, in the worst case where every element is equal to `val`, the time complexity becomes **$O(n^2)$**.

    - ### Space Complexity
        The space complexity is **$O(1)$** because the operation is done in-place without using any additional data structures that scale with the input size. The only extra memory used is for variables like the loop index, which does not depend on the size of the input array.