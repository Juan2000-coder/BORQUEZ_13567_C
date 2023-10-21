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

from cmd import Cmd
import os
import subprocess
import platform
import json
from prettytable import PrettyTable

from C4File import C4File
from C4File import fileException
from C4Text import C4Text
from asciiGenerator import asciiGenerator

class commandException(Exception):
    """A class for specific C4 class exceptions."""

    def __init__(self, message):
        super().__init__(message)

class C4(Cmd):
    """Command Interpreter. Interface with user."""

    doc_header = "Ayuda para comandos documentados."
    undoc_header = "Comandos no documentados."
    marginLevel = 5                      # Left Margin for output
    outFormat = ' '*marginLevel + "{}"   # Left Margin string for use with format()

    def __init__(self):
        """A list is used to contain C4Text objects so that the same text object
        is no created multiple times. This way, if a command requires creating
        a text object for a file that has already been opened recently, that object
        is obtained directly from the list."""

        super().__init__()
        self.route = os.getcwd()    # The path of the solution.

        self.texts = []             # A list containing C4Text objects.
        self.numberOfTexts = 5      # The maximum number of objects in the previous list.
        self.textsListFull = False  # A flag indicating if the list is full.

    def do_listdir(self, args):

        """
Muestra el nombre de los archivos en el directorio.
listdir [-e EXTENSION]
    -e      Muestra los archivos con la extension indicada por EXTENSION (.txt ie)
        """
        
        arguments = args.split()
        print()
        try:
            for fileName in os.listdir(self.route):
                if len(arguments) > 0:
                    if arguments[0] == '-e':
                        if not (fileName[-len(arguments[1]):] == arguments[1]):
                            continue
                    else:
                        raise commandException("Opcion de comando no encontrada.")
                print(self.outFormat.format(fileName))
        except commandException as e:
            print(self.outFormat.format(e))
        except Exception as e:
            print(self.outFormat.format(e))
        finally:
            print()
    
    def do_cls(self, args):

        """
Limpia la pantalla.
cls
        """

        if platform.system() == 'Windows':
            subprocess.call('cls', shell = True)
        else:
            subprocess.call('clear', shell = True)

    def do_display(self, args):

        """
Muestra por pantalla el contenido de una lista de archivos de arte ASCII.
display archivo1.txt archivo2.txt ...
    archivo1.txt archivo2.txt ...      Una lista de archivos de arte ASCII.
        """
        print()
        try:
            arguments = args.split()
            if self.verifyFileName(arguments):
                for fileName in arguments:
                    print(self.outFormat.format(fileName))
                    """
                    # Altertnative solution in case the other one is not accepted.

                    asciiText = self.getText(fileName)
                    print(asciiText)
                    """
                    if platform.system() == 'Windows':
                        subprocess.call("type " + fileName, shell = True)
                    else:
                        subprocess.call('cat '+ fileName, shell = True)
                    print()
        except commandException as e:
            print(self.outFormat.format(e))
        except FileNotFoundError as e:
            print(self.outFormat.format(f"El archivo {e.filename} no se encontró."))
        except Exception as e:
            print(self.outFormat.format(e))
        finally:
            print()
    
    def do_mkreport(self, args):

        """
Realiza el reporte de los archivos de arte ASCII indicados.
mkreport archivo1.txt archivo2.txt ...
    archivo1.txt archivo2.txt ...      Una lista de archivos de arte ASCII.
        """
        print()
        try:
            arguments = args.split()
            if self.verifyFileName(arguments):
                for fileName in arguments:
                    asciiText = self.getText(fileName)
                    chs = asciiText.getChars()
                    chsCount = {}
                    lastCh = chs[-1]

                    table = PrettyTable()
                    table.field_names = ["CARACTER", "NUMERO DE OCURRENCIAS"]

                    for ch in chs:
                        chsCount[ch] = asciiText.getCount(ch)
                        if not (ch == lastCh):
                            table.add_row([ch, chsCount[ch]])
                        else:
                            table.add_row([ch, chsCount[ch]], divider = True)

                    table.add_row(['TOTAL', sum(chsCount.values())])
                    print(table.get_string(title = fileName))
                    print()

        except commandException as e:
            print(self.outFormat.format(e))
        except FileNotFoundError as e:
            print(self.outFormat.format(f"El archivo {e.filename} no se encontró."))
        except fileException as e:
            print(self.outFormat.format(e))
        except Exception as e:
            print(self.outFormat.format(e))
        finally:
            print()

    def do_listcoords(self, args):

        """
Muestra las coordenadas en el archivo de un carácter indicado por el usuario.
listcoords 'ch' archivo1 archivo2 ...
    ch                                 El caracter a buscar.
    archivo1.txt archivo2.txt ...      Una lista de archivos de arte ASCII.
        """
        print()
        try:
            if len(args) > 3:           # At least 3 for the query
                if args[0] == args[2] == '\'':
                    query = args[1]     # The query
                    arguments = args[3:].split()
                    if self.verifyFileName(arguments):
                        for fileName in arguments:
                            asciiText = self.getText(fileName)
                            print(self.outFormat.format(fileName))
                            print(json.dumps(asciiText.getCoords(query), indent = 2)) # JSON formatted output.
                            print()
                else:
                    raise commandException("Sintaxis de comando incorrecto.")
            else:
                raise commandException("Faltan argumentos para el comando.")
        except commandException as e:
            print(self.outFormat.format(e))
        except FileNotFoundError as e:
            print(self.outFormat.format(f"El archivo {e.filename} no se encontró."))
        except fileException as e:
            print(self.outFormat.format(e))
        except Exception as e:
            print(self.outFormat.format(e))
        finally:
            print()

    def do_ascii2text(self, args):
        """
Obtiene la representación en texto plano de un mensaje en ASCII art.
ascii2text archivo1.txt archivo2.txt ...
    archivo1.txt archivo2.txt ...      Una lista de archivos de arte ASCII.
        """
        print()
        try:
            arguments = args.split()
            if self.verifyFileName(arguments):
                asciiaux = asciiGenerator()
                for fileName in arguments:
                    cadena = asciiaux.read(fileName)
                    print(self.outFormat.format(fileName))
                    print(self.outFormat.format(cadena))
                    print()


        except commandException as e:
            print(self.outFormat.format(e))
        except FileNotFoundError as e:
            print(self.outFormat.format(f"El archivo {e.filename} no se encontró."))
        except fileException as e:
            print(self.outFormat.format(e))
        except subprocess.CalledProcessError as e:
            print(f"Error al ejecutar la aplicación de C++: {e}")
        except Exception as e:
            print(self.outFormat.format(e))
        finally:
            print()
        
    def do_exit(self, args):

        """
Termina la ejecucion del programa.
exit
        """

        raise SystemExit
    
    def verifyFileName(self, arguments: list):
        """Verifies if a file name has a .txt extension or not.
        If it doesn't have that extension, it's considered not an ASCII art file.

        args:
            arguments (list): A list of file Names.
        returns:
            (bool): True if the name corresponds to what an ASCII art file is considered to be.
        """
        if len(arguments) > 0:
            for fileName in arguments:
                if not (fileName[-4:] == ".txt"):
                    raise commandException("El archivo indicado no corresponde a un archivo de arte ASCII.")
        else:
            raise commandException("Debe indicar al menos el nombre de un archivo de arte ASCII.")
        return True
    
    def getText(self, fileName:str):
        """Given a fileName, it obtains the text object from the list if it already exists
        or creates a new object if no match is found.

        args.
            fileName(str): a file name string.
        returns:
            (C4Text): a text object for the file."""
        try:
            index = next(i for i, text in enumerate(self.texts) if text.fileName == fileName)
            asciiText = self.texts[index]   # A match is found.

        except StopIteration:               # if no match is found.

            asciiFile = C4File(self.route, fileName)
            asciiText = C4Text(asciiFile)   # May throw an exception if the file doesn´t exists.

            if not self.textsListFull:
                if len(self.texts) == self.numberOfTexts: # it means that the list is full.
                    self.textsListFull = True
            else:
                self.texts.pop(0)   # If the list is full the first object is discarded.

            self.texts.append(asciiText)    # Puts the new object in the list.
        return asciiText