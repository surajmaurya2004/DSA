class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0; // agar 4 ya usse kam elements hain to sabko same kar sakte hain

        sort(nums.begin(), nums.end()); // array ko sort kar lo

        // 4 possible cases consider karte hain:
        int ans = INT_MAX;
        ans = min(ans, nums[n - 1] - nums[3]);   // change 3 smallest
        ans = min(ans, nums[n - 2] - nums[2]);   // change 2 smallest + 1 largest
        ans = min(ans, nums[n - 3] - nums[1]);   // change 1 smallest + 2 largest
        ans = min(ans, nums[n - 4] - nums[0]);   // change 3 largest

        return ans;
    }
};
