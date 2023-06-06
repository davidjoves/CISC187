/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 21 - Programming Assignment
 * 
 * 
 * Date: 18 - MAY - 2023
*/

//Implementation file for BinarySearchTree
#include <iostream> 
#include "BinaryTree.h"

using namespace std; 

//***************************************************************************
// Member function inOrderTraversal, traverses through the tree using depth *
// first search algorithm. Will output the data in each node in order.      *
//***************************************************************************
void BinarySearchTree::inOrderTraversal(TreeNode* node)
{
    //Base Case: 
    // When node points to null, output data in order from left and right subtrees
    if(node != nullptr)
    {
        //Recursive Case: 
        //When node is not pointing to null, search left, output data, then search right 
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

//***************************************************************************
// Member function destroy, traverses through the tree using recursion to   *
// visit each left and right node, then deletes it when base case is met.   *
//***************************************************************************
void BinarySearchTree :: destroy(TreeNode* nodePtr)
{
    //Base Case: 
    // If nodePtr points to nullptr, return
    if(nodePtr == nullptr)
    {
        return; 
    }
    //Recursive Case:
    // Search the left tree and right tree until base case is met. Delete current nodePtr.
    destroy(nodePtr->left);
    destroy(nodePtr->right);
    delete nodePtr;
}

//***************************************************************************
// Member function insertNode, traverses through the tree using recursion   *
// to visit each data in left and right subtrees to insert newNode properly.*
//***************************************************************************
void BinarySearchTree :: insertNode(TreeNode *&nodePtr, int key) 
{
    //Base case: 
    // If node points to nullptr insert new TreeNode
    if (nodePtr == nullptr)
    {
        nodePtr = new TreeNode(key); 
        return;
    }

    //Recursive Case 1: 
    // If key is less than current node, go through left subtree until base case is met
    if (key < nodePtr->data)
    {
        insertNode(nodePtr->left, key); 
    }
    //Recursive Case 2: 
    // If key is greater than current node, go through right subtree until base case is met
    else
    {
        insertNode(nodePtr->right, key); 
    }
}

//***************************************************************************
// Member function countLeaf, traverses through the tree using recursion.   *
// Will check if current node is a leaf and will add all leaves from left   *
// and right subtrees.                                                      *
//***************************************************************************
int BinarySearchTree :: countLeaf(TreeNode* nodePtr)
{   
    //Base case 1:
    //If nodePtr points to null, (no subtree or empty tree) so return 0
    if(nodePtr == nullptr)
    {
        return 0;
    }
    
    //Base case 2:
    //If nodePtr left and right points to null (node is a leaf) return 1
    if(nodePtr->left == nullptr && nodePtr->right == nullptr)
    {
        return 1;
    }
    //Recursive Case:
    //If nodePtr is not a leaf node, we check left and right subtrees and add up sums
    else 
    {
        int leftLeaves = countLeaf(nodePtr-> left);
        int rightLeaves = countLeaf(nodePtr->right);
        return leftLeaves + rightLeaves;
    }
}

//***************************************************************************
// Member function countHeight, traverses through the tree using recursion. *
// Will check and compare the max heights from left and right subtrees to   *
// determine the length to the deepest node.                                *
//***************************************************************************
int BinarySearchTree :: countHeight(TreeNode* nodePtr)
{
    //Base case: 
    //If nodePtr points to null, (empty tree or subtree) so return 0
    if(nodePtr == nullptr)
    {
        return 0; 
    }
    //Recursive Case: 
    //Otherwise, check left and right subtrees until base case, then determine max height 
    else
    {
        int leftHeight = countHeight(nodePtr->left);    //Declare and initialize leftHeight 
        int rightHeight = countHeight(nodePtr->right);  //Declare and initialize rightHeight
        int maxHeight;                                  //Declare maxHeight


        //If left greater than right, max = left
        if(leftHeight > rightHeight)
        {
            maxHeight = leftHeight;
        }
        //Otherwise, max = right
        else
        {
            maxHeight = rightHeight;
        }

        return maxHeight + 1;

     
    }
}

//***************************************************************************
// Member function countWidth, traverses through the tree using recursion.  *
// Will go through each level of the tree in left and right. Returns count  *
//***************************************************************************
int BinarySearchTree :: countWidth(TreeNode* nodePtr, int level)
{
    if (nodePtr == nullptr || level == 0)
    {
        return 0;
    }
    else if (level == 1)
    {
        return 1;
    }
    else
    {
        return countWidth(nodePtr->left, level - 1) + countWidth(nodePtr->right, level - 1);
    }
}

//***************************************************************************
// Member function isEmpty, returns boolean determining if binary tree is   *
// empty by looking at the root node.                                       *
//***************************************************************************
bool BinarySearchTree :: isEmpty()
{
    if(root == nullptr)
    {
        return true;
    } 
    return false;
}
