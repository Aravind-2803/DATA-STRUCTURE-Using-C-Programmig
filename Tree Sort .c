#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void treeSort(int arr[], int n)
{
    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    printf("Sorted array: ");
    inorderTraversal(root);
    printf("\n");
}
int main()
{
    int arr[] = {5, 3, 8, 1, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    treeSort(arr, n);
    return 0;
}