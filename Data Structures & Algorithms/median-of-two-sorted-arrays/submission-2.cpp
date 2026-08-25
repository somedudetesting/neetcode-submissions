class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if (A.size() > B.size()) {
            swap(A, B);
        }

        int total = A.size() + B.size();
        int half = (total+1) / 2;
        
        int l = 0, r = A.size();
        while (l <= r) {
            int i = ((l + r) / 2);
            int j = half - i;

            int aLeft = (i > 0) ? A[i - 1] : INT_MIN;
            int aRight = (i < A.size()) ? A[i] : INT_MAX;
            int bLeft = (j > 0) ? B[j - 1] : INT_MIN;
            int bRight = (j < B.size()) ? B[j] : INT_MAX;

            if (aLeft <= bRight && bLeft <= aRight) {
                if (total % 2 == 0) {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
                } 
                return max(aLeft, bLeft);

            } else if (aLeft > bRight) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;
    }
};
