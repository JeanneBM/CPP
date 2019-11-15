#include <iostream>

using namespace std;

class foo{
  public:
  foo(int a) : a(a) {cout << "parametric " << a <<endl;}
  void print() { cout << a << endl; }
  
  foo& operator+=(const foo& f)
  {
    cout << "+= " << this->a << " " << f.a << endl;
    if(this != &f)
     a+=f.a;
    return *this;
  }
  foo operator+(const foo& lewy)
  {
    cout << "+" << this->a << " " << lewy.a << endl;
    foo tmp = *this;
    tmp += lewy;
    return tmp;
  }
  
  private:
  int a;
};

int main(){
  foo f1(3), f2(2);
  foo f3=f1;  
  f1.print();
  f2.print();
  f3.print();
  cout << &f1 << " " << &f2 << " " << &f3 << endl;
  f3 = f1 + f2;
  f1.print();
  f2.print();
  f3.print();
  cout << &f1 << " " << &f2 << " " << &f3 << endl;
}
