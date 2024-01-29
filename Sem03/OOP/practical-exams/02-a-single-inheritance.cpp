#include <iostream>
using namespace std;

class human {
    public:
    string name;
    void set_name(string human_name) {
        name = human_name;
    }
    void print_name() {
        cout<<"The name of this human is "<<name<<endl;
    }
};

class employee: public human {
    int salary;
    public:
    void set_salary(int salary_amount) {
        salary = salary_amount;
    }
    void print_salary() {
        cout<<"The salary of "<<name<<" is "<<salary<<endl;
    }
};

int main() {
    human h1;
    h1.set_name("Anurag Verma");
    h1.print_name();
    employee e1;
    e1.set_name("Elon Musk");
    e1.set_salary(10000000);
    e1.print_name();
    e1.print_salary();
    return 0;
}
