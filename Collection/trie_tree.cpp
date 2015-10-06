#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    bool hasKey;
    TrieNode *children[ALPHABET_SIZE];
    TrieNode() : hasKey(false) {
        for (int i=0; i<ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string key) {
        TrieNode *current = root;
        for (int i=0; i<key.length(); i++) {
            if (current->children[key[i]-'a'] == NULL) {
                current->children[key[i]-'a'] = new TrieNode();
            }
            current = current->children[key[i]-'a'];
        }
        current->hasKey = true;
    }

    bool search(string key) {
        TrieNode *current = root;
        for (int i=0; i<key.length(); i++) {
            if (current->children[key[i]-'a'] == NULL)
                return false;
            current = current->children[key[i]-'a'];
        }
        if (current->hasKey)
            return true;
        else
            return false;
    }
    bool remove(string key) {
        bool removable;
        return removeKey(key, 0, root, removable);  
    }
private:
    TrieNode *root;
    bool removeKey(string &key, int index, TrieNode *cur, bool &removable) {
        if (index == key.length()) {
            if (cur->hasKey) {
                for (int i=0; i<ALPHABET_SIZE; i++) {
                    if (cur->children[i])
                        removable = false;
                }
                cur->hasKey = false;
                return true;
            } else {
                removable = false;
                return false;
            }
        }

        if (cur->children[key[index] - 'a'] == NULL)
            return false;
        if (removeKey(key, index+1, cur->children[key[index]-'a'], removable)) {
            if (removable)
                cur->children[key[index]-'a'] = NULL;
            removable = true;
            for (int i=0; i<ALPHABET_SIZE; i++) {
                if (cur->children[i])
                    removable = false;
            }
            return true;
        } else
            return false;
    }
};

/*int main() {
    Trie trie;

    trie.insert("ab");
    trie.insert("abc");
    trie.insert("mn");
    trie.insert("abcdefg");

    cout << trie.search("mn") << endl;
    cout << trie.search("fjdaks") << endl;
    cout << trie.remove("abm") << endl;
    cout << trie.search("ab") << endl;
    cout << trie.search("abcdefg") << endl;
    cout << trie.search("abc") << endl;

    return 0;
}*/
