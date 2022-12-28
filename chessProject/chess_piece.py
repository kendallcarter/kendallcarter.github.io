from cProfile import label
from shutil import move
from turtle import color
from chess_utils import BoardInfo
from chess_utils import PieceInfo

class ChessPiece:
    def __init__(self, row_num, col_num, label, color):
        ChessPiece.__init__(self, row_num, col_num, label, color)
        #PieceInfo.EMPTY

    def get_color(self):
        return color

    def get_label(self):
        return label

    def move(self, newRow, newCol):
        row_num = newRow
        col_num = newCol

    def is_legal_move(newRow, newCol, Board):
        return False
        
    def generate_legal_moves(theList, Board):
        return theList
    

    
