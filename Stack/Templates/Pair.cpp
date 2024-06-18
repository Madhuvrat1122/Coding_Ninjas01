
#include <iostream>
using namespace std;
// template<typename T>
template<typename T, typename V>
class Pair {
    T x;
    // T y;
    V y;
    public:
    void setX(T x){
        this->x = x;
    }
    void setY(V y){
        this->y = y;
    }
    T getX(){
        return x;
    }
    V getY(){
        return y;
    }
};
