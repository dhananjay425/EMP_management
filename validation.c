#include "validation.h"
int isIdExist(int id, Employee emp[], int employeeCount)
{
    for(int i = 0; i < employeeCount; i++)
    {
      if(id == emp[i].EmpId)
        {
          return 1;
        }
    }
    return 0;
}
int isIdValid(int id)
{
    if(id < 0) return 0;
  
    return 1;
}
int isSalaryValid(int salary)
{
    if(salary == 0 || salary < 0) return 0;

    return 1;

}
int isDateValid(int date, int month, int year)
{
  if (year >= 1900 && year <= 9999)
  {
    if (month >= 1 && month <= 12)
    {
      if ((date >= 1 && date <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
      {
        //date is valid.
        return 1;
      }
      else if ((date >= 1 && date <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
      {
        //Date is valid.
        return 1;
      }
      else if ((date >= 1 && date <= 28) && (month == 2))
      {
        //Date is valid.
        return 1;
      }
      else if (date == 29 && month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
      {
        //Date is valid.
        return 1;
      }
      else
      {
        //Day is invalid
        return 0;
      }
    }
    else
    {
        //Month is not valid.
        return 0;
    }
  }
  else
  {
    //year is not valid.
    return 0;
  }
}
