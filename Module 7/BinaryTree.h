/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 21 - Programming Assignment
 * 
 * 
 * Date: 18 - MAY - 2023
*/

//Specification file for TreeNode and BinarySearchTree
#ifndef BinaryTree_H
#define BinaryTree_H 

using namespace std; 

class TreeNode
{
    public: 

        int data;           //Data in node
        TreeNode* left;     //Pointer to left child
        TreeNode* right;    //Pointer to right child

        //Constructor
        TreeNode(int data)
        {
            this->data = data; 
            left = nullptr;
            right = nullptr;
        }   
};

class BinarySearchTree
{
    private: 

        TreeNode* root;     //Pointer to root node

        //Private member functions
        void insertNode(TreeNode *&, int);
        void inOrderTraversal(TreeNode*);
        void destroy(TreeNode*);
        int countLeaf(TreeNode*);
        int countHeight(TreeNode*);
        int countWidth(TreeNode*, int);

    public: 

        //Constructor
        BinarySearchTree()
        {root = nullptr;}

        //Destructor
        ~BinarySearchTree()
        {destroy(root);}

        //Binary Tree Operations

        void insert(int key)
        { insertNode(root, key);}

        void displayInOrder()
        { inOrderTraversal(root); }

        int getLeafCount()
        {return countLeaf(root);}

        int getHeightCount()
        {return  countHeight(root) - 1;}

        int getWidthCount(int level)
        { return countWidth(root, level); }

        bool isEmpty();
        
        
};
#endif