class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                c1++;
            else if (nums[i] == 1)
                c2++;
            else
                c3++;
        }
        for (int i = 0; i < c1; i++)
            nums[i] = 0;
        for (int i = c1; i < c1 + c2; i++)
            nums[i] = 1;
        for (int i = c1 + c2; i < n; i++)
            nums[i] = 2;
    }
};