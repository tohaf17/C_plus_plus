#include <iostream>
#include <cmath>
#include <list>
#include <tuple>

using namespace std;

double CalcTriangleByPoints(int null1,int null2,int a,int b,int x,int y){
    return abs(((null1*b+a*y+x*null2)-(null2*b+b*x+y*null1))/2.0);
}
auto CalcMinSquares(int a,int b){
    list <tuple <int,int>> coordinatesMin;
    double minSquare;
    minSquare=numeric_limits<double>::max();

    for(int i=a,j=b;i>=-1||j>=-1;i--,j--){
        double current{CalcTriangleByPoints(0,0,a,b,i+1,j)};
        if(current==minSquare&&current!=0){
            coordinatesMin.push_back(make_tuple(i+1,j));
            coordinatesMin.push_back(make_tuple(i-1,j));
        }
        if(current<minSquare&&current!=0){
            minSquare=current;
            coordinatesMin.clear();
            coordinatesMin.push_back(make_tuple(i+1,j));
            coordinatesMin.push_back(make_tuple(i-1,j));
        }
    }
    for(int i=a,j=b;i>=-1||j>=-1;i--,j--){
        double current{CalcTriangleByPoints(0,0,a,b,i,j+1)};
        if(current==minSquare){
            coordinatesMin.push_back(make_tuple(i,j+1));
            coordinatesMin.push_back(make_tuple(i,j-1));
        }
        if(current<minSquare){
            minSquare=current;
            coordinatesMin.clear();
            coordinatesMin.push_back(make_tuple(i,j+1));
            coordinatesMin.push_back(make_tuple(i,j-1));
        }
    }
    return coordinatesMin;
}
int main() {
    cout<<"Input coordinates of the point B: "<<endl;
    int a,b;
    cout<<"x: ";
    cin>>a;
    cout<<"y: ";
    cin>>b;

    list<tuple <int,int>> coordinatesMin=CalcMinSquares(a,b);
    cout<<"Now, the output of points\n";
    
     for (const auto& pair : coordinatesMin) {
        
            cout << "(" << get<0>(pair) << ", " << get<1>(pair) << ")" << endl;
        
    }
    

}
