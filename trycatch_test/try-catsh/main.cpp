#include <iostream>

using namespace std;

double devide(double a,double b){
    const double delta = 0.00000000001;
    double ret = 0;
if( !((-delta < b) && (b < delta)) ) {
        ret = a / b;
    }else{
        throw 0; //产生了除0异常,C++ 通过 throw 语句抛出异常
    }            //throw 抛出的异常必须被 catch 处理
    return ret;  //当前函数能够处理异常，程序继续往下执行
}                //当前函数无法处理，则函数停止执行,并返回
//未被处理的异常会沿着函数调用栈向上传播，直到被处理为止，否则程序将停止执行。

void demo1(){
    try{
        throw 'c';
    }catch(char c){
        cout << "catch (char c)" << endl;
    }catch(int i){
        cout << "catch (int i)" << endl;
    }catch(double d){
        cout << "catch (double d)" << endl;
    }
}

void demo2(){
    throw "D.T.Software";
}



int main(){
    try{    //try 语句处理正常代码逻辑,try 语句中的异常由对应的 catch 语句处理
        double r = devide(1,0);
        cout << r << endl;
    }catch(...){  //catch 语句处理异常代码逻辑
         cout << "Divided by zero ..." << endl;//输出：Divided by zero ...
    }
    demo1();//输出：catch (char c)

    try{
         demo2();
    }catch(char*c){
        cout << "catch(char*c)" << endl;
    }catch(const char* cc){
        cout << "catch(const char* cc)" << endl;//输出：catch(const char* cc)
    }catch(...){
        cout << "catch(...)" << endl;
    }

    return 0;
}
