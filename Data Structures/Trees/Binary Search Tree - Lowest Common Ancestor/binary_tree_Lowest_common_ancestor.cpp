// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
// https://www.youtube.com/watch?v=13m9ZCB8gjw&t=467s

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    // Node* findLCA(){

    // } 
  
    Node *lca(Node *root, int v1,int v2) {
        if(root == NULL)// handling leaf nodes
            return NULL;
        Node* left = lca(root->left, v1, v2);
        Node* right = lca(root->right, v1, v2);

        if(root->data == v1 || root->data == v2)// i am one of the nodes
            return root;
        else{// i'm not one of the nodes
            if(left != NULL && right != NULL)
                return root;
            else if(left != NULL && right == NULL)
                return left;
            else if (left == NULL && right != NULL)
                return right;
            else //left == NULL && right == NULL   Node is leaf node
                return NULL;
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
