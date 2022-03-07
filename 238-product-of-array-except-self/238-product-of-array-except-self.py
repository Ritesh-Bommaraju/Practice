class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        l_to_r = [1]
        r_to_l = [1]
        for i in range(1,len(nums)):
            temp = l_to_r[i-1]*nums[i-1]
            l_to_r.append(temp)
        nums.reverse()
        for i in range(1, len(nums)):
            temp = r_to_l[i-1]*nums[i-1]
            r_to_l.append(temp)
        r_to_l.reverse()
        ans = []
        for i, j in zip(l_to_r,r_to_l):
            ans.append(i*j)
        return ans