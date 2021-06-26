#include<iostream>
#include<iomanip>
#include<cmath>

#define f(x) exp(-x)-5

using namespace std;

float Equation(float X, float Xn, float fX, float fXn)
{
    return (Xn - ((Xn-X)/(fXn - fX)) * fXn);
}

void Display(float X,float Xn, float fX, float fXn, float Xnew, float error)
{
    static int i = 1;
    cout<<left<<setw(15)<<i
        <<setw(15)<<X
        <<setw(15)<<Xn
        <<setw(15)<<fX
        <<setw(15)<<fXn
        <<setw(15)<<Xnew
        <<setw(15)<<error<<endl;
    i++;
}

int main()
{
    float X,Xn,fX,fXn,Xnew,Error;
    X = -2.0;
    Xn = 0.0;
    cout<<left<<setw(15)<<"Iteration"
        <<setw(15)<<"Xn-1"
        <<setw(15)<<"f(Xn-1)"
        <<setw(15)<<"Xn"
        <<setw(15)<<"f(Xn)"
        <<setw(15)<<"Xn+1"
        <<setw(15)<<"Error"<<endl;
    do {
        fX = f(X);
        fXn = f(Xn);
        Xnew = Equation(X,Xn,fX,fXn);
        Error = (Xnew - Xn) / Xnew;
        Error < 0.0 ? Error = -Error : Error;
        Display(X,Xn,fX,fXn,Xnew,Error);
        
        X = Xn;
        Xn = Xnew;
    } while(Error > 0.005);      
    cout<<endl<<"Fixed Root is "<<setprecision(4)<<Xn;
}