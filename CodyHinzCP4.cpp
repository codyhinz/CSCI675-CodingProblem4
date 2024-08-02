class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }
    
private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        // If the current node is null, return an empty vector
        if (node == nullptr)
            return {};
        
        // If the current node is a leaf node, return a vector with a single element 1
        if (node->left == nullptr && node->right == nullptr)
            return {1};
        
        // Recursively call dfs on the left and right subtrees
        vector<int> leftDist = dfs(node->left, distance, count);
        vector<int> rightDist = dfs(node->right, distance, count);
        
        // Iterate over the distances of leaf nodes in the left and right subtrees
        // If the sum of distances is less than or equal to the distance limit, increment count
        for (int i = 0; i < leftDist.size(); i++) {
            for (int j = 0; j < rightDist.size(); j++) {
                if (leftDist[i] + rightDist[j] <= distance)
                    count++;
            }
        }
        
        // Create a vector to store the distances of leaf nodes from the current node
        vector<int> result;
        
        // Iterate over the distances in leftDist
        // If the distance plus 1 is less than or equal to the distance limit, add it to result
        for (int d : leftDist)
            if (d + 1 <= distance)
                result.push_back(d + 1);
        
        // Iterate over the distances in rightDist
        // If the distance plus 1 is less than or equal to the distance limit, add it to result
        for (int d : rightDist)
            if (d + 1 <= distance)
                result.push_back(d + 1);
        
        // Return the result vector containing the distances of leaf nodes from the current node
        return result;
    }
};