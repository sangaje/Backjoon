import sys

def sudoku(board: list[list], N):
        full = (1 << N) -1
        N_box = 3
        
        # Setting up
        cols : list[int] = [full for _ in range(N)]
        rows : list[int] = [full for _ in range(N)]
        boxs : list[list[int]] = [[full for _ in range(N_box)] for _ in range(N_box)]
        
        avail_rows : list[int] = [0 for _ in range(N)]
        avail_cols : list[int] = [0 for _ in range(N)]
        
        for i in range(N):
                for j in range(N):
                        indx = board[i][j] - 1
                        if indx < 0:
                                avail_rows[i] |= 1 << j
                                avail_cols[j] |= 1 << i
                                continue
                        cols[j] ^= (1 << indx)
                        rows[i] ^= (1 << indx)
                        boxs[i // N_box][j // N_box] ^= (1 << indx)
        
        def get_avails(row, col):
                avails = cols[col]
                avails &= rows[row]
                avails &= boxs[row // N_box][col // N_box]
                return avails
        
        def is_done():
                for line in avail_rows:
                        if line:
                                return False
                
                return True
        
        def set_and_go(avails, col, row, col_bit, row_bit):
                while avails:
                        bit = avails & -avails
                        
                        # Set
                        cols[col] ^= bit
                        rows[row] ^= bit
                        boxs[row // N_box][col // N_box] ^= bit
                        
                        avail_rows[row] ^= col_bit
                        avail_cols[col] ^= row_bit
                        
                        board[row][col] = bit.bit_length()
                        if solve():
                                return True
                        
                        avails ^= bit
                        
                        cols[col] ^= bit
                        rows[row] ^= bit
                        boxs[row // N_box][col // N_box] ^= bit
                        
                        avail_rows[row] ^= col_bit
                        avail_cols[col] ^= row_bit
                        
                return False
        
        # retv = (row, col)
        def get_minimum_cell() -> tuple[int, int]:
                retv = None
                min = 10
                for row in range(N):
                        col_avails = avail_rows[row]
                        while col_avails:
                                col_bit = col_avails & -col_avails
                                col = col_bit.bit_length() -1
                                
                                avails = get_avails(row, col)
                                if not avails:
                                        return None
                                
                                bit_count = avails.bit_count()
                                if bit_count < min:
                                        min = bit_count
                                        retv = (row, col, avails)
                                        
                                col_avails ^= col_bit
                
                return retv
        
        def solve():
                if is_done():
                        return True
                
                retv = get_minimum_cell()
                
                if not retv:
                        return False
                
                row, col, avails = retv
                
                if set_and_go(avails, col, row, 1 << col, 1 << row):
                        return True
                                
                
                return False

        return solve()

if __name__ == "__main__":
        board = []
        
        for _ in range(9):
                in_args = sys.stdin.readline().rstrip().split()
                
                board.append(list(map(int, in_args)))
        
        retv = sudoku(board, 9)
        
        for line in board :
                for cell in line:
                        print(cell, end = ' ')
                print()
                
        if not retv:
                print("시이뻐어어얼")