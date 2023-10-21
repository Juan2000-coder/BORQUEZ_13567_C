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
import os
import subprocess

class asciiGenerator:
    """A class to read a message from an ASCII art file."""

    path = os.getcwd()                                  # The solution path.
    directory = os.path.join(path, "C4-auxiliar")       # The directory of ASCII generator application.
    executable = os.path.join(directory, "c4ascii")     # The path to the .exe file.
    fonts = os.path.join(directory, "font.txt")         # The to the fonts file
    command = [executable, "read", fonts]               # A list with the command elements.

    def __init__(self):
        pass
    def read(self, fileName:str):
        """Calls the read method from the ASCII art generator application (c4ascii.exe).

        param:
            fileName(str): A file name.
        returns:
            (str): The message cointained in the ASCII art file.
        """
        self.command.append(os.path.join(self.path, fileName))
        result = subprocess.run(self.command, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        self.command.pop()
        return result.stdout