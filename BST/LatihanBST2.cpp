struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

int countNodes(struct Node *root) { // This function will return the total number of nodes in the BST
  if (root == NULL) {
    return 0;
  }
  return (1 + countNodes(root->left) + countNodes(root->right));
}

int findHeight(struct node* node){ // This function will return the height of the tree
    if (node == NULL)
        return 0;
    else {
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
        
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

void search(struct Node *current, int find) {
  if (current == NULL) {
    printf("%d is not found\n", find);
  } else if (current->data == find) {
    printf("%d is found\n", current->data);
  } else if (find < current->data) {
    search(current->left, find);
  } else {
    search(current->right, find);
  } 
}

