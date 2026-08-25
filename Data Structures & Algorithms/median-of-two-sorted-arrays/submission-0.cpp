class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        vector<int> nums(n);

        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                nums[k++] = nums1[i++];
            } else {
                nums[k++] = nums2[j++];
            }
        }

        while (i < nums1.size()) {
            nums[k++] = nums1[i++];
        }
        while (j < nums2.size()) {
            nums[k++] = nums2[j++];
        }


        double median = 0;
        if (n % 2 == 1) {
            median = nums[n / 2];
        } else {
            median = (double) (nums[(n / 2) - 1] + nums[n / 2]) / 2;
        }

        return median;
    }
};
