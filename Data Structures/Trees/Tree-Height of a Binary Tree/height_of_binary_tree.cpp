// https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem


/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if(root->left == NULL && root->right==NULL)
            return 0;
        else if(root->left != NULL && root->right==NULL)
            return 1+height(root->left);
        else if(root->left == NULL && root->right!=NULL)
            return 1+height(root->right);
        else
            return max(1+height(root->left), 1+height(root->right));
    }

