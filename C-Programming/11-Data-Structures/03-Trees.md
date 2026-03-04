# Trees

A Tree is a hierarchical data structure. The topmost node is called the **Root**.

## 🌲 Binary Search Tree (BST)

A BST is a binary tree where:
1.  The left subtree of a node contains only nodes with keys **lesser** than the node's key.
2.  The right subtree of a node contains only nodes with keys **greater** than the node's key.

### Structure

```c
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};
```

### Insertion

```c
struct TreeNode* insert(struct TreeNode* node, int data) {
    if (node == NULL) return createNode(data); // Helper to malloc new node
    
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
        
    return node;
}
```

## 🔄 Traversal

### In-Order (Left, Root, Right)
Produces sorted output for a BST.

```c
void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
```

---
[[00-Index|Back to Data Structures Index]]
