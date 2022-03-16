#include <iostream>
using namespace std;


struct TreeNode {
    int info;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

//class for binary search tree
class BinSearchTree {
public:
    BinSearchTree (int input[], int size){
        root = buildTree(input, 0, size - 1 ); // this calls your method
    }

    void traverseNodes();

private:
    TreeNode* root = nullptr;
    /**
     * Builds a binary using the elements from input[start]
     * to input[end]. So start and end are indices for the array input
     */
    TreeNode* buildTree(int input[], int start, int end);
    void traverseNodes(TreeNode* root);
};

//Methods
void BinSearchTree::traverseNodes() {
    traverseNodes(root); // call the traversal with the root, which is private
}
void BinSearchTree::traverseNodes(TreeNode* root) {
    if (root == nullptr)
        return;
    traverseNodes(root->left);
    std::cout << root->info << " ";
    traverseNodes(root->right);
}


TreeNode* BinSearchTree::buildTree(int input[], int start, int end){
    //Base Case /
   if (start > end)
   return NULL;

   //Get the middle element and make it root
    int middle = (start + end)/2;
    TreeNode* p = new TreeNode;
    p->info = input[middle];
    root = p;

    // Recursively go to the left subtree
    p->left = buildTree(input, start,middle - 1);

    // Recursively go to the right subtree
    p->right = buildTree(input, middle + 1, end);

    return p;

}


int main(){
    int input[] = {4, 9, 15, 20, 22, 24, 35, 87};
    //1 - create the binary search tree given the sorted input
    BinSearchTree st = BinSearchTree (input,8);
    //2 - print the tree node values inorder
    st.traverseNodes(); // this code was given on Canvas earlier
}

/*
    int middle = (start + end) / 2 ;

    TreeNode *p = new TreeNode;
    TreeNode *q = new TreeNode;

    root = p;
    p->info = input[middle];
    q = p;

    if(middle == start || middle == end){       //the base case
        return q;
    }
    else{
        q->left = buildTree(input, start, middle - 1);    //left side
        q->right = buildTree(input, middle + 1, end);      //right side
    }
 */