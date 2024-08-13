#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    //Iterator On Maps
    unordered_map<string, int> mp;
    mp["abc1"] = 1;
    mp["abc2"] = 2;
    mp["abc3"] = 3;
    mp["abc4"] = 4;
    mp["abc5"] = 5;
    mp["abc6"] = 6;
    
    // Intialize Iterator
    unordered_map<string, int>:: iterator it = mp.begin();
    while(it != mp.end()){
        cout<<"Key:- "<<it->first<<" value:- "<<it->second<<endl;
        it++;
    }
    
    // find function
    unordered_map<string, int>:: iterator it0 = mp.find("abc1");
    cout<<it0->first<<" "<<it0->second<<endl;
    
    // erase function
    // delete first two element
    unordered_map<string, int>:: iterator it10 = mp.begin();
    mp.erase(it10);
    it10++;
    
    unordered_map<string, int>:: iterator it11 = mp.begin();
    cout<<"After Erase:- "<<endl;
    while(it11 != mp.end()){
        cout<<"Key:- "<<it11->first<<" value:- "<<it11->second<<endl;
        it11++;
    }
    
    // iterator on vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int> :: iterator it1 = v.begin();
    cout<<"Print Vector:- "<<endl;
    while(it1 != v.end()){
        cout<<*it1<<endl;
        it1++;
    }
    
    return 0;
}
