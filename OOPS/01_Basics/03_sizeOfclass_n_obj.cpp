#include<iostream>
using namespace std;

class a{
    int b;
    char c;
// Size = 8 but expected is 5, This is because of concept padding

};

int main(){

    a obj;
    cout<<sizeof(obj)<<" ";  // if class is empty size of object - 1 Byte

}