# [27. Remove Element](https://leetcode.com/problems/remove-element?envType=study-plan-v2&envId=top-interview-150)

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

- ## Approach 2:- Two Pointers

    - ### Intuition
        The goal is to remove all occurrences of a given value (`val`) from the input array (`nums`) while modifying the array in-place. The challenge is to achieve this without using extra space proportional to the array size.

        The idea is to use two pointers:
        - One pointer (`index`) to iterate through the array and check each element.
        - Another pointer (`actual_Index`) to keep track of where the next valid (non-`val`) element should be placed.

        Whenever a valid element (i.e., an element not equal to `val`) is encountered, it is placed at the `actual_Index` position, and `actual_Index` is incremented. In this way, the array is effectively "compressed" by removing elements equal to `val`.

        At the end of the iteration, the value of `actual_Index` will represent the length of the modified array, and the first `actual_Index` elements of the array will contain all valid elements.

    - ### Approach
        1. **Initialize two pointers**:
            - `index` (iterating pointer) will be used to traverse the entire array.
            - `actual_Index` (position pointer) will track where the next valid element should be placed.

        2. **Iterate over the array**:
            - For each element in the array, check if it is equal to `val`.
            - If it is **not** equal to `val`, move it to the `actual_Index` position in the array, then increment `actual_Index`.

        3. **Return the new length**:
            - The value of `actual_Index` will be the number of valid elements left in the array after removing all occurrences of `val`.
            - The first `actual_Index` elements in the array will hold the valid elements.

        4. **Modify the array in-place**:
            - The array is modified directly without needing any extra space for another array.

        - #### Example Walkthrough
            Given `nums = [3, 2, 2, 3]` and `val = 3`:
            - **Initial array**: `[3, 2, 2, 3]`
            - **First pass**:
                - At index 0, `nums[0] == 3`. Skip this element.
                - At index 1, `nums[1] == 2`. Move it to `nums[0]` (array becomes `[2, 2, 2, 3]`), and increment `actual_Index`.
                - At index 2, `nums[2] == 2`. Move it to `nums[1]` (array becomes `[2, 2, 2, 3]`), and increment `actual_Index`.
                - At index 3, `nums[3] == 3`. Skip this element.
            - **Final array**: `[2, 2]`
            - Return `actual_Index = 2`, representing the new length of the array.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution**
            ```cpp []
            class Solution {
            public:
                // Function to remove all occurrences of `val` from the `nums` array
                int removeElement(vector<int>& nums, int val) {
                    // Initialize two pointers: `index` to iterate over the array
                    // and `actual_Index` to track where valid elements should be placed.
                    int index = 0, actual_Index = 0;
                    
                    // Loop over all elements in the `nums` array using `index`
                    for(; index < nums.size(); ++index) {
                        // If the current element is not equal to `val`, we need to keep it
                        if(nums[index] != val) {
                            // Place the valid element at the position indicated by `actual_Index`
                            nums[actual_Index++] = nums[index]; // Increment `actual_Index` after placement
                        }
                    }

                    // Return the new size of the array, which is the count of valid elements
                    return actual_Index;
                }
            };
            ```

    - ### Time Complexity
        - **$O(n)$**, where **$n$** is the number of elements in the `nums` array.
            - The array is iterated through once using the `index` pointer.
            - For each element, we perform constant-time operations (comparison and assignment).
            - The algorithm processes each element of the array in constant time, resulting in linear time complexity.

    - ### Space Complexity
        - **$O(1)$**.
            - The algorithm modifies the array in-place and only uses a few extra variables (`index`, `actual_Index`) to track positions.
            - No additional data structures (like another array) are used, so the space complexity is constant.