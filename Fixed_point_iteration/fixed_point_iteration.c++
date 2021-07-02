#include<iostream>
#include<iomanip>
#include<cmath>

#define f(x) x - exp(-x)
#define g(x) exp(-x)

using namespace std;

void Display(float X, float Xn, float error)
{
    static int i = 1;
    cout<<left<<setw(15)<<i
        <<setw(15)<<X
        <<setw(15)<<Xn
        <<setw(15)<<error<<endl;
    i++;
}

int main()
{
    float X,Xn,Error;
    X = 2.0;
    cout<<left<<setw(15)<<"Iteration"
        <<setw(15)<<"Xn"
        <<setw(15)<<"Xn+1"
        <<setw(15)<<"Error"<<endl;
    do {
        Xn = g(X);
        Error = (Xn - X) / Xn;
        Error < 0.0 ? Error = -Error : Error;
        Display(X,Xn,Error);
        
        X = Xn;
    } while(Error > 0.005);      
    cout<<endl<<"Fixed Root is "<<setprecision(4)<<Xn;
}