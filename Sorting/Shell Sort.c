#include <stdio.h>
void shellSort(int array[], int n) 
{
  for (int interval = n / 2; interval > 0; interval /= 2) 
  {
    for (int i = interval; i < n; i += 1) 
    {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) 
      {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}
int main() 
{
  int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
  int size = sizeof(data) / sizeof(data[0]);
  printf("Sorted array: \n");
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", data[i]);
  }
  printf("\n");
  shellSort(data, size);
  printf("Sorted array: \n");
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", data[i]);
  }
  printf("\n");
} 