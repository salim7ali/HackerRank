// https://www.hackerrank.com/challenges/is-binary-search-tree/submissions/code/174997819

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
// #include<bits/stdc++.h>

bool validator(Node* node, int min, int max){
    if(node == NULL)
        return true;
    if(node->data <= min || node->data >= max)
        return false;
    else{
        return validator(node->left, min, node->data) && validator(node->right, node->data, max); 
    }
}

	bool checkBST(Node* root) {
	   return validator(root, -99999999, 9999999);	
	}