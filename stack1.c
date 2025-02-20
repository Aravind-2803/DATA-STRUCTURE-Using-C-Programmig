 while(choise != 5)
    {

        choise = 0;
        printf("enter your choice\n 1.Push \n 2.Pop \n 3.Peek Top \n 4.Display \n 5.Exit\n");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
        printf("enter the data");
            do
            {
                data = getchar();
            }
            while (data == '\0' || data == '\n');    
            push(s,&top,max,data);
            printf("successfully pushed\n");
            break;
        case 2:
            data = pop(s,&top,max);
            if(data != '\0')
            {
                printf("the poped element is %c\n",data);
            }
            if(!isempty(s,&top))
            {
                printf("stack is empty\n");
            }
            break;
        case 3:
            printf("%d\n",peektop(s,&top));
            break;
        case 4:
            for(int i = 0;i <strlen(s);i++)
            {
                printf("%c",s[i]);
            }
            break;
        case 5:
            printf("...TERMINATED...\n");
            break;
        default:
            printf("enter the valid choise");
            break;
        }
        printf("\n");     
    }
}
