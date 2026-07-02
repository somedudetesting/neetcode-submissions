class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size() - 1;

        while (m <= r) {
            int temp;
            if (nums[m] == 1) {
                m++;
            }
            else if (nums[m] == 0) {
                temp = nums[m];
                nums[m] = nums[l];
                nums[l] = temp;
                l++;
                m++;
            }
            else if (nums[m] == 2) {
                temp = nums[m];
                nums[m] = nums[r];
                nums[r] = temp;
                r--;
            }
        }
    }
};