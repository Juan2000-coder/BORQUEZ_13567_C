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
class fileException(Exception):
    """A class for C4File specific exception."""
    def __init__(self, message):
        super().__init__(message)

class C4File:
    def readLine(self):
        """Obtain the next line in the file if it has been oppened.

        returns:
            (str) the next line in the file."""
        
        if not self.file == None:
            line = self.file.readline()
            line = line.rstrip('\n')    # Discards new line scape sequences.
            return line
        else:       # Throws an exception if the file hasn't been oppened.
            raise fileException("Archivo no abierto")
        
    def __init__(self, route:str, fileName:str):
        """Doesn't actually open the file. Only sets the file name and the route.
        Up to this point, no verification of the existence of the file has been done.

        args:
            route(str): A route to the directory of the file.
            fileName (str): The name of the supposed file in the route."""

        self.fileName = fileName
        self.fileFullName = os.path.join(route, fileName)
        self.file = None 
        

    def __enter__(self):
        """ It actually opens the file when a with context is accessed
        if a valid fileName has been given to the constructor. """

        self.file = open(self.fileName, newline = '')
        # May Throw an exception if the file doesn't exist.

        return self
    
    def __exit__(self, exc_type, exc_value, traceback):
        """Conext method, invoqued at the end of a with context."""

        self.file.close()
        self.file = None