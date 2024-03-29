#include <bits/stdc++.h>
using namespace std;
struct Node {
      int data;
      Node *left;
      Node *right;
      Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
class Solution {
  public:
    int findLargestSubtreeSumUtil(Node* root, int& ans){
    // If current node is null then
    // return 0 to parent node.
    if (root == NULL)    
        return 0;
     
    // Subtree sum rooted at current node.
    int currSum = root->data +
      findLargestSubtreeSumUtil(root->left, ans)
      + findLargestSubtreeSumUtil(root->right, ans);
 
    // Update answer if current subtree
    // sum is greater than answer so far.
    ans = max(ans, currSum);
 
    // Return current subtree sum to
    // its parent node.
    return currSum;
}
 
// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
    // If tree does not exist,
    // then answer is 0.
    if (root == NULL)    
        return 0;
     
    // Variable to store maximum subtree sum.
    int ans = INT_MIN;
 
    // Call to recursive function to
    // find maximum subtree sum.
    findLargestSubtreeSumUtil(root, ans);
 
    return ans;
}
};
//current sum is important look there and use of & as ans will change everytime 
//https://practice.geeksforgeeks.org/problems/largest-subtree-sum-in-a-tree/1