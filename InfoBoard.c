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
void GetInfo(char pre[Fname], char nom[Lname], int num, int record);
void PrintInfo(employeeComp Var1);

int main(){
    employeeComp Emp1;
    Emp1.score =0;
    Emp1.streak =0;
    GetInfo(Emp1.firstname, Emp1.lastname, Emp1.score , Emp1.streak);
    printf("2)Employee: %s %s, Score: %d, Streak(days): %d\n", Emp1.firstname, Emp1.lastname, Emp1.score, Emp1.streak);
    //PrintInfo(Emp1);
    return 0;
}

void GetInfo(char pre[Fname], char nom[Lname], int num, int record){
    printf("Please enter the first name: ");
    fgets(pre, Fname, stdin);
    printf("Please enter the last name: ");
    fgets(nom, Lname, stdin);
    printf("Please enter the score: ");
    scanf("%d", &num);
    printf("Please enter any streak held (in days): ");
    scanf("%d", &record);

    //Replace "\n" with "\0" at the end of each string
    pre[strcspn(pre,"\n")] = 0;
    nom[strcspn(nom,"\n")] = 0;

    printf("1)Employee: %s %s, Score: %d, Streak(days): %d\n", pre, nom, num, record);
}

void PrintInfo(employeeComp Var2){
    FILE *fptr;
    fptr = fopen("EmployeeData.txt", "a");
    fprintf(fptr,"Employee: %s %s, Score: %d, Streak(days): %d\n", Var2.firstname, Var2.lastname, Var2.score, Var2.streak);
    fclose(fptr);
}

//Now print onto a file
