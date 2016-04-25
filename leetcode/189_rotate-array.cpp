class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> vi(n);
        for (int i = 0; i < n; i++) {
            vi[(i + k) % n] = nums[i];
        }
        nums = vi;
    }
};