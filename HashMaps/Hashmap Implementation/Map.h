#include "MapNode.h"
/** 
 * Time Complexity:-
 * Insertion = O(1)
 * Deletion = O(1)
 * Search = O(1)
*/
template <typename V>
class Map {
    MapNode<V>** buckets;
    int count = 0;
    int numBuckets = 5;
    // Get Bucket Index Function
    int getBucketIndex(string key){
        int hashCode = 0;
        int currentCoeff = 1;
        // ex:- abc = a*p^2+b*p^1+c*p^0;
        for(int i=key.length(); i >= 0; i--){
            hashCode += key[i]*currentCoeff;
            hashCode = hashCode % numBuckets; // to keep it in the range of integer as we know (a+b+c)%r = (a%r)
            currentCoeff = currentCoeff * 37; // any prime let's assume 37)
            currentCoeff = currentCoeff % numBuckets; // to keep it in the range of integer
        }
        
        return hashCode % numBuckets; // compressing
    }
    public:
    // constructor
    Map(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        // to remove the garbage value
        for(int i=0; i<numBuckets; i++){
            buckets[i] = NULL;
        }
    }
    // destructor
    ~Map(){
        for(int i=0; i<numBuckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }
    // Get size
    int size(){
        return count;
    }
    // Insert
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        // Make New Node
        MapNode<V>* newNode = new MapNode<V>(key, value);
        head = buckets[bucketIndex];
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++;
        
    }
    // Search
    V search(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        
        return -1;
    }
    // delete
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }
                else {
                    prev->next = head->next;
                }
                count--;
                V value = head->value;
                head->next = NULL; // to avoid deletion of whole string
                delete head;
                return value;
            }
            prev = head;
            head = head->next;
        }
        
        return -1;
    }
};
