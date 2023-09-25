#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "header.h"
#include "Emp_struct.c"
#include "validation.c"
#define SIZE 100



Employee emp[SIZE];
int employeeCount = 0;

void addEmployee()
{
    int id ;
    char name[25];
    float salary;
    int date, month, year;
    if (employeeCount < SIZE)
    {
            int flag1 = 0, flag2 = 0, flag3 = 0;
        while(1)
        {
            printf("\nEnter EmpId = ");
            scanf("%d", &id);   
            if(isIdValid(id))
            {
                flag1 = 1;
                break;
            }
            if(flag1 == 1)
                break;
            else
            {
                system("cls");
                printf("\nId is invalid please enter valid Employee Id....\n Id must be numeric and positive.\n");
            }
        }
        printf("\nEnter Employee Name = ");
        scanf("%s", name);
        while(1)
        {
            printf("\nEnter Employee Basic Salary = ");
            scanf("%f", &salary);

            if(isSalaryValid(salary))
            {
                flag2 = 1;
                break;
            }
            if(flag2 == 1)
                break;
            else{
                system("cls");
                printf("\nSalary can not be zero or nagative.\nPlease enter Positive Salary....\n");
            }

        }
        while(1)
        {
            printf("\nEnter Hire Date = ");
            scanf("%d/%d/%d", &date, &month, &year);
            if(isDateValid(date,month,year))
            {
                flag3 = 1;
                break;
            }

            if(flag3 == 1)
            {
                break;
            }else
            {
                   system("cls");
                printf("\nEntered Date is Invalid....\nPlease enter Valid Date.\n");
            }

        }
        if(flag1 == 1 && flag2 == 1 && flag3 == 1)
        {
            emp[employeeCount].EmpId = id;
            strcpy(emp[employeeCount].EmpName,name);
            emp[employeeCount].EmpBasicSalary = salary;
            emp[employeeCount].HireDate.date = date;
            emp[employeeCount].HireDate.month = month;
            emp[employeeCount].HireDate.year = year;
            
            employeeCount++;
        }
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
    printf("Enter Employee Id to search = ");
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
    printf("Enter Employee Id to Delete the Employee Details = ");
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
void updateEmployee()
{
    int id;
    printf("Enter Employee id to Update = ");
    scanf("%d", &id);
    int i;
    char name[50];
    float Salary;

  for (i = 0; i < employeeCount; i++)
  {

    if (emp[i].EmpId == id)
    {
      printf("\nEnter updated Name = ");
      scanf("%s", name);

      printf("\nEnter updated Salary = ");
      scanf("%f", &Salary);

      if (strlen(name) > 0)
      {
        strcpy(emp[i].EmpName, name);
      }

      if (Salary > 0)
      {
        emp[i].EmpBasicSalary = Salary;
      }

      printf("\nDetails Updated Successfully.\n");
      return;
    }
  }

  printf("Employee not found.\n");
}
