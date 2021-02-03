#include <iostream>

using namespace std;

double devide(double a,double b){
    const double delta = 0.00000000001;
    double ret = 0;
if( !((-delta < b) && (b < delta)) ) {
        ret = a / b;
    }else{
        throw 0; //�����˳�0�쳣,C++ ͨ�� throw ����׳��쳣
    }            //throw �׳����쳣���뱻 catch ����
    return ret;  //��ǰ�����ܹ������쳣�������������ִ��
}                //��ǰ�����޷���������ִֹͣ��,������
//δ��������쳣�����ź�������ջ���ϴ�����ֱ��������Ϊֹ���������ִֹͣ�С�

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
    try{    //try ��䴦�����������߼�,try ����е��쳣�ɶ�Ӧ�� catch ��䴦��
        double r = devide(1,0);
        cout << r << endl;
    }catch(...){  //catch ��䴦���쳣�����߼�
         cout << "Divided by zero ..." << endl;//�����Divided by zero ...
    }
    demo1();//�����catch (char c)

    try{
         demo2();
    }catch(char*c){
        cout << "catch(char*c)" << endl;
    }catch(const char* cc){
        cout << "catch(const char* cc)" << endl;//�����catch(const char* cc)
    }catch(...){
        cout << "catch(...)" << endl;
    }

    return 0;
}
