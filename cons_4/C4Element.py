"""
 * Application for general processing of ASCCI art files.
 * Solution for assignment 4 of Part C of TP1
 * Course: Oriented Object programming
 * 
 * @version 1.0
 * @date 	2023.09.23
 * @author 	Juan Manuel BORQUEZ PEREZ
 * @contact borquez.juan00@gmail.com
 * 
"""
class C4Element:
    """A class for the elements in an ASCII art file."""
    def __init__(self, ch:chr, row: int, col:int):
        self.character = ch
        self.row = row
        self.column = col
    def __str__(self):
        return self.character