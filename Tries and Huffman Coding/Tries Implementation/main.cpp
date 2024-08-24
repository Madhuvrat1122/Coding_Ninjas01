#include <iostream>
#include "Trie.h"
using namespace std;

int main()
{
    Trie t;
    
    t.insertWord("Alok");
    t.insertWord("AlokA");
    t.insertWord("AlokB");
    
    
    cout<<t.searchWord("AlokB")<<endl; // 1
    
    t.removeWord("AlokB");
    
    cout<<t.searchWord("AlokB")<<endl; // 0
    
    return 0;
}
