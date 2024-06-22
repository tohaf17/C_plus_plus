#include <iostream>
#include <limits>

using namespace std;

void Block1(){
    cout<<"Input the quantity of the range ";
    int n,sum=0,i=0;
    cin>>n;
    for (;i<n;i++)
    {
        cout<<"Input "<<i+1<<" element: ";
        int element;
        cin>>element;
        if(element%2==0){
            sum+=element;
        }
    }
    cout<<"Sum of the even elements of the range "<<sum;
}

void Block2(){
    int maxNumber=numeric_limits<int>::min(),
    maxNumberIndex=-1,currentIndex=0,number;
    cout<<"Input numbers of the range "<<endl;
    while(cin>>number&&number!=0){
        if(number>maxNumber){
            maxNumber=number;
            maxNumberIndex=currentIndex;
        }
        currentIndex++;
    }
    if(maxNumberIndex!=-1){
        cout<<"Max element "<<maxNumber<<" has index "<<maxNumberIndex+1;
    }
}

void Block3(){
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int Number = numeric_limits<int>::min();
    int NumberIndex = -1;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter element " << i + 1 << ": ";
        int element;
        std::cin >> element;
            if (element < 0 && NumberIndex == -1) {
                Number = element;
                NumberIndex = i;
            }
    }

    if (Number != numeric_limits<int>::min()) {
        std::cout << "The first negative number " << Number << " is at position " << NumberIndex + 1 << " in the sequence." << std::endl;
    } else {
        std::cout << "No negative numbers found." << std::endl;
    }
}

int main() {
    int choice;
    do{
        cout<<"\nInput the 1 for the first block"<<endl;
        cout<<"Input the 2 for the first block"<<endl;
        cout<<"Input the 3 for the first block"<<endl;
        cout<<"Input the 0 for the end"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"The first block: "<<endl;
            Block1();
            break;
        case 2:
            cout<<"The second block: "<<endl;
            Block2();
            break;
        case 3:
            cout<<"The third block: "<<endl;
            Block3();
            break;
        case 0:
            cout<<"End";
            break;
        default:
            cout<<"M?";
            break;
        }
    }
    while(choice!=0);
    return 0;
}
