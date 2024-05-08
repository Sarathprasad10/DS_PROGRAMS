//Define a structure for employees with eno,ename, esal and dno. Read  n employees information and provide functions for the following: 

//   Searching an employee by no

#include <stdio.h>
#include <string.h>
int pos = -1;
struct employees
{
    int eno;
    char ename[30];
    int esal;
    int dno;
};
void disp(struct employees emp[])
{
    int i;
    for (i = 0; i <= pos; i++)
    {
        printf("EMPLOYEE %d", i + 1);
        printf("\nEmp no: %d", emp[i].eno);
        printf("\nEmp name: %s", emp[i].ename);
        printf("\nEmp salary: %d", emp[i].esal);
        printf("\nEmp dept.no: %d", emp[i].dno);
    }
}
void search(struct employees emp[], int n)
{
    int i, e;
    printf("Enter employee number to search: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
    {
        if (e == emp[i].eno)
        {
            printf("Emp.no: %d\nEmp.name: %s\nEmp.salary: %d\nEmp.dept.no: %d\n", emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
            return;
        }
    }
    printf("\nThe employee number %d is not in the list.\n", e);
}
void insert(struct employees emp[], int n)
{
    if (pos == n - 1)
    {
        printf("Employee list is full\n");
    }
    else
    {
        static int i = 0;
        printf("\nFor employee %d -\n", ++i);
        printf("Enter the employee number: ");
        scanf("%d", &emp[++pos].eno);
        printf("Enter the employee name:");
        scanf("%s", emp[pos].ename);
        printf("Enter the employee salary:");
        scanf("%d", &emp[pos].esal);
        printf("Enter the department no:");
        scanf("%d", &emp[pos].dno);
    }
}

int main()
{
    int n,ch;
    int i;
    printf("\nEnter the number of employees : ");
    scanf("%d", &n);
    struct employees emp[n];
    do{
        printf("\n*********************************");
        printf("\n1.Insert\t\t2.Search\n3.View emp details\t4.Exit");
        printf("\n*********************************");
        for(i=0;i<=n;i++)
        {
            printf("\nEnter your choice:");
            scanf("%d", &ch);
            switch (ch)
            {
                case 1:insert(emp, n);
                    break;
                case 2:search(emp, n);
                    break;
                case 3:disp(emp);
                    break;
                case 4:printf("**exit**");
                        return -1;
                    break;
                default:printf("Enter a valid choice.");
                    break;
            }
        }

        
    }while(ch!=4);
    return 0;
}


