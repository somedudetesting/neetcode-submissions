class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        do {
            int mid = (l + r) / 2;
            if (target > nums[mid]) {
                l++;
            } else if (target < nums[mid]) {
                r--;
            } else {
                return mid;
            } 
        } while (l <= r);

        return -1;
    }
};
