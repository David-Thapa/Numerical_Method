#include<iostream>
#include<iomanip>
#include<cmath>

#define f(x) exp(-x)-5
#define df(x) -exp(-x)

using namespace std;

float Equation(float x,float fx,float dfx)
{
    return (x - (fx / dfx));
}

void Display(float x,float fx, float dfx, float xn, float error)
{
    static int i = 1;
    cout<<left<<setw(15)<<i
        <<setw(15)<<x
        <<setw(15)<<fx
        <<setw(15)<<dfx
        <<setw(10)<<xn
        <<setw(10)<<error<<endl;
    i++;
}

int main()
{
    float X,Xn,fx,dfx,Error;
    X = -2.0;
    cout<<left<<setw(15)<<"Iteration"
        <<setw(15)<<"X"
        <<setw(15)<<"f(X)"
        <<setw(15)<<"df(X)"
        <<setw(10)<<"Xn+1"
        <<setw(10)<<"Error"<<endl;
    do {
        fx = f(X);
        dfx = df(X);
        Xn = Equation(X,fx,dfx);
        Error = (Xn - X) / Xn;
        Error < 0.0 ? Error = -Error : Error;
        Display(X,fx,dfx,Xn,Error);
        X = Xn;
    } while(Error > 0.05);      
    cout<<endl<<"Fixed Root is "<<setprecision(2)<<Xn;
}