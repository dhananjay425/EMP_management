#include <stdio.h>
#include <conio.h>
#include "header.c"

int main()
{
  int choice;

  while (1)
  {
    printf("\n********Menu for Employee Management System*******");
    printf("\n1. Add Employee Details.");
    printf("\n2. Search Employee Details(By Employee Id).");
    printf("\n3. Delete Employee Details.");
    printf("\n4. Update Employee Details.");
    printf("\n5. Exit.");
    printf("\n\n Enter your Choice = ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      system("cls");
      addEmployee();
      printf("\nEnter anything to go to Main menu.......");
      _getch();
      system("cls");
      break;
    case 2:
      system("cls");
      showEmployee();
      printf("\nEnter anything to go to Main menu.......");
      _getch();
      system("cls");
      break;
    case 3:
      system("cls");
      deleteEmployee();
      printf("\n\nEnter anything to go to Main menu.......");
      _getch();
      system("cls");
      break;
    case 4:
      system("cls");
      updateEmployee();
      printf("\n\nEnter anything to go to Main menu.......");
      _getch();
      system("cls");
      break;
    case 5:
      exit(1);
    default:
      printf("Invalid Choice.....\n Please enter valid choice.....\n");
    }
  }
  return 0;
}
