#include <iostream>
using namespace std;
    

int largest_number(int firstNum, int secondNum) {
    if (firstNum > secondNum)
    {
        return firstNum;
    }
    else if (firstNum < secondNum)
    {
        return secondNum;
    }
    else {
        return firstNum;
    }
}

int main(){
    int num1, num2;
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter first number: ";
    cin>>num2;
    cout<<"Largest of the two given numbers is: " <<largest_number(num1, num2);
    return 0;
}