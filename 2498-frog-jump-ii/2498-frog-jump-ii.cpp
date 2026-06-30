class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();

        if (n == 2)
            return stones[1] - stones[0];

        int ans = stones[1] - stones[0];

        for (int i = 2; i < n; i++) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna