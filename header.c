#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "header.h"
#include "Emp_struct.c"
#define SIZE 100



Employee emp[SIZE];
int employeeCount = 0;

void addEmployee()
{
    if (employeeCount < SIZE)
    {
        printf("\nEnter EmpId = ");
        scanf("%d", &emp[employeeCount].EmpId);
        printf("\nEnter Employee Name = ");
        scanf("%s", emp[employeeCount].EmpName);
        printf("\nEnter Employee Basic Salary = ");
        scanf("%f", &emp[employeeCount].EmpBasicSalary);
        printf("\nEnter Hire Date = ");
        scanf("%d/%d/%d", &emp->HireDate.date, &emp->HireDate.month, &emp->HireDate.year);
        employeeCount++;
    }
    else
    {
        printf("\nNot enough space to store.....");
        return;
    }
    system("cls");
    printf("\n\t\tEmployee Details has been added.\n\n");
}

void showEmployee()
{
    system("cls");
    int id, flag = 0;
    printf("Enter EmpId = ");
    scanf("%d", &id);
    for (int i = 0; i < employeeCount; i++)
    {
        if (id == emp[i].EmpId)
        {
            flag = 1;
            printf("\n\t\t Employee Details ");
            printf("\nEmployee Id = %d", emp[i].EmpId);
            printf("\nName = %s", emp[i].EmpName);
            printf("\nBasic Salary = %0.2f", emp[i].EmpBasicSalary);
            float netsal = calcNetSalary(emp[i].EmpBasicSalary);
            printf("\nNet Salary = %0.2f", netsal);
            printf("\nEmployee Hire Date = %d/%d/%d", emp->HireDate.date, emp->HireDate.month, emp->HireDate.year);
        }
    }
    if (flag == 0)
    {
        printf("\nEmployee Details is not found with id = %d", id);
    }
    printf("\n");
}

float calcNetSalary(int basicSalary)
{
    float da = 0.4 * basicSalary;
    float ta = 0.1 * basicSalary;
    float hra = 0.05 * basicSalary;
    float netSalary = da + ta + hra + basicSalary;
    return netSalary;
}

void deleteEmployee()
{
    int id;
    printf("Enter Employee Id = ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (id == emp[i].EmpId)
        {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++)
            {
                emp[j] = emp[j + 1];
            }
            employeeCount--;
            printf("\nEmployee with id = %d is deleted.", id);
        }
    }
    if (found == 0)
        printf("\nEmployee Not Found....\n");
}
