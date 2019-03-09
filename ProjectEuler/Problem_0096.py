# A file containing fifty different Su Doku puzzles
# ranging in difficulty, but all with unique solution.
# By solving all fifty puzzles find the sum of the
# 3-digit numbers found in the top left corner of each
# solution grid.
# ----------------------------------------------------
# Analysis: dancing links X

from lib.dancing_links import DancingLinks

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p096_sudoku.txt'
with open(PROBLEM_FILE, 'r') as f:
    sudokus = f.read().strip().split('\n')


class Soduku:
    ORDER = 3
    ORDER_SQUARE = ORDER ** 2
    ORDER_QUATRA = ORDER ** 4
    GRID_OFFSET = 0
    ROW_OFFSET = GRID_OFFSET + ORDER_QUATRA
    COLUMN_OFFSET = ROW_OFFSET + ORDER_QUATRA
    BLOCK_OFFSET = COLUMN_OFFSET + ORDER_QUATRA
    COLUMNS = BLOCK_OFFSET + ORDER_QUATRA

    def __init__(self, grid):
        self.grid = grid

    def __str__(self):
        return '\n'.join(map(lambda a: ' '.join(map(str, a)), self.grid))

    @staticmethod
    def _get_one_row(row, column, value):
        block = row // Soduku.ORDER * Soduku.ORDER + column // Soduku.ORDER
        return (row * Soduku.ORDER_SQUARE + column + Soduku.GRID_OFFSET,
                row * Soduku.ORDER_SQUARE + value + Soduku.ROW_OFFSET,
                column * Soduku.ORDER_SQUARE + value + Soduku.COLUMN_OFFSET,
                block * Soduku.ORDER_SQUARE + value + Soduku.BLOCK_OFFSET)

    def solve(self):
        sparse_matrix = []
        choice_matrix = []
        for i in range(Soduku.ORDER_SQUARE):
            for j in range(Soduku.ORDER_SQUARE):
                if self.grid[i][j]:
                    value = self.grid[i][j] - 1
                    sparse_matrix.append(self._get_one_row(i, j, value))
                    choice_matrix.append((i, j, value))
                else:
                    for value in range(Soduku.ORDER_SQUARE):
                        sparse_matrix.append(self._get_one_row(i, j, value))
                        choice_matrix.append((i, j, value))

        for k in DancingLinks().solve(sparse_matrix, Soduku.COLUMNS):
            i, j, v = choice_matrix[k]
            self.grid[i][j] = v + 1

        return self.grid[0][0] * 100 + self.grid[0][1] * 10 + self.grid[0][2]


print(sum(map(lambda i: Soduku(list(map(lambda a: list(map(int, a)), sudokus[i + 1: i + 10]))).solve(), range(0, len(sudokus), 10))))
