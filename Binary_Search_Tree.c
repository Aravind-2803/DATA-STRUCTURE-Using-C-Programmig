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
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
struct Node* search(struct Node* root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}
struct Node* findMin(struct Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct Node* deleteNode(struct Node* root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL)
         {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct Node* root = NULL;
    int choice, value;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            struct Node* foundNode = search(root, value);
            if (foundNode != NULL) {
                printf("Value %d found in the BST.\n", value);
            } else {
                printf("Value %d not found in the BST.\n", value);
            }
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Value %d deleted from the BST.\n", value);
            break;
        case 4:
            printf("In-order Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Thank You...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
