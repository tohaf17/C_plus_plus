#include <iostream>
#include <vector>
#include <sstream>
#include <limits>


std::vector<int> Random(){
    std::cout<<"How many numbers do you want to see in array ";
    int numRandom;
    std::cin>>numRandom;
    std::vector<int> myArray(numRandom);
    for(int i=0;i<numRandom;i++){
        myArray[i]=std::rand()%(numRandom-(-numRandom)+1)-numRandom;
    }
    return myArray;
}
std::vector<int> ByYourselfOneLine(){
    std::cout<<"Input numbers ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
    std::string numbers;
    std::getline(std::cin, numbers);

    std::stringstream ss(numbers);
    std::vector<int> myArray;
    int number;

    while (ss >> number) {
        myArray.push_back(number);
    }
    return myArray;
}

std::vector<int> ByYourselfManyLines(){
    std::cout<<"How many numbers do you want to see in array ";
    int numManyLines;
    std::cin>>numManyLines;
    std::cout<<"Input numbers\n";
    std::vector<int> myArray;
    for(int i=0;i<numManyLines;i++){
        std::cin>>myArray[i];
    }
    return myArray;
}
void PrintArray(const std::vector<int>& array){
    std::string str;
    for(const auto& i:array){
        str += std::to_string(i) + " ";
    }
    std::cout<<str<<std::endl;
} 
std::pair<int,int> MaxAndMinOfArray(const std::vector<int>& array){
    int minIndex{0},maxIndex{0};
    for(int i=1;i<array.size();i++){
        if(array[i]>array[maxIndex]){
            maxIndex=i;
        }
        if(array[i]<array[minIndex]){
            minIndex=i;
        }
    }
    return {maxIndex,minIndex};
}
int SumArray(int max,int min,const std::vector<int>& array) {
    int sum{0};
    if(min<max){
        for(int i=min+1;i<max;i++){
            sum+=array[i];
        }
    }
    else{
        for(int i=max+1;i<min;i++){
            sum+=array[i];
        }
    }
    return sum;
}

void Summary(const std::vector<int>& myArray){
    auto [max,min]=MaxAndMinOfArray(myArray);
    
    int result{SumArray(max,min,myArray)};
    std::cout<<"Sum of the numbers between max and min is "<<result;
}
int main(){
    std::cout << "How do you want to fill the array: randomly (1) or not (2)? ";
    int choiceFirst;
    std::cin >> choiceFirst;
    std::vector<int> myArray;
    if (choiceFirst == 1) {
        myArray = Random();
        std::cout << "Our array:\n";
        PrintArray(myArray);
        Summary(myArray);
    } else if (choiceFirst == 2) {
        std::cout << "One line (1) or many lines (2)? ";
        int choiceSecond;
        std::cin >> choiceSecond;
        if (choiceSecond == 1) {
            myArray = ByYourselfOneLine();
        } else if (choiceSecond == 2) {
            myArray = ByYourselfManyLines();
        }
        PrintArray(myArray);
        Summary(myArray);
    }

    return 0;

}
