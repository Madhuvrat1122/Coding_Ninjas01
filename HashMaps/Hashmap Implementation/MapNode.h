#include<string>
using namespace std;
template <typename V>
class MapNode {
  public:
    string key;
    V value;
    MapNode* next;
    // constructor
    MapNode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    // Destructor
    ~MapNode(){
        delete next;
    }
};
