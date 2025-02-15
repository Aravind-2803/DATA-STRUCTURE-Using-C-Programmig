#include <stdio.h>
#include <string.h>

typedef struct Student
{
    int roll;
    char name[50];
    int age;
    char gender;
    int mark1;
    int mark2;
    int mark3;
    char grade[2];
} Student;

void dispOne(Student *arr, int n)
{
    int roll;
    printf("Enter Roll No: ");
    scanf("%d", &roll);
    for (int i = 0; i < n; i++)
        if (arr[i].roll == roll)
            printf("%d %s %d %c %d %d %d %s\n",arr[i].roll, arr[i].name, arr[i].age, arr[i].gender, arr[i].mark1, arr[i].mark2, arr[i].mark3, arr[i].grade);
        else
            printf("Not present \n");
}

void dispAll(Student *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d %s %d %c %d %d %d %s\n",arr[i].roll, arr[i].name, arr[i].age, arr[i].gender, arr[i].mark1, arr[i].mark2, arr[i].mark3, arr[i].grade);
}

void dispFail(Student *arr, int n)
{
    for (int i = 0; i < n; ++i)
        if (strncmp(arr[i].grade, "F", 2) == 0)
            printf("%d %s %d %c %d %d %d %s\n",arr[i].roll, arr[i].name, arr[i].age, arr[i].gender, arr[i].mark1, arr[i].mark2, arr[i].mark3, arr[i].grade);
}

void dispPass(Student *arr, int n)
{
    for (int i = 0; i < n; i++)
        if (strncmp(arr[i].grade, "F", 2) != 0)
            printf("%d %s %d %c %d %d %d %s\n",arr[i].roll, arr[i].name, arr[i].age, arr[i].gender, arr[i].mark1, arr[i].mark2, arr[i].mark3, arr[i].grade);
}

void insert(Student *arr,int *n)
{
  if(*n==99)
    return;
  Student students;
  printf("Roll No: ");
  scanf("%d", &students.roll);
  printf("Name: ");
  scanf("%s",students.name);
  printf("Age: ");
  scanf("%d", &students.age);
  getchar();
  printf("Enter The gender (M/F): ");
  students.gender=getchar();
  if(students.gender!='M'&&students.gender!='F')
  {
    printf("Invalid gender ");
    return;
  }
  printf("Mark_1 (0-100): ");
  scanf("%d", &students.mark1);
  printf("Mark_2 (0-100): ");
  scanf("%d", &students.mark2);
  printf("Mark_3 (0-100): ");
  scanf("%d", &students.mark3);
  if ((students.mark1 < 0 || students.mark1 > 100) && (students.mark2 < 0 || students.mark2 > 100) && (students.mark3 < 0 || students.mark3 > 100))
        return;
  else
  {
    float avg=(students.mark1+students.mark2+students.mark3)/3;
    if(avg>90)
      strcpy(students.grade,"O");
    else if (avg > 80 && avg <= 90)
      strcpy(students.grade, "A+");
    else if (avg > 70 && avg <= 80)
      strcpy(students.grade, "A");
    else if (avg > 60 && avg <= 70)
      strcpy(students.grade, "B+");
    else if (avg > 50 && avg <= 60)
      strcpy(students.grade, "B");
    else
      strcpy(students.grade,"F");
    }
  for(int i=*n;i>-1;i--)
  {
    if(i==0)
    {
        arr[i]=students;
    }
    else
    {
      if(arr[i-1].roll>students.roll)
          arr[i]=arr[i-1];
      else
      {
        arr[i]=students;
        break;
      }
    }
    }
  (*n)++;
  dispAll(arr,*n);
}


void delete(Student *arr, int *n)
{
    if (*n == 0)
        return;

    int Roll, found, pos;
    found = 0;
    printf("Roll No: ");
    scanf("%d", &Roll);
    for (int i = 0; i < *n; i++)
        if (arr[i].roll == Roll)
            pos = i;
    found = 1;

    if (found)
        for (int i = pos; i < *n; i++)
            arr[i] = arr[i+1];
    else
        printf("Student Not Found!");
    (*n)--;
    dispAll(arr, *n);
}

int main()
{
    int init,n, roll, choice,avg,grade;
    n = 0;
    choice = 0;
    printf("Enter the number of students: ");
    scanf("%d", &init);
    Student students[100];
    for (int i = 0; i < init; i++)
    {
        insert(students, &n);
    }
    
    while (1)
    {
        printf("--------------------\n");
        printf("1.Display\n2.Insert\n3.Delete\n4.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("------------\n");
            printf("1.All\n2.One\nEnter Your Choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("1.All\n2.Passed\n3.Failed\nEnter Your Choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    dispAll(students, n);
                    break;
                case 2:
                    dispPass(students, n);
                    break;
                case 3:
                    dispFail(students, n);
                    break;
                default:
                    printf("Invalid Choice\n");
                }
                break;

            case 2:
                dispOne(students, n);
                break;

            default:
                printf("Invalid Choice\n");
            }
            break;

        case 2:
            insert(students, &n);
            break;

        case 3:
            delete(students, &n);
            break;

        case 4:
            printf("_______________________________________\n");
            printf("THANK YOU...\n");
            printf("_______________________________________\n");
            return 0;

        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}

    
