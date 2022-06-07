class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size() - 1;
        int i = m - 1, j = n - 1;
        
        while(j >= 0 && i >= 0){
            if(nums2[j] > nums1[i]){
                nums1[k] = nums2[j];
                j--;
                k--;
            }else{
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
        
        while(j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        
        while(i >= 0){
            nums1[k] = nums1[i];
            k--;
            i--;
        }
    }
};