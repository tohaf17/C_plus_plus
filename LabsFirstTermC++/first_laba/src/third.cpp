#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

int main(){
    locale culture=locale::classic();
    locale::global(culture);
    cout.imbue(culture);

    double x,y;
    cin>>x;
    cin>>y;
    if(abs(x)<=3&&abs(y)<=2&&!((x*x+y*y)<1)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}