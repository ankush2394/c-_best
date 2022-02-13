//
// Created by Ankush on 17/06/21.
//
#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    char val;
    bool isWord= false;
    TrieNode * arr[26];

    TrieNode(char val, bool isWord) {
        this->val = val;
        this->isWord = isWord;
        for(int i=0;i<26;i++) {
            this->arr[i] = nullptr;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode * root;
    Trie() {
        root = new TrieNode((char)0, false);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * temp = root;
        for (int i=0;i<word.length();i++) {
            int pos = int(word[i])-97;   //assuming lower case chars only

            if (temp->arr[pos] == NULL) {
                if (i==word.length()-1) {
                    temp->arr[pos] = new TrieNode(word[i], true);
                } else {
                    temp->arr[pos] = new TrieNode(word[i], false);
                }
            }
            if (i==word.length()-1){
                temp->arr[pos]->isWord = true;
            }
            temp = temp->arr[pos];

        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * temp = root;
        for(int i=0;i<word.length();i++) {
            int pos = int(word[i])-97;   //assuming lower case chars only
            if (temp->arr[pos] != NULL) {
                if (i==word.length()-1) {
                    if (temp->arr[pos]->isWord) {
                        return true;
                    } else {
                        return false;
                    }
                }
                temp=temp->arr[pos];
                continue;
            } else {
                return false;
            }
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * temp = root;
        for(int i=0;i<prefix.length();i++) {
            int pos = int(prefix[i])-97;   //assuming lower case chars only
            if (temp->arr[pos] != NULL) {
                if (i==prefix.length()-1) {
                    return true;
                }
                temp=temp->arr[pos];
                continue;
            } else {
                return false;
            }
        }
        return false;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//int main() {
//    Trie* obj = new Trie();
//    obj->insert("abcd");
//    cout<<obj->search("abc")<<endl;
//    cout<<obj->startsWith("abcd");
//    return 0;
//}

