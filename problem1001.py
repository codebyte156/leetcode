'''

There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] 
indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.
When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.

You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, 
determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, 
turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist.
A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.

 

'''

from collections import defaultdict
from typing import List

class Solution:
    def gridIllumination(self, n: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        # Initialize counters for rows, columns, diagonals, and anti-diagonals
        rows = defaultdict(int)
        cols = defaultdict(int)
        diagonals = defaultdict(int)
        anti_diagonals = defaultdict(int)

        # Set of lamps to quickly check if a lamp is present at a particular cell
        lamps_set = set()

        # Increment counters for each lamp
        for lamp in lamps:
            row, col = lamp
            rows[row] += 1
            cols[col] += 1
            diagonals[row - col] += 1
            anti_diagonals[row + col] += 1
            lamps_set.add((row, col))

        # Function to check if a cell is illuminated
        def is_illuminated(row, col):
            return rows[row] > 0 or cols[col] > 0 or diagonals[row - col] > 0 or anti_diagonals[row + col] > 0

        # Result list to store answers
        result = []

        # Process queries
        for query in queries:
            row, col = query
            if is_illuminated(row, col):
                result.append(1)
                # Turn off adjacent lamps
                for dr in [-1, 0, 1]:
                    for dc in [-1, 0, 1]:
                        nr, nc = row + dr, col + dc
                        if (nr, nc) in lamps_set:
                            lamps_set.remove((nr, nc))
                            rows[nr] -= 1
                            cols[nc] -= 1
                            diagonals[nr - nc] -= 1
                            anti_diagonals[nr + nc] -= 1
            else:
                result.append(0)

        return result

# Test cases
solution = Solution()
print(solution.gridIllumination(5, [[0,0],[4,4]], [[1,1],[1,0]]))  # Output: [1,0]
print(solution.gridIllumination(5, [[0,0],[4,4]], [[1,1],[1,1]]))  # Output: [1,1]
print(solution.gridIllumination(5, [[0,0],[0,4]], [[0,4],[0,1],[1,4]]))  # Output: [1,1,0]


#By RR