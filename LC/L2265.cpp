#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans = 0;

pair<int, int> func(TreeNode* node){
    if(node == nullptr){
        return {0, 0}; // both sum and count are zero
    }

    auto left = func(node->left);
    auto right = func(node->right);
    
    int subtreeSum = node->val + left.first + right.first;
    int subtreeCount = 1 + left.second + right.second;

    if(node->val == (subtreeSum/subtreeCount)){
        ans++;
    }

    return {subtreeSum, subtreeCount};
}

int averageOfSubtree(TreeNode* root){
    if(root == nullptr){
        return 0;
    }

    auto x = func(root);
    
    return ans;
}