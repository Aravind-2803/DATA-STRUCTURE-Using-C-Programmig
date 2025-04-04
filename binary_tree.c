#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* getnode(int data) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* root, int data) 
{
    if (root == NULL)
    {
        root = getnode(data);
        return root;
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
struct node* findmin(struct node* root) 
{
    if (root == NULL)
        return NULL;
    else if (root ->left == NULL)
    {
        return root ->data;
    }
    else 
        return findmin(root ->data);
}
struct node* findmax(struct node* root) 
{
    if (root == NULL)
        return NULL;
    else if (root ->right == NULL)
    {
        return root ->data;
    }
    else 
        return findmax(root ->data);
}
struct node* deletenode(struct node* root, int data) 
{
    if (root == NULL)
    {
        printf("DELETION NOT POSSIBLE !\n");
        return root ;
    }
    if (data < root->data)
        root->left = deletenode(root->left, data);
    else if (data > root->data)
        root->right = deletenode(root->right, data);
    else 
    {
        if (root->left == NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}
void inorderTraversal(struct node* root) 
{
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
void freeTree(struct node* root) 
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main() 
{
    struct node* root = NULL;
    int choice, data;
    while (1) 
    {
        printf("***************************\n");
        printf("*       BINARY TREE       *\n");
        printf("*1. INSERT                *\n");
        printf("*2. DELETE                *\n");
        printf("*3. INORDER TRAVERSAL     *\n");
        printf("*4. EXIT                  *\n");
        printf("***************************\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("ENTER DATA TO INSERT : ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                inorderTraversal(root);
                printf("\nENTER DATA TO DELETE : ");
                scanf("%d", &data);
                root = deletenode(root, data);
                break;

            case 3:
                printf("\nINORDER TRAVERSAL : ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                freeTree(root);
                printf("EXITING PROGRAM .....\n");
                exit(0);

            default:
                printf("INVALID CHOICE , PLEACE TRY AGAIN\n");
        }
    }
    return 0;
}