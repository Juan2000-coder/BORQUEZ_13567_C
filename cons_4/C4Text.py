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
from C4Element import C4Element
from C4File import C4File

class C4Text:
    """Objects of this class represent the content of the ASCII
    art files and allow for general processing.
    """
    def getChars(self):
        """Obtain the characters in the ASCII art file.

        returns:
            A list containing the characters in the ASCII art file."""
        
        charlist = []
        for row in self.elements:
            for element in row:
                if not (element.character in charlist):
                    charlist.append(element.character)
        return charlist
        
    def getCount(self, ch:chr):
        """Obtain the number of ocurrrences of a given character in the ASCII art File.

        args:
            ch (chr): a character for wich the number of ocurrences is to be determined.
        returns:
            The number of ocurrences of the given character."""
        
        return sum(1 for row in self.elements for element in row if element.character == ch)
        
    def getCoords(self, ch:chr):
        """Obtain the coordinates of a given character in the ASCII art file. That is, a tuple
        (row, column) for each ocurrence of the character, considering that row = 0, and column = 0
        is corresponding to the top-left corner in the file.
        
        args:
            ch(chr): a character for wich the coordinates are to be determined.
        returns:
            A dictionary with 'ch' as the key and a list of coordinates (tuples) as the value.
        """

        coords:dict = {}
        for row in self.elements:
            for element in row:
                if element.character == ch:
                    if ch in coords:
                        coords[ch].append((element.row, element.column))
                    else:
                        coords[ch] = [(element.row, element.column)]
        return coords
        
    def __init__(self, asciiFile: C4File):
        """If a valid asciiFile is given, it assigns all the attributs in the object.
        args:
            asciiFile(C4File): The file to be process."""

        self.rows:int = 0           # The number of rows in the file.
        self.columns:int = 0        # The number of columns in the file.
        self.elements:list = []     # A matrix containing all the elements (C4Element).
        self.fileName = asciiFile.fileName # The name of the ASCII art File.

        # The name of the ASCII file is used by command methods in the C4 class.

        with asciiFile as file:
            """ Up to this point no verification of the existence of the file has been done
                so the previous line may throw an exception.
            """
            line = file.readLine()
            while line:
                self.rows += 1

                row = []
                for col, element in enumerate(line):
                    row.append(C4Element(element, self.rows - 1, col))
                self.elements.append(row)

                if (col + 1) > self.columns:
                    self.columns = col + 1

                line = file.readLine()
    def __str__(self):
        """
        Obtain the equivalent string representation of the object (the ASCII art).
        """
        lines:list = []
        for line in self.elements:
            lines.append(''.join(str(element) for element in line))
        return '\n'.join(lines)
