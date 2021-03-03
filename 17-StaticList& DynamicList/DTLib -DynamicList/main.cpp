#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"
using namespace std;
using namespace DTLib;

int main(){
    cout << "main begin" << endl;

    DynamicList<int>sl(5);


    for (int i = 0; i < sl.capacity(); ++i){
         sl.insert(0, i);
    }

     for (int i = 0; i< sl.length(); ++i){
        cout << sl[i] << endl;
     }

     cout << "--------------" << endl;
     sl[0] *= sl[0];

        for (int i = 0; i< sl.length(); ++i)
        {
            cout << sl[i] << endl;
        }

        cout << "--------------" << endl;
        try
            {
               sl[5] = 5;
            }
            catch (const Exception &e)
            {
                cout << e.message() << endl;
                cout << e.location() << endl;

                sl.resize(10);
                sl.insert(5, 50);
            }

            for (int i = 0; i< sl.length(); ++i)
            {
                cout << sl[i] << endl;
            }

            cout << "--------------" << endl;

            sl.resize(3);
            for (int i = 0; i< sl.length(); ++i)
            {
                cout << sl[i] << endl;
            }

            cout << "main end" << endl;

    return 0;
}

