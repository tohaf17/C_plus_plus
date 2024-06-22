#include <iostream>
#include <locale>
#include <cmath>

using namespace std;
int main(){
    locale currentLocale=locale::classic();
    locale::global(currentLocale);
    cout.imbue(currentLocale);

    double x,result;
    cin>>x;
    result=sqrt(x+pow(abs(x),1/4.0))+abs(x);
    cout<<result<<endl;
}