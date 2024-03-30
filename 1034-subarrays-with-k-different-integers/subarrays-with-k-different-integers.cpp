class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return KatMost(nums, k) - KatMost(nums, k - 1);
    }

private:
    int KatMost(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int s = 0;
        int cnt = 0;
        for (int e = 0; e < nums.size(); ++e) {
            mp[nums[e]]++;
            while (mp.size() > k) {
                mp[nums[s]]--;
                if (mp[nums[s]] == 0) {
                    mp.erase(nums[s]);
                }
                ++s;
            }
            cnt += (e - s + 1);
        }
        return cnt;
    }
};