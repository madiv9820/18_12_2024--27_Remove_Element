from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testcases = {1: ([3,2,2,3], 3, 2, [2,2]),
                            2: ([0,1,2,2,3,0,4,2], 2, 5, [0,1,4,0,3])}
        self.__obj = Solution()
        return super().setUp()

    @timeout(0.5)
    def test_case_1(self):
        nums, val, k, output = self.__testcases[1]
        result = self.__obj.removeElement(nums, val)
        self.assertIsInstance(result, int)
        self.assertEqual(k, result)
        
        nums = nums[:result]
        nums.sort()
        output.sort()
        self.assertTrue(all(x == o for x, o in zip(nums, output)))

    @timeout(0.5)
    def test_case_2(self):
        nums, val, k, output = self.__testcases[2]
        result = self.__obj.removeElement(nums, val)
        self.assertIsInstance(result, int)
        self.assertEqual(k, result)
        
        nums = nums[:result]
        nums.sort()
        output.sort()
        self.assertTrue(all(x == o for x, o in zip(nums, output)))

if __name__ == '__main__': unittest.main()