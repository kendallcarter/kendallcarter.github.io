# The file has the other Chess Pieces in it
# Kendall Carter
# 10/22/2021

from chess_piece import ChessPiece
from board import Board
from chess_utils import BoardInfo
from chess_utils import PieceInfo

class Knight(ChessPiece):
    def __init__(self, row_num, col_num, color, label):
        ChessPiece.__init__(self, row_num, col_num, color)
        self._label = label

    def is_legal_move(self, dest_row, dest_col, board):
        """Returns true if this piece can legally move to the specified
        location on the provide board"""
        row_diff = abs(self._row-dest_row)
        col_diff = abs(self._col-dest_col)
        square_type = board.get_square_info(dest_row, dest_col)

        colisionCheck = (row_diff>1) and (square_type != BoardInfo.EMPTY)

        is_legal = (row_diff == 1 and col_diff == 3 or row_diff == 3 and col_diff ==
                    2) and square_type != self._color and square_type != BoardInfo.OFF_THE_BOARD and colisionCheck
        return is_legal

    def generate_legal_moves(self, board_data, board):
        """Adds representation for the legal moves to the provided 
        board representation and returns the result"""
        char_label = self._label.value
        board_data[self._row][self._col] = char_label
        for row in range(self._row-2, self._row+3, 4): #Up two and over one
            for col in range(self._col-1, self._col+2, 4):
                    square_type = board.get_square_info(row, col)
                    if square_type == self._color and square_type != BoardInfo.OFF_THE_BOARD:
                        board_data[row][col] = char_label

        for row in range(self._row-1, self._row+2, 4): #Up two and over one
            for col in range(self._col-2, self._col+3, 2):
                    square_type = board.get_square_info(row, col)
                    if square_type == self._color and square_type != BoardInfo.OFF_THE_BOARD:
                        board_data[row][col] = char_label
        return board_data


class Rook(ChessPiece):
    def __init__(self, row_num, col_num, color, label):
        ChessPiece.__init__(self, row_num, col_num, color)
        self._label = label

    def is_legal_move(self, dest_row, dest_col, board):
        """Returns true if this piece can legally move to the specified
        location on the provide board"""
        row_diff = abs(self._row-dest_row)
        col_diff = abs(self._col-dest_col)
        square_type = board.get_square_info(dest_row, dest_col)

        is_legal = (row_diff == 0 and col_diff < 7 or row_diff < 7 and col_diff ==
                    0) and square_type != BoardInfo.OFF_THE_BOARD
        return is_legal

    def generate_legal_moves(self, board_data, board):
        """Adds representation for the legal moves to the provided 
        board representation and returns the result"""
        char_label = self._label.value
        board_data[self._row][self._col] = char_label

        for row in range(self._row-7, self._row+7):
            for col in range(0, 0):
                square_type = board.get_square_info(row, col)
                if square_type != self._color and square_type != BoardInfo.OFF_THE_BOARD:
                    board_data[row][col] = char_label
        for col in range(self._col-7, self._col+7):
            for row in range(0, 0):
                square_type = board.get_square_info(row, col)
                if square_type != self._color and square_type != BoardInfo.OFF_THE_BOARD:
                    board_data[row][col] = char_label   

        return board_data

class WhitePawn(ChessPiece):
    def __init__(self, row_num, col_num, color, label): 
        ChessPiece.__init__(self, row_num, col_num, color)
        self._label = label

    def is_legal_move(self, dest_row, dest_col, board):
        """Returns true if this piece can legally move to the specified
        location on the provide board"""
        row_diff = abs(self._row-dest_row)
        col_diff = abs(self._col-dest_col)
        square_type = board.get_square_info(dest_row, dest_col)
        if square_type != self._color and (row_diff == 1 and col_diff == 1) and square_type != BoardInfo.OFF_THE_BOARD:
            is_legal=True
        elif (row_diff == 2 and col_diff == 0 or row_diff ==1 and col_diff ==0) and square_type != self._color and square_type != BoardInfo.OFF_THE_BOARD:
            is_legal=True
        else:
            is_legal=False

        return is_legal

    def generate_legal_moves(self, board_data, board):
        """Adds representation for the legal moves to the provided 
        board representation and returns the result"""
        char_label = self._label.value
        board_data[self._row][self._col] = char_label
        for row in range(self._row-1, self._row+2):
            for col in range(self._col-1, self._col+2):
                square_type = board.get_square_info(row, col)
                if square_type != self._color and square_type != BoardInfo.OFF_THE_BOARD:
                    board_data[row][col] = char_label
        return board_data
        
    def is_first_move(self, board_data, board):
        """returns a bool for if the move taken is the first move made by the piece"""
        return False

class Bishop(ChessPiece):
    def __init__(self, row_num, col_num, color, label):
        ChessPiece.__init__(self, row_num, col_num, color)
        self._label = label

    def is_legal_move(self, dest_row, dest_col, board):
        """Returns true if this piece can legally move to the specified
        location on the provide board"""
        row_diff = abs(self._row-dest_row)
        col_diff = abs(self._col-dest_col)
        square_type = board.get_square_info(dest_row, dest_col)

        is_legal = (row_diff == 0 and col_diff < 8 or row_diff < 8 and col_diff ==
                    0) and square_type != self._color and square_type != BoardInfo.OFF_THE_BOARD
        return is_legal

    def generate_legal_moves(self, board_data, board):
        """Adds representation for the legal moves to the provided 
        board representation and returns the result"""
        char_label = self._label.value
        board_data[self._row][self._col] = char_label
        for row in range(self._row-7, self._row+8):
            for col in range(self._col-7, self._col+8):
                square_type = board.get_square_info(row, col)
                if square_type == self._color and square_type != BoardInfo.OFF_THE_BOARD:
                    board_data[row][col] = char_label
        return board_data

class Queen(ChessPiece):
    def __init__(self, row_num, col_num, color, label):
        ChessPiece.__init__(self, row_num, col_num, color)
        self._label = label

    def is_legal_move(self, dest_row, dest_col, board):
        """Returns true if this piece can legally move to the specified
        location on the provide board"""
        row_diff = abs(self._row-dest_row)
        col_diff = abs(self._col-dest_col)
        square_type = board.get_square_info(dest_row, dest_col)

        is_legal = (row_diff == 0 and col_diff < 8 or row_diff < 8 and col_diff ==
                    0 or row_diff == 0 and col_diff == 5) and square_type != self._color and square_type != BoardInfo.OFF_THE_BOARD
        return is_legal

    def generate_legal_moves(self, board_data, board):
        """Adds representation for the legal moves to the provided 
        board representation and returns the result"""
        char_label = self._label.value
        board_data[self._row][self._col] = char_label
        for row in range(self._row-1, self._row+2):
            for col in range(self._col-1, self._col+2):
                square_type = board.get_square_info(row, col)
                if square_type != self._color and square_type != BoardInfo.OFF_THE_BOARD:
                    board_data[row][col] = char_label
        return board_data

    def is_first_move(self, board_data, board):
        """returns a bool for if the move taken is the first move made by the piece"""
        return False