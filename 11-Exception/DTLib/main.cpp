#include <iostream>
#include "Exception.h"

using namespace std;
using namespace DTLib;

int main()
{
    try{
        //THROW_EXCEPTION(ArithmeticException, "Test");
        //throw ArithmeticException("Test", __FILE__, __LINE__);
        THROW_EXCEPTION(Exception, "Test");
    }
    catch (const ArithmeticException &e){
        cout << "catch (const ArithmeticException &e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    catch (const Exception &e){
        cout << "catch (const Exception &e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    return 0;
}
/*
��������
catch (const ArithmeticException &e)
Test
..\Exception\main.cpp:11
*/
