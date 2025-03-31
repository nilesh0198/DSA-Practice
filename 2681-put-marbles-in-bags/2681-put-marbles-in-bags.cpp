class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (n == 1) return 0;
        long long max = weights[0] + weights[n - 1], min = weights[0] + weights[n - 1];
        vector<int> sum(n - 1);
        for (int i = 1; i < n; i++)
            sum[i - 1] = weights[i] + weights[i - 1];
        sort(sum.begin(), sum.end());
        for (int i = 0; i < k - 1; i++) {
            min += sum[i];
            max += sum[n - i - 2];
        }
        return max - min;
    }
};