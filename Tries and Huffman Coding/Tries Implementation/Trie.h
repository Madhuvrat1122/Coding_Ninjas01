#include "TrieNode.h"
#include <string>
using namespace std;
class Trie {
    TrieNode* root;
    void insertWordHelper(TrieNode *root, string word){
        // Base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a'; // current character index
        TrieNode* child;
        // if already exist
        if(root->children[index] != NULL){
            child = root->children[index]; 
        }
        // not exist
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        // Recursive call
        insertWordHelper(child, word.substr(1));
    }
    bool searchWordHelper(TrieNode *root, string word){
        // Base case
        if(word.length() == 0){
            return root->isTerminal;
        }
        
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            return searchWordHelper(root->children[index], word.substr(1));
        }
        else {
            return false;
        }
    }
    void removeWordHelper(TrieNode *root, string word){
        // Base case
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else {
            // Word Not Exits
            return;
        }
        
        removeWordHelper(child, word.substr(1));
        
        // Delete the child node if it is useless
        // A node is called useless if its not a terminal and there is no child
        // attached to it.
        if(child->isTerminal == false){
            for(int i=0; i<26; i++){
                if(child->children[i] != NULL){
                    // it menas it contains a child
                    return;
                }
            }
            // if comes here means there is not child
            delete child; // deallocate 
            root->children[index] = NULL;
        }
    }
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    // INsertion
    void insertWord(string word){
        insertWordHelper(root, word);
    }
    // Search
    bool searchWord(string word){
        return searchWordHelper(root, word);
    }
    // Deletion
    void removeWord(string word){
        removeWordHelper(root, word);
    }
};
