class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)
        minRight = [0] * n
        minRight[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            minRight[i] = min(nums[i], minRight[i + 1])

        maxLeft = nums[0]
        for i in range(1, n):
            if maxLeft <= minRight[i]:
                return i
            maxLeft = max(maxLeft, nums[i])