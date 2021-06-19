#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float Equation(float x)
{
    return (log(x) + 6 * x - 5);
}

void Display(float xu, float xl, float xm, float error)
{
    static int i = 1;
    cout<<left<<setw(5)<<i
        <<setw(10)<<xu
        <<setw(15)<<Equation(xu)
        <<setw(10)<<xl
        <<setw(15)<<Equation(xl)
        <<setw(10)<<xm
        <<setw(15)<<Equation(xm)
        <<setw(10)<<error<<endl;
    i++;
}

int main()
{
    float Xu,Xl,Xm,xOld,xNew,xMid,Error;
    Xu = 1;
    Xl = 0.5;
    xOld = Xl;
    cout<<left<<setw(5)<<"S.N"
        <<setw(10)<<"Xu"
        <<setw(15)<<"f(Xu)"
        <<setw(10)<<"Xl"
        <<setw(15)<<"f(Xl)"
        <<setw(10)<<"Xm"
        <<setw(15)<<"f(Xm)"
        <<setw(10)<<"Error"<<endl;
    do {
        Xm = (Xu + Xl) /2;
        xNew = Xm;
        xMid = Equation(Xm);
        
        Error = (xNew - xOld) / xNew;
        Error < 0.0 ? Error = -Error : Error;
        Display(Xu,Xl,Xm,Error);

        if(xMid > 0.0) {
            Xu = Xm;
            xOld = Xl;
        }
        else {
            Xl = Xm;
            xOld = Xu;
        }
        if((Equation(Xu) > 0 && Equation(Xl) > 0) || (Equation(Xu) < 0 && Equation(Xl) < 0)) {
            cout<<endl<<"f(Xu) & f(Xl) doesn't have opposite sign"<<endl;
            exit(0);
        }
    } while(Error > 0.05);      
    cout<<endl<<"Fixed Root is "<<setprecision(1)<<Xm;
}