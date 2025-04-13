#include <stdio.h>
void bubbleSort(int array[], int size) 
{
for (int i = 0; i< size - 1; ++i) 
{
    for (int j = 0; j < size - i - 1; ++j) 
    {
      if (array[j] > array[j + 1]) 
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}
int main() 
{
  int data[] = {-2, 45, 0, 11, -9};
  int size = sizeof(data) / sizeof(data[0]);
  printf("Unsorted Array :\n");
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", data[i]);
  }
  printf("\n");
  bubbleSort(data, size);
  printf("Sorted Array in Ascending Order:\n");
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", data[i]);
  }
  printf("\n");
  return 0;
}
