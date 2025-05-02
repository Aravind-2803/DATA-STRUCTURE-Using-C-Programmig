#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heap(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[largest]) 
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) 
    {
        largest = right;
    }
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heap(arr, n, largest);
    }
}
void heapSort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heap(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heap(arr, i, 0);
    }
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() 
{
  int y = 0 ;
  printf("ENTER THE NUMBER OF ELEMENTS THE ARRAY SHOULD CONTAIN :");
  scanf("%d", &y);
  int data [y];
  for (int x = 0 ; x < y ; x++)
  {
    printf("ENTER THE ELEMENT AT [%d] = ",x);
    scanf("%d",&data[x]);
  }
  int n = sizeof(data) / sizeof(data[0]);
  printf("Original array: ");
  printArray(data, n);
  heapSort(data, n);
  printf("Sorted array: ");
  printArray(data, n);
  return 0;
}
