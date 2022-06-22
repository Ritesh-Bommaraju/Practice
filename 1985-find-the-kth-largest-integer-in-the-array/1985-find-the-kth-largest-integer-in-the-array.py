class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        a = []
        for i in range(len(nums)):
            a.append(int(nums[i]))
        a.sort(reverse = True)
        print(a)
        return str(a[k-1])