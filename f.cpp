#include<iostream>
using namespace std;

int p=1;
int factorial(int n)
{
    if(n==0)
    {
        return p;
    }
    p=p*n;
    factorial(n-1);
}
int main()
{
    int n;
    cout<<"enter Number:";
    cin >> n;
    cout<<"Factorial of "<<n<<" is: "<<factorial(n);
    
return 0;
}
