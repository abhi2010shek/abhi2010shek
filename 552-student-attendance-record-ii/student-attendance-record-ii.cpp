class Solution {
 public:
  int checkRecord(int n) {
    constexpr int kMod = 1'000'000'007;
    vector<vector<long>> dp(2, vector<long>(3));
    dp[0][0] = 1;

    while (n--) {
      const auto prev(dp);
      dp[0][0] = (prev[0][0] + prev[0][1] + prev[0][2]) % kMod;
      dp[0][1] = prev[0][0];
      dp[0][2] = prev[0][1];
      dp[1][0] = (prev[0][0] + prev[0][1] + prev[0][2] +  
                  prev[1][0] + prev[1][1] + prev[1][2]) %
                 kMod;

      dp[1][1] = prev[1][0];
      dp[1][2] = prev[1][1];
    }

    return accumulate(dp.begin(), dp.end(), 0, [](int s, vector<long>& row) {
      return (s + accumulate(row.begin(), row.end(), 0L)) % kMod;
    });
  }
};