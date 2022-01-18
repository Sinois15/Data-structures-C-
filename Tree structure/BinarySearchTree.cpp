#include <iostream>
using namespace std;

// define structure of a Binary Search Tree (BST)
struct BSTNode {
    int key;
    BSTNode *leftChild;
    BSTNode *rightChild;
};
//initialize the first node created in BST
void initBST(BSTNode *tmpNode, int key) {
    tmpNode->key = key;
    tmpNode->leftChild = NULL;
    tmpNode->rightChild = NULL;
}
// inserts a new node in the BST at the correct position
void insertBST(BSTNode* node, int key) {
    if(key < node->key) {
        if(node->leftChild != NULL)
            insertBST(node->leftChild, key);
        else {
            BSTNode *newNode = new BSTNode;
            newNode->key = key;
            newNode->leftChild = NULL;
            newNode->rightChild =NULL;
            node->leftChild = newNode;
        }
    }
    else if (key >= node->key) {
        if(node->rightChild != NULL)
            insertBST(node->rightChild, key);
        else {
        BSTNode *newNode = new BSTNode;
        newNode->key = key;
        newNode->leftChild = NULL;
        newNode->rightChild =NULL;
        node->rightChild = newNode;
        }
    }
}
// search and return the matching node
BSTNode *searchBST(BSTNode *tmpNode, int key){
if (tmpNode != NULL) {
    if(key == tmpNode->key)
    return tmpNode;
    else {
        if (key < tmpNode->key)
        return searchBST(tmpNode->leftChild, key);
    else
        return searchBST(tmpNode->rightChild, key);
    }
}
else
return NULL;
}

void visit(BSTNode *tmpNode){
    if (tmpNode != NULL){
        cout<<tmpNode -> key<<" ";
    }
    else{
        cout<<"tree is empty";
    }
}

void preOrder(BSTNode *t){
    if (t != NULL) {
        visit(t); // visit tree node (root)
        preOrder(t->leftChild); // do left subtree
        preOrder(t->rightChild);// do right subtree
    }
}

void inOrder(BSTNode *t){
    if (t != NULL) {
        if(! isLeaf(t)) printf( '(' );
            inOrder(t->leftChild); // do left subtree
            visit(t); // visit tree root
            inOrder(t->rightChild); // do right subtree
        if(! isLeaf(t)) printf( ')' );
    }
}

int main(){
BSTNode *root = new BSTNode;
initBST(root, 8);
insertBST(root, 3);
insertBST(root, 10);
insertBST(root, 1);
insertBST(root, 6);
insertBST(root, 14);
insertBST(root, 4);
insertBST(root, 7);
insertBST(root, 13);
preOrder(root);
/*int searchedKey = 14;
BSTNode *searchNode = new BSTNode;
searchNode = searchBST(root, searchedKey);
if (searchNode != NULL) {
    cout << "KEY = " << searchNode->key << endl;
if (searchNode->leftChild == NULL)
    cout << "LCHILD = NULL\n";
else
    cout << "LCHILD = " << searchNode->leftChild->key << endl;
if (searchNode->rightChild == NULL)
    cout << "RCHILD = NULL\n";
else
    cout << "RCHILD = " << searchNode->rightChild->key << endl;
}
else
    cout << searchedKey << " Not Found!";
return 0;*/
}