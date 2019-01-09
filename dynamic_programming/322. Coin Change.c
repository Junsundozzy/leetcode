class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        for (int i = 0; i <= amount; i++) {
            dp.push_back(-1);
        }
        
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i-coins[j]] != -1) {
                    if (dp[i] == -1 || dp[i] >= dp[i - coins[j]] + 1) {
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
                
            }
            
        }
        
        return dp[amount];
    }
};
//dp[i]为金额i的最少硬币数,所以dp[i+a1],dp[i+a2]...都等于dp[i]+1

/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
*/