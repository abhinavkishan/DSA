class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, array<bool, 9>> row;
        unordered_map<int, array<bool, 9>> col;
        unordered_map<int, array<bool, 9>> quad;
        for(int i = 0; i < 9; i++) {
            row[i].fill(0);
            col[i].fill(0);
            quad[i].fill(0);
        }
        int row_quad = 0;
        int dot = '.' - '1';
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int  j = 0; j < m; j++) {
                int ele = board[i][j] - '1';
                if(ele != dot) {
                    if(row[i][ele] || col[j][ele] || quad[row_quad + (j / 3)][ele]) return false;
                    row[i][ele] = 1, col[j][ele] = 1,  quad[row_quad + (j / 3)][ele] = 1;
                }
            }
            if(i % 3 == 2) row_quad += 3;
        }
        return true;
    }
};