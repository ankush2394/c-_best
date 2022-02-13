//
// Created by Ankush on 01/06/21.
//

//
//        10
//    2          20
// 1       8  15       35

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode * left, *right;
};
int height(TreeNode * root ) {
    if (root == NULL) {
        return  0;
    }

    return 1+ max(height(root->left), height(root->right));
}

bool isBst(TreeNode * root, int min, int max) {
    //inorder traversal give sorted array , but memory o(nodes)
    //o(1) memory

    if (root == NULL) {
        return true;
    }
    if (root->data>max || root->data<min) {
        return false;
    }
    return isBst(root->left, min, root->data-1) && isBst(root->right, root->data+1,max);
}

int kthLargest(TreeNode * root, int k, int count ) {

    //morris traversal gives o(1) memory , this still gives o(h) memory of function call stack

    if (root == NULL || count>k) {
        return -1;
    }

    kthLargest(root->right,k,count);
    count++;
    if (count==k) {    //some issue here
        return root->data;
    }

    kthLargest(root->left,k,count);

}

TreeNode * sortedArrayToBSt(int arr[], int start, int end) {
    if (start>end) {
        return nullptr;
    }
    int mid = (start+end)/2;

    TreeNode *node = new TreeNode;
    node->data = arr[mid];

    node->left = sortedArrayToBSt(arr, start, mid-1);
    node->right = sortedArrayToBSt(arr, mid+1, end);

    return node;
}


