#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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

struct TestCase {
    vector<int> input;
    int val;
    int k;
    vector<int> output;
};

class UnitTest {
private:
    Solution obj;
    vector<TestCase> testcases;

public:
    UnitTest() {
        testcases.push_back({{3,2,2,3}, 3, 2, {2,2}});
        testcases.push_back({{0,1,2,2,3,0,4,2}, 2, 5, {0,1,4,0,3}});
    }

    void test() {
        for(int i = 0; i < testcases.size(); ++i) {
            vector<int> nums = testcases[i].input;
            int val = testcases[i].val;
            int k = testcases[i].k;
            vector<int> output = testcases[i].output;

            int result = obj.removeElement(nums, val);
            bool correct = true;
            
            sort(output.begin(), output.end());
            sort(nums.begin(), nums.begin()+k);

            if(k == result) {
                for(int j = 0; j < k; ++j)
                    if(output[j] != nums[j]) { correct = false; break; }
            }
            else
                correct = false;
            
            cout << "TestCase " << i+1 << ": " << ((correct) ? "passed":"failed") << endl;
        }
    }
};

int main() {
    UnitTest test;
    test.test();
}