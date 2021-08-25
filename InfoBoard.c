#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Fname 20
#define Lname 30
#define lineLen 100

typedef struct {
    char firstname[Fname];
    char lastname[Lname];
    int score;
    int streak;//in days
}employeeComp;

void createNewFile();//Create and format the new file
void getInfo(char pre[Fname], char nom[Lname], int* num, int* record);
void printInfo(employeeComp Var1);
void createSpaces(char strgot[Lname], FILE *fptrBuff);//Makes spaces to represent empty chars in a string

int main(){
    employeeComp Emp1;
    Emp1.score =0;
    Emp1.streak =0;

    createNewFile();
    getInfo(Emp1.firstname, Emp1.lastname, &Emp1.score , &Emp1.streak);

    //For debugging purposes
    //printf("2)Employee: %s %s, Score: %d, Streak(days): %d\n", Emp1.firstname, Emp1.lastname, Emp1.score, Emp1.streak);

    printInfo(Emp1);
    //readList(Emp1);
    return 0;
}

//Gets the information from user about employee name, lastname, their score, and daily score
void getInfo(char pre[Fname], char nom[Lname], int *num, int *record){
    //int num2,record2;
    printf("Please enter the first name: ");
    fgets(pre, Fname, stdin);
    printf("Please enter the last name: ");
    fgets(nom, Lname, stdin);
    printf("Please enter the score: ");
    scanf("%d", &*num);
    printf("Please enter any streak held (in days): ");
    scanf("%d", &*record);

    //would have done scanf("%d", &num2); but the above code avoids the declaration of two new ints
    //the idea is to scanf a value into the variable pointed by num( which contains the address of Emp1.score)
    // while still keeping the & character so that the compiler doesnt return an error
    //*num = num2;
    //*record = record2;

    //Replace "\n" with "\0" at the end of each string
    pre[strcspn(pre,"\n")] = 0;
    nom[strcspn(nom,"\n")] = 0;

    //For debugging purposes
    //printf("1)Employee: %s %s, Score: %d, Streak(days): %d\n", pre, nom, num, record);
}

void createNewFile(){
    FILE *fptr;
    fptr = fopen("EmployeeData.txt", "r+");
    if (fptr == NULL){
        fclose(fptr);
        fptr = fopen("EmployeeData.txt", "w");
        fprintf(fptr, "           Employee Name                 |     Score     |  Streak |\n");
        fclose(fptr);
    }else{
        fclose(fptr);
        return 0;
    }
}

void printInfo(employeeComp Var2){
    FILE *fptr;
    fptr = fopen("EmployeeData.txt", "a");
    createSpaces(Var2.firstname, fptr);
    createSpaces(Var2.lastname, fptr);
    fprintf(fptr, "  %10d   |   %3d   |\n", Var2.score, Var2.streak);
    //fprintf(fptr,"%s, %s | %d | %d |\n", Var2.firstname, Var2.lastname, Var2.score, Var2.streak);
    fclose(fptr);
}

void readList(employeeComp Var2){
    FILE *fptr;
    char teststr[100];
    if (fptr = fopen("EmployeeData.txt", "r") == NULL){
        printf("ERROR! File not found(file pointer is NULL)\n");
        //printf("exit"); //debug
        exit(1);
    }else{
        //fgets(fptr);
        //Work in Progress
        printf("else\n");
        fgets(teststr,strlen(teststr), fptr);
        printf("%s\n", teststr);
        while(!feof(fptr)){
            //print the line as a whole
            printf("Accessed");
            fgets(teststr,strlen(teststr), fptr);
            printf("%s\n", teststr);
            printf("printed");
        }

    fclose(fptr);
    }
}

void createSpaces(char strgot[Lname], FILE *fptrBuff){
    fprintf(fptrBuff, "%s", strgot);

    for (int i=0; i<(Fname - strlen(strgot));i++){
        fprintf(fptrBuff," ");
    }

    fprintf(fptrBuff,"|");
}
