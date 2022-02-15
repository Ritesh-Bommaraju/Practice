class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in nums:
            if nums.count(i) == 1:
                return i
        
            
        