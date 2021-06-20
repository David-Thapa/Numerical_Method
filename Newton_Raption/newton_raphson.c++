#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

void Question1(float x, float &fx, float &dfx)
{
    fx = log(x) + 6*x - 5;
    dfx = (1/x) + 6;
}

void Question2(float x, float &fx, float &dfx)
{
    fx = cos(x) + 5*x*x - 3*x - 5;
    dfx = -sin(x) + 10*x - 3;
}

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
    X = 2;
    cout<<left<<setw(15)<<"Iteration"
        <<setw(15)<<"X"
        <<setw(15)<<"f(X)"
        <<setw(15)<<"df(X)"
        <<setw(10)<<"Xn+1"
        <<setw(10)<<"Error"<<endl;
    do {
        Question1(X,fx,dfx);
        Xn = Equation(X,fx,dfx);
        Error = (Xn - X) / Xn;
        Error < 0.0 ? Error = -Error : Error;
        Display(X,fx,dfx,Xn,Error);
        X = Xn;
    } while(Error > 0.05);      
    cout<<endl<<"Fixed Root is "<<setprecision(2)<<Xn;
}