#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Trie {
public:
    Trie() : root(NULL) { }
    
    ~Trie() {
        destroy(root);
    }
    
    void add_string(char s[]) {
        pNode current_node = root;
        
        for (int i = 0; s[i]; i++) {
            current_node = current_node -> add_next_letter(s[i]);    
        }
    }
    
    bool has_string(char s[]) {
        pNode current_node = root;
        
        for (int i = 0; s[i]; i++) {
            current_node = current_node -> get_next_letter(s[i]);
            
            if (current_node == NULL)
                return false;
        }
        
        return true;
    }
    
private:
    struct Node {
        char letter;
        Node *left_child, *right_child, *sibling;
        
        Node(char letter) : letter(letter), left_child(NULL), right_child(NULL), sibling(NULL) { }
        
        Node* get_next_letter(char next_letter) {
            for (Node* current_child = left_child; current_child != NULL; current_child = current_child -> sibling) {
                if (current_child -> letter == next_letter)
                    return current_child;
            } 
            
            return NULL;
        }
        
        Node* add_next_letter(char next_letter) {
            Node* new_child = new Node(next_letter);
            
            if (left_child == NULL) {
                left_child = right_child = new_child;
            } else if (left_child -> letter > letter) {
                new_child -> sibling = left_child;
                left_child = new_child;
            } else if (right_child -> letter < letter) {
                right_child -> sibling = new_child;
                right_child = new_child;
            } else {
                for (Node* current_child = left_child; current_child != NULL; current_child = current_child -> sibling) {
                    if (current_child -> letter == next_letter)
                        return current_child;
                        
                    if (current_child -> letter < next_letter && current_child -> sibling -> letter > next_letter) {
                        new_child -> sibling = current_child -> sibling;
                        current_child -> sibling = new_child;
                        break;
                    }
                }
            }
            
            return new_child;
        }
    };
    
    typedef Node* pNode;
    
    void destroy(pNode node) {
        pNode current_child = node -> left_child;
        
        while (current_child != NULL) {
            pNode sibling_child = current_child -> sibling;
            destroy(current_child);
            current_child = sibling_child;
        }
        
        delete node;
    }
    
    pNode root;
};

int main() {
    return 0;
}