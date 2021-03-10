#include <iostream>
#include "LinkList.h"

using namespace std;
using namespace DTLib;
int main(){
    cout << "main begin" << endl;
    LinkList<int>L;
    for(int i=0;i<5;i++){
        L.insert(0,i);
    }
    for(int i=0;i<5;i++){
        cout << L.get(i)<< endl;
    }
    cout << "***********" << endl;
    L.remove(4);
    for(int i=0;i<L.length();i++){
        cout << L.get(i)<< endl;
    }
    cout << "&************" << endl;
    L.set(0,200);
    for(int i=0;i<4;i++){
        cout << L.get(i)<< endl;
    }
    cout << "&************" << endl;
    /*L.clear();
    for(int i=0;i<5;i++){
        cout << L.get(i)<< endl;
    }*/
    cout << "&************" << endl;
    LinkList<int>L2;
    L2 = L;
    for(int i=0;i<4;i++){
        cout << L2.get(i)<< endl;
    }
    cout << "&************" << endl;
    return 0;
}

