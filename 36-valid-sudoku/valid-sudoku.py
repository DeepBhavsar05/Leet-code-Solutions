class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_sets=[set() for _ in range(9)]
        col_sets=[set() for _ in range(9)]
        grid_set=set()
        for i in range(9):
            grid_set.clear()
            for j in range(3):
                for k in range(3):
                    num=board[j+(3*(i//3))][k+(3*(i%3))]
                    if num=='.':
                        continue
                    if num in row_sets[j+(3*(i//3))]:
                        return False
                    if num in col_sets[k+(3*(i%3))]:
                        return False
                    if num in grid_set:
                        return False
                    
                    row_sets[j+(3*(i//3))].add(num)
                    col_sets[k+(3*(i%3))].add(num)
                    grid_set.add(num)
        return True
        