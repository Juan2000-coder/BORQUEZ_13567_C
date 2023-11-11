#include <iostream>
#include "C5Requirement.h"
#include <ctime>

using namespace std;

int main(){
    try{
        //Prueba de Constructores
        C5Requirement req1;
        time_t currentTime_t = chrono::system_clock::to_time_t(req1.getInitialTime());
        cout << ctime(&currentTime_t) <<endl;
        req1.setUserId(3);
        cout << req1.getUserId()<<endl;
        C5Requirement req2;
        currentTime_t = chrono::system_clock::to_time_t(req2.getInitialTime());
        cout << ctime(&currentTime_t) <<endl;
        req2.setUserId(3);
        cout << req2.getUserId()<<endl;
        //auto numbere1 = req1.getNumber<int>();
        auto numbere2 = req1.getRecent<int>();
        req1.appendNumber<int>(1, 3);
        try{
            auto number1e = req1.getNumber<double>();
        }
        catch(std::bad_variant_access &e){
            cerr << e.what() << endl;
        }
        auto number1 = req1.getNumber<int>();
        cout << number1.getValue() << endl;
        cout << number1.getBmax() << endl;
        cout << number1.getBmin() << endl;
        cout << number1.getTime() << endl;
        cout << number1.getOrdinal() << endl;
        cout << number1.getType() << endl;

        req1.appendNumber<double>(1.1, 5.5);
        auto number2 = req1.getNumber<double>();
        cout << number2.getValue() << endl;
        cout << number2.getBmax() << endl;
        cout << number2.getBmin() << endl;
        cout << number2.getTime() << endl;
        cout << number2.getOrdinal() << endl;
        cout << number2.getType() << endl;

        req1.appendNumber<int>();
        auto number3 = req1.getNumber<int>();
        cout << number3.getValue() << endl;
        cout << number3.getBmax() << endl;
        cout << number3.getBmin() << endl;
        cout << number3.getTime() << endl;
        cout << number3.getOrdinal() << endl;
        cout << number3.getType() << endl;

        auto number4 = req1.getRecent<double>();
        cout << number4.getValue() << endl;
        cout << number4.getBmax() << endl;
        cout << number4.getBmin() << endl;
        cout << number4.getTime() << endl;
        cout << number4.getOrdinal() << endl;
        cout << number4.getType() << endl;

        //probablemente tirar excepciones
        //req1.appendNumber(10);//esta debería tirar exceptión porque no se indica rango previo
        //C5Requirement req3(3.3);
        /*en realidad no tira excepción, hace la conversión directa en el llamado*/

        /*
        req1.appendNumber<double>();
        auto number4 = req1.getNumber<int>();
        cout << number4.getValue() << endl;
        cout << number4.getBmax() << endl;
        cout << number4.getBmin() << endl;
        cout << number4.getTime() << endl;
        cout << number4.getOrdinal() << endl;
        cout << number4.getType() << endl;*/
    }
    catch(exception &e){
        cout << e.what() << endl;
    }
    return EXIT_SUCCESS;
}