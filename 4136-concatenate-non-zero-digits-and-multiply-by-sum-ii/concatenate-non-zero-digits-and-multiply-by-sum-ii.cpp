class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> power(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * 10) % MOD;
        }
        vector<long long> prefixNumber(n + 1, 0);
        vector<int> prefixSum(n + 1, 0);
        vector<int> prefixCount(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            prefixSum[i + 1] = prefixSum[i] + digit;
              if (digit != 0) {
                prefixNumber[i + 1] = (prefixNumber[i] * 10 + digit) % MOD;
                prefixCount[i + 1] = prefixCount[i] + 1;
            }
            else {
                prefixNumber[i + 1] = prefixNumber[i];
                prefixCount[i + 1] = prefixCount[i];
            }
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1] + 1;
            long long sum = prefixSum[r] - prefixSum[l];
            int cnt = prefixCount[r] - prefixCount[l];
            long long x = (prefixNumber[r] -(prefixNumber[l] * power[cnt]) % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};