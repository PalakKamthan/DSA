class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int abc = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[abc++] = nums[i];
            }
        }
        while (abc < nums.size()) {
            nums[abc++] = 0;
        }
    }
};