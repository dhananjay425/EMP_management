#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include<string.h>
#include "Emp_struct.c"
#include "validation.c"
#define SIZE 100



Employee emp[SIZE];
int employeeCount = 0;

void addEmployee()
{
    int id ;
    char FName[25];
    char LName[25];
    float salary;
    int date, month, year;
    if (employeeCount < SIZE)
    {
            int idValid = 0, salaryValid = 0, dateValid = 0;
        while(1)
        {
            printf("\nEnter EmpId = ");
            scanf("%d", &id);
            if(isIdExist(id,emp,employeeCount))
            {
                printf("\nEmployee Id already exists....\n\n please enter unique Employee Id.\n");
                continue;
            }
            if(isIdValid(id))
            {
                idValid = 1;
                break;
            }
            if(idValid == 1)
                break;
            else
            {
                printf("\nId is invalid please enter valid Employee Id....\n Id must be numeric and positive.\n");
            }
        }
        printf("\nEnter First Name = ");
        scanf("%s", FName);
        printf("\nEnter Last Name = ");
        scanf("%s", LName);
        while(1)
        {
            printf("\nEnter Employee Basic Salary = ");
            scanf("%f", &salary);

            if(isSalaryValid(salary))
            {
                salaryValid = 1;
                break;
            }
            if(salaryValid == 1)
                break;
            else{
                printf("\nSalary can not be zero or nagative.\nPlease enter Positive Salary....\n");
            }

        }
        while(1)
        {
            printf("\nEnter Hire Date(dd/mm/yyyy) = ");
            scanf("%d/%d/%d", &date, &month, &year);
            if(isDateValid(date,month,year))
            {
                dateValid = 1;
                break;
            }

            if(dateValid == 1)
            {
                break;
            }else
            {
                printf("\nEntered Date is Invalid....\nPlease enter Valid Date.\n");
            }

        }
        if(idValid == 1 && salaryValid == 1 && dateValid == 1)
        {
            emp[employeeCount].EmpId = id;
            strcpy(emp[employeeCount].FirstName ,FName);
            strcpy(emp[employeeCount].LastName ,LName);
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
            printf("\nName = %s %s", emp[i].FirstName,emp[i].LastName);
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
    char FName[25];
    char LName[25];
    float Salary;

  for (i = 0; i < employeeCount; i++)
  {

    if (emp[i].EmpId == id)
    {
      printf("\nEnter updated First Name = ");
      scanf("%s", FName);
      printf("\nEnter updated Last Name = ");
      scanf("%s", LName);
      

      if (strlen(FName) > 0 && strlen(LName))
      {
        strcpy(emp[i].FirstName, FName);
        strcpy(emp[i].LastName, LName);
      }
      int validSalary = 0;
        while(1)
        {
            printf("\nEnter updated Salary = ");
            scanf("%f", &Salary);   
            if(isSalaryValid(Salary))
            {
                validSalary = 1;
                    emp[i].EmpBasicSalary = Salary;
            }else{
                printf("\nSalary input is Invalid.\n\n please input valid Salary.\n\n");
            }
            if(validSalary == 1)
            break;
        }
      

      printf("\nDetails Updated Successfully.\n");
      return;
    }
  }

  printf("Employee not found.\n");
}
