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
from C4 import C4

if __name__ == "__main__":
    commandLine = C4()
    commandLine.prompt = '->'
    commandLine.cmdloop('Entrada de comandos')