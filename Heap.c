#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
void heapSort(int arr[], int n) 
{
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() 
{
    int *arr = NULL;
    int size = 0;
    int choice, element, i;
    while (1) 
    {
        printf("\nMenu:\n1. Create Heap\n2. Insert Element\n3. Sort Heap\n4. Print Heap\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter the size of the heap: ");
                scanf("%d", &size);
                if (size <= 0) 
                {
                    printf("Invalid heap size.\n");
                    break;
                }
                arr = (int *)malloc(size * sizeof(int));
                 if (arr == NULL) 
                 {
                    printf("Memory allocation failed.\n");
                    exit(1); 
                }
                printf("Enter elements for the heap:\n");
                for (i = 0; i < size; i++) 
                {
                    scanf("%d", &arr[i]);
                }
                buildHeap(arr, size);
                printf("Heap created successfully.\n");
                break;
             case 2:
                if (arr == NULL) {
                    printf("Create a heap first.\n");
                    break;
                }
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                size++;
                arr = (int *)realloc(arr, size * sizeof(int));
                if (arr == NULL) 
                {
                    printf("Memory reallocation failed.\n");
                    exit(1);
                }
                arr[size - 1] = element;
                buildHeap(arr, size);
                printf("Element inserted successfully.\n");
                break;
            case 3:
                if (arr == NULL) 
                {
                    printf("Create a heap first.\n");
                    break;
                }
                heapSort(arr, size);
                printf("Heap sorted successfully.\n");
                break;
            case 4:
                 if (arr == NULL) 
                 {
                    printf("Create a heap first.\n");
                    break;
                }
                printf("Heap elements: ");
                printArray(arr, size);
                break;
            case 5:
                free(arr);
                printf("Thank you.........\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
    
}
