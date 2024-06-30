#include <iostream>
#include <chrono>
#include <string>

std::string FirstVariant(int n){
    std::string  str ="";
    for(int i=1;i<=n;i++){
        str+=std::to_string(i)+" ";
    }
    return str;
}
std::string SecondVariant(int n){
    std::string  str ="";
    for(int i=n;i>=1;i--){
        str=std::to_string(i)+" "+str; 
    }
    return str;
}
std::string ThirdVariant(int n){
    std::string  str ="";
    for(int i=1;i<=n;i++){
        str.append(std::to_string(i)+ " ");
    }
    return str;
}
std::string FourthVariant(int n){
    std::string  str ="";
    for(int i=1;i<=n;i++){
        str.append(std::to_string(i)+ " ");
    }
    return str;
}
int main() {
    std::cout<<"Input the number ";
    int number,variant;
    std::cin>>number;
    std::cout<<"Input the variant ";
    std::cin>>variant;
    auto start=std::chrono::high_resolution_clock::now();
    switch(variant){
        case 1:
        std::cout<<FirstVariant(number);
        break;
        case 2:
        std::cout<<SecondVariant(number);
        break;
        case 3:
        std::cout<<ThirdVariant(number);
        break;
        case 4:
        std::cout<<FourthVariant(number);
        break;
    }
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration=end-start;
    std::cout<<"\nTime is "<<duration.count();
}
