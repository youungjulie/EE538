#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.
bool IsBST(BinaryTreeNode *root) {
    if (root == nullptr) return true; 

    BinaryTreeNode* l = root->left;
    BinaryTreeNode* r = root->right;

    if (l != nullptr && l->val > root->val) return false;
    if (r != nullptr && r->val < root->val) return false;

    return(IsBST(l) && IsBST(r));
}

std::map<Statistics, int> FindStatistics(BinaryTreeNode *root) {
    std::map<Statistics, int> statistics {
        {Statistics::kHeight, 0}, 
        {Statistics::kNumberOfLeaves, 0}, 
        {Statistics::kMin, INT32_MAX}, 
        {Statistics::kMax, 0}, 
        {Statistics::kNumberOfSingleChildNodes, 0}, 
        {Statistics::kNumberOfNodes, 0}
    };

    int current_level = 0;
    if (root != nullptr) {
        FindStatistics_Helper(root, current_level, statistics);
    }
    return statistics;
}

void FindStatistics_Helper(BinaryTreeNode *root, int current_level,
                           std::map<Statistics, int> &statistics) {
    // When getting in the helper function, we checked that root is not nullptr,
    // so the current level += 1
    current_level += 1;
    if (current_level > statistics[kHeight]) {
        statistics[kHeight] = current_level;
    }

    if (root->left == nullptr && root->right == nullptr) {
        statistics[kNumberOfLeaves] += 1;
    }

    if (root->val >= statistics[kMax]) {
        statistics[kMax] = root->val;
    }

    if (root->val <= statistics[kMin]) {
        statistics[kMin] = root->val;
    }

    if ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr)) {
        statistics[kNumberOfSingleChildNodes] += 1;
    }

    if (root != nullptr) {
        statistics[kNumberOfNodes] += 1;
    }

    if (root->left != nullptr) {
        FindStatistics_Helper(root->left, current_level, statistics);
    }
    if (root->right != nullptr) {
        FindStatistics_Helper(root->right, current_level, statistics);
    }
}