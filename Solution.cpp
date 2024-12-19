#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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