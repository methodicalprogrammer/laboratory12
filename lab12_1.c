#include <stdio.h>
#include <stdlib.h>
#define MAXSTUDENTS 100

typedef struct {
    int AM;
    char name[100];
    double grade;
} student;

student arraySt[MAXSTUDENTS];

void init() {
    for(int i=1;i<MAXSTUDENTS;i++) {
        arraySt[i].AM = -1;
    } 
}
 
void print_menu() {
    printf("Choose from 1 to 4:\n");
    printf("1. Add new student\n2. Delete student by AM\n3. Print all students\n4. Quit\n");
}

int find_student(int x) {
    for(int i=0;i<MAXSTUDENTS;i++) {
        if(arraySt[i].AM == x) {
            return i;
        }
    }
    return -1;
}


void add_new_student() {
    int index = find_student(-1);
    if(index == -1) {
        printf("There's no empty slot\n");
        return;
    }
    student tmp;

    printf("Type student's AM:\n");
    scanf("%d", &tmp.AM);
    printf("Type student's name:\n");
    scanf("%s", &tmp.name);
    printf("Type student's grade:\n");
    scanf("%lf", &tmp.grade);

    arraySt[index] = tmp;
}

void delete_student() {
    int AM;
    printf("Type student's AM:\n");
    scanf("%d", &AM);

    int index = find_student(AM);
    if(index == -1) {
        printf("The student's AM: %d was not found.\n", AM);
        return;
    }
    arraySt[index].AM = -1;
}

void print_students() {
    for(int i=0;i<MAXSTUDENTS;i++) {
        if(arraySt[i].AM != -1) {
            printf("AM:%d\tName:%s\tGrade:%lf\n", arraySt[i].AM, arraySt[i].name, arraySt[i].grade);
        }
    }
}

int main(int argc, char **argv) {
    int run = 1;
    char choice;
    
    while(run) {
        print_menu();
        do {
            scanf("%c", &choice);
        }
        while (choice<'1'||choice>'4');
        switch(choice) {
            case '1':
                add_new_student();
                break;
            case '2':
                delete_student();
                break;
            case '3':
                print_students();
                break;
            case '4':
                run = 0;
                break;
        }   
    } 
}




