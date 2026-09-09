#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minSwaps(vector<int>& level){
    int n = level.size();

    vector<int> sorted = level;
    sort(sorted.begin(), sorted.end());

    unordered_map<int, int> pos;
    for(int i=0; i<n; i++){
        pos[sorted[i]] = i;
    }

    vector<int> perm(n);
    for(int i=0; i<n; i++){
        perm[i] = pos[level[i]];
    }

    int cycles = 0;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(visited[i]){
            continue;
        }

        cycles++;

        int current = i;
        while(!visited[current]){
            visited[current] = true;
            current = perm[current];
        }
    }

    return n - cycles;
}

int minimumOperations(TreeNode* root){

    if(root == nullptr){
        return 0;
    }

    int answer = 0;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        int levelSize = q.size();

        vector<int> level;
        
        // Process exactly this level
        for(int i=0; i<levelSize; i++){
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }

        answer += minSwaps(level);
    }

    return answer;
}