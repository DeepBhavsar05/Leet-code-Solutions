// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<unordered_set<int>> row(9);
//         vector<unordered_set<int>> col(9);
//         vector<vector<unordered_set<int>>> gridset(3,3);

//         for(int i=0;i<board.size();i++){
//             gridset.clear();
//             for(int j=0;j<board[0].size();j++){
//                 int num = board[i][j];
//                 if(num==".") continue;

//                 if(row[i].count(num) || col[j].count(num) || gridset[i][j%3].count(num)) return false;

//                 row[i].insert(num);
//                 col[j].insert(num);
//                 gridset[i][j%3].insert(num);
//             }
//         }
//         return true;
//     }
// };

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row_sets(9);
        vector<unordered_set<char>> col_sets(9);
        unordered_set<char> grid_set;

        for (int i = 0; i < 9; ++i) {
            grid_set.clear();
            for (int j = 0; j < 9; ++j) {
                int row = i - i % 3 + j / 3;
                int col = (i % 3) * 3 + j % 3;
                char num = board[row][col];

                if (num == '.') continue;

                if (row_sets[row].count(num)) return false;
                if (col_sets[col].count(num)) return false;
                if (grid_set.count(num)) return false;

                row_sets[row].insert(num);
                col_sets[col].insert(num);
                grid_set.insert(num);
            }
        }
        return true;
    }
};
