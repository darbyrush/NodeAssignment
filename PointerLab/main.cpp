//
//  main.cpp
//  lab12
//
//  Created by Darby Rush on 11/18/20.
//  Copyright © 2020 Darby Rush. All rights reserved.
//

#include <cstdlib>
#include <iostream>

using namespace std;

struct Node
{

    int data;

    Node* left;

    Node* right;

} ;
Node* search(Node* t, int key, Node * & parent){
    if(t == NULL){
        return NULL;
    }
    if(key == t-> data){
        return t;
    }
    if(key < t -> data){
        parent = t;
        return search(t->left,key,parent);
    }
        if(key > t -> data){
        parent = t;
        return search(t->right,key,parent);
    }
    return 0;
}
Node* insert(Node* t, int key){
    if(key < t ->data){
        if(t-> left != NULL){
            insert(t ->left,key);
        }
        else{
            t -> left = new Node();
            t -> left -> data = key;
            t -> left -> left = NULL;
            t -> left -> right = NULL;
        }
    }
    else if(key >= t->data){
        if(t->right != NULL){
            insert(t -> right, key);
        }
        else{
            t -> right = new Node();
            t -> right -> data = key;
            t -> right -> right = NULL;
            t -> right -> left = NULL;
        }
    }
  return 0;
}
void inorder (Node* t){
    if(t != NULL){
        inorder(t->left);
        cout << t->data<< ",";
        inorder(t->right);
    }
}
int main()
{
    Node* build = new Node();
    insert(build,10);
    insert(build,25);
    insert(build,20);
    inorder(build);

    return 0;
}
