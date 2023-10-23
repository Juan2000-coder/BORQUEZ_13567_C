#include "C5Number.h"
#include <iostream>
#include <string>

using namespace std;

int main(void){
    try{
        C5Number<int> number1(1, 2, 30);
        C5Number<double> number2(3.3, 5.5, 30);
        cout << number1.getValue() << endl;
        cout << number2.getValue() << endl;
        cout << number1.getBmin() << endl;
        cout << number2.getBmin() << endl;
        cout << number1.getBmax() << endl;
        cout << number2.getBmax() << endl;
        cout << number1.getType() << endl;
        cout << number2.getType() << endl;
        cout << number1.getTime() << endl;
        cout << number2.getTime() << endl;
        number1.setOrdinal(1);
        number2.setOrdinal(2);
        cout << number1.getOrdinal() << endl;
        cout << number2.getOrdinal() << endl;

        /*Prueba de errores/excepciones*/
        //C5Number<int> number3(3, 2);//check
        //C5Number<double> number4(5.5, 2.2);//check
        //C5Number<string> number5("hola", "hola");//ckeck
    }
    catch(exception &e){       
        cerr<<e.what()<<endl;
    }
    return EXIT_SUCCESS;
}
