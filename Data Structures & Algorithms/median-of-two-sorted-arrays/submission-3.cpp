class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m;

        while(true){
            int partition1 = (l + r) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int leftMax1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1]; 
            int rightMin1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int leftMax2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int rightMin2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if(leftMax1 <= rightMin2 && leftMax2 <= rightMin1){
                if((n + m) % 2){
                    return (double) max(leftMax1, leftMax2);
                }
                return (double) (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2;
            }
            if(leftMax1 > rightMin2){
                r = partition1 - 1;
            }
            else if(leftMax2 > rightMin1){
                l = partition1 + 1;
            }
        }
    }
};
