# The file has the chess Piece Class
# Kendall Carter
# IT 327

from webbrowser import get
from chess_utils import BoardInfo
from chess_utils import PieceInfo


#WHile loops instead of for loops for rook piece 

class ChessPiece:
    def __init__(self, row_num, col_num, color, label=PieceInfo.EMPTY):
        self._row=row_num
        self._col=col_num
        self._color=color
        self._label=label
        

    def get_color(self):
        """Returns the color of the ChessPiece"""
        return self._col

    def get_label(self):
        """Returns the label of the ChessPiece"""
        return self._label

    def move(self, newRow, newCol):
        """Takes in new Row and Column and moves the chess piece"""
        self._row = newRow
        self._col = newCol

    def is_legal_move(newRow, newCol, board):
        """Return a boolean for if move is legal or not, to be overridden by other pieces"""
        return False
        
    def generate_legal_moves(theList, board):
        """Returns a list of the legal moves to represent a chess board"""
        return theList
    

    