// Mhammed Alhayek Homework 5: Question 1 - Dynamic Memory Allocation Array-Based Binary Tree
#include <iostream>
using namespace std;

//reference book

template<class ItemType>
class TreeNode{
private:
    ItemType item;          // Data portion
    int leftChild;          // Index to left child
    int rightChild;         // Index to right child
public:
    // default constructor initializes children to -1
    TreeNode() : leftChild(-1), rightChild(-1){
    }
    
    // constructor that initializes item and children to user input
    TreeNode(const ItemType& nodeItem, int left, int right) : item(nodeItem), leftChild(left), rightChild(right) {
    }
    
    // sets the item
    void setItem(ItemType nodeItem){
        item = nodeItem;
    }
    
    // gets the item
    ItemType getItem(){
        return item;
    }
    
    // sets leftChild
    void setLeft(int subRoot){
        leftChild = 2*subRoot + 1;
    }
    
    // gets leftChild
    int getLeft(){
        return leftChild;
    }
    
    // sets rightChild
    void setRight(int subRoot){
        rightChild = 2*subRoot + 2;
    }
    
    // gets rightChild
    int getRight(){
        return rightChild;
    }
};

class Tree{
private:
    int max_nodes = 10;         // array max height is 6 : (2^6) - 1 ---- Arbitrary Value
    // malloc
    TreeNode<string>* tree = new TreeNode<string>[max_nodes];     // dynamic array of tree nodes
    int root = 0;               // index of root
    int free;               // index of free list
    int size = 0;
public:
    // default constructor
    Tree(){
        for (int i = 0; i<max_nodes; i++){
            // empty string represents empty node
            tree[i].setItem("");
            tree[i].setLeft(i);
            tree[i].setRight(i);
        }
    }
    
    // constructor that intializes tree from array
    Tree(string arr[], int n){
        for (int i = 0; i<n; i++){
            insertElement(arr[i]);
        }
    }
    
    void preOrder(int subRoot){
        if (subRoot<size){
            cout << tree[subRoot].getItem() << " ";
            preOrder(tree[subRoot].getLeft());
            preOrder(tree[subRoot].getRight());
        }
    }

    void inOrder(int subRoot){
        if (subRoot<size){
            inOrder(tree[subRoot].getLeft());
            cout << tree[subRoot].getItem() << " ";
            inOrder(tree[subRoot].getRight());
        }
    }
    
    void postOrder(int subRoot){
        if (subRoot<size){
            postOrder(tree[subRoot].getLeft());
            postOrder(tree[subRoot].getRight());
            cout << tree[subRoot].getItem() << " ";
        }
    }
    
    void insertElement(string data) {
        // check if size is within indices of tree.
        if (size < max_nodes){
            // if size is within indices of tree, add to end of tree because it is complete
            tree[size].setItem(data);
            tree[size].setRight(size);
            tree[size].setLeft(size);
            size++;
        } else{
            // else, extend the size of the tree
            TreeNode<string>* oldTree = tree;
            tree = new TreeNode<string>[2*max_nodes];
            for (int i = 0; i < max_nodes; i++){
                tree[i] = oldTree[i];
            }
            max_nodes = 2*max_nodes;
            delete [] oldTree;
            tree[size].setItem(data);
            tree[size].setRight(size);
            tree[size].setLeft(size);
            size++;
        }

    }
    
    void removeElement(int index){
        // if index of element to remove is within tree and that item is not already blank
        if ((index < size) && (tree[index].getItem() != "")){
            for (int i = index; i<size; i++){
                tree[i] = tree[i+1];
                tree[i].setLeft(i);
                tree[i].setRight(i);
                
            }
            size--;
            tree[size].setItem("");
            
        }
        // else do nothing
    }

};

int main(int argc, const char * argv[]) {
    // program to test above code
    string arr[20] = {"A", "B", "C" , "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
    Tree myTree(arr, 20);
    cout << "Displaying tree in order" << endl;
    myTree.inOrder(0);
    cout << "\nDisplaying tree in post order" << endl;
    myTree.postOrder(0);
    
    cout << "\nAdding 'Z' to the tree" << endl;
    myTree.insertElement("Z");
    cout << "Displaying new tree in pre order" << endl;
    myTree.preOrder(0);
    
    cout << "\nRemoving element in index 5 from tree" << endl;
    myTree.removeElement(5);
    cout << "Displaying new tree in order" << endl;
    myTree.inOrder(0);
    cout << endl;
    
    
    
    return 0;
}
