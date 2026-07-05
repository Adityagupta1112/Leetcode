class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> dp;

    int getIntFromChar(char ch) {
        return (ch == 'S' || ch == 'E') ? 0 : ch - '0';
    }

    bool isValid(int i, int j, vector<string>& board) {
        return (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X');
    }

    pair<int, int> solve(int i, int j, vector<string>& board) {

        if (board[i][j] == 'E')
            return {0, 1};

        if (board[i][j] == 'X')
            return {0, 0};

        if (dp[i][j] != make_pair(-1, -1))
            return dp[i][j];

        int upScore = -1, upPath = 0;
        int leftScore = -1, leftPath = 0;
        int diagScore = -1, diagPath = 0;

        char ch = board[i][j];

        // Up
        if (isValid(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            if (paths > 0) {
                upScore = score + getIntFromChar(ch);
                upPath = paths;
            }
        }

        // Left
        if (isValid(i, j - 1, board)) {
            auto [score, paths] = solve(i, j - 1, board);
            if (paths > 0) {
                leftScore = score + getIntFromChar(ch);
                leftPath = paths;
            }
        }

        // Diagonal
        if (isValid(i - 1, j - 1, board)) {
            auto [score, paths] = solve(i - 1, j - 1, board);
            if (paths > 0) {
                diagScore = score + getIntFromChar(ch);
                diagPath = paths;
            }
        }

        int bestScore = max({upScore, leftScore, diagScore});

        if (bestScore == -1)
            return dp[i][j] = {0, 0};

        int bestPath = 0;

        if (upScore == bestScore)
            bestPath = (bestPath + upPath) % MOD;

        if (leftScore == bestScore)
            bestPath = (bestPath + leftPath) % MOD;

        if (diagScore == bestScore)
            bestPath = (bestPath + diagPath) % MOD;

        return dp[i][j] = {bestScore, bestPath};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        n = board.size();

        dp.assign(n, vector<pair<int, int>>(n, {-1, -1}));

        auto result = solve(n - 1, n - 1, board);

        return {result.first, result.second};
    }
};