#include <iostream>
#include "Pair.cpp"
using namespace std;
int main()
{
    // integer
    // Pair<int> p1;
    // p1.setX(10);
    // p1.setY(20);
    // cout<<p1.getX()<< " " <<p1.getY()<<endl;
    
    // chaaractor
    // Pair<char> p2;
    // p2.setX('a');
    // p2.setY('b');
    // cout<<p2.getX()<< " " <<p2.getY()<<endl;
    
    // Differnet type
    Pair<int, double> p3;
    p3.setX(10);
    p3.setY(20.5);
    cout<<p3.getX()<<" "<<p3.getY()<<endl;
    
    // Triplets from pair of pair (pair chaining)
    Pair<int, double> p4;
    p4.setX(100);
    p4.setY(124.5);
    Pair<Pair<int, double>, char> p5;
    p5.setX(p4);
    p5.setY('a');
    cout<<p5.getX().getX()<<" "<<p5.getX().getY()<<" "<<p5.getY();

    return 0;
}
