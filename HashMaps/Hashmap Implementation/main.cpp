#include <iostream>
#include "Map.h"
using namespace std;

int main()
{
    Map<int> mp;
    
    mp.insert("Alok", 10);
    mp.insert("Madhu", 20);
    
    // cout<<"Size:- "<<mp.size()<<endl; // 2
    // cout<<mp.search("Madhu")<<endl; // 20
    // cout<<mp.search("Nannu")<<endl; // -1
    
    // Deletion Test
     mp.insert("abc0", 30);
     mp.insert("abc1", 40);
     mp.insert("abc2", 50);
     
     cout<<"Before Delete:- "<<mp.search("abc0")<<endl; // 30
     int deletedValue = mp.remove("abc0");
     cout<<"After Deleting "<<deletedValue<<":- "<<mp.search("abc0")<<endl; // -1
    
    
    return 0;
}
