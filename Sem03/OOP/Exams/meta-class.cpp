#include <iostream>
using namespace std;

template <typename T>
class Meta
{
public:
  Meta(const T &init) : mData(init) {}
  // ...
private:
  T mData;
};

int main(int, char **)
{
  cout << "The size of Meta<double> is " << sizeof(Meta<double>) << endl;
  cout << "The size of double is " << sizeof(double) << endl;
  return 0;
}