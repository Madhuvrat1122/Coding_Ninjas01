#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> mp;
    
    // insertion
    // 1th way
    pair<string, int> p("abc", 1);
    mp.insert(p);
    // 2nd way
    mp["def"] = 2;
    
    // Find/Access
    // one way
    cout<<mp["abc"]<<endl;
    cout<<mp["za"]<<endl; // 0 => not exist so it will insert it with default value 0
    // second way
    cout<<mp.at("abc")<<endl;
    // cout<<mp.at("tyu")<<endl; // Exception => not exist
    
    // check presence of key
    if(mp.count("tre") > 0){ // will not go inside since key doesn't exist
        cout<<mp["tre"];
    }
  
    return 0;
}
