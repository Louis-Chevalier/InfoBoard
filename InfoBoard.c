#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Fname 20
#define Lname 30

typedef struct {
    char firstname[Fname];
    char lastname[Lname];
    int score;
    int streak;//in days
}employeeComp;

void CreateNewFile();//Create and format the new file
void GetInfo(employeeComp Var1);
void PrintInfo(employeeComp Var1);

int main(){
    employeeComp Emp1;
    GetInfo(Emp1);
    PrintInfo(Emp1);

}

void GetInfo(employeeComp Var1){
    printf("Please enter the first name: ");
    fgets(Var1.firstname, Fname, stdin);
    printf("Please enter the last name: ");
    fgets(Var1.lastname, Lname, stdin);
    printf("Please enter the score: ");
    scanf("%d", Var1.score);
    printf("Please enter any streak held (in days): ");
    scanf("%d", Var1.streak);
}

void PrintInfo(employeeComp Var1){
    FILE *fptr;
    fptr = fopen("EmployeeData.txt", "a");
    fprintf("Employee: %s %s, Score: %d, Streak(days): %d\n", Var1.firstname, Var1.lastname, Var1.score, Var1.streak);
    fclose(fptr);
}

//Now print onto a file
