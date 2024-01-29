#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<< " ";
        cout<<vec.at(i)<< " ";
    }
}

int main() {
    vector<int> vec1;
    int element, size;   
    cout<<"Enter the size of your vector: ";
    cin>>size;
    for(int i=0; i < size; i++) {
        cout<<"Enter element number " << i << ": ";
        cin>>element;
        vec1.push_back(element);
    }
    // cout<<"Removing the last element"<<endl;
    // vec1.pop_back();
    vector<int>::iterator iter = vec1.begin();
    display(vec1);
    cout<<endl;
    vec1.insert(iter, 100);
    display(vec1);
    return 0;
}