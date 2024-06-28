#include <iostream>
#include <vector>
using namespace std;
int main() {
    // static allocatiom
    vector<int> v;
    // dynamic allocation
    // vector<int> *v = new vector<int>();
    
    // push into vector
    for(int i=0; i<10; i++){
        v.push_back(i+1);
    }
    
    // print vector element
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
        // cout<<v.at(i)<<endl;
    }
    
    // capacity
    cout<<"capacity:- "<<v.capacity()<<endl;
    // size
    cout<<"size:- "<<v.size()<<endl;

    return 0;
}
