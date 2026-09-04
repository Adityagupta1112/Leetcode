class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int need=prices[0]+prices[1];
        int left=money-need;
        return left<0?money:left;
    }
};