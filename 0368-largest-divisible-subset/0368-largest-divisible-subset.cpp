class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        vector<int> parent(n, 0), len(n, 1);
        int maxLen = 1, lastIndex = 0;

        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] % nums[j] == 0 && len[j] >= len[i]){
                    parent[i] = j;
                    len[i] = len[j] + 1;

                    if(len[i] > maxLen) {
                        maxLen = len[i];
                        lastIndex = i;
                    }
                }
            }
        }

        vector<int> ans;
        while(maxLen--) {
            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};