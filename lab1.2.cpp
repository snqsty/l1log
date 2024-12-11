#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>


typedef struct {
    int id;
    char surname[50];
    char name[50];
    int age;
} student;

student* findStudentById(student students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            return &students[i]; 
        }
    }
    return NULL; 
}

int main() {
    setlocale(LC_ALL, "RUS"); 

    student students[] = {
        {1, "Кучин", "Алексей", 65},
        {2, "Серякова", "Анастасия", 19},
        {3, "Лунин", "Максим", 19},
        {4, "Солдатов", "Дмитрий", 21}
    };
    int size = sizeof(students) / sizeof(students[0]);

    int searchId;

    printf("Введите ID студента: ");
    scanf_s("%d", &searchId);


    student* foundStudent = findStudentById(students, size, searchId);

    if (foundStudent != NULL) {
        printf("Найден студент:\n");
        printf("ID: %d\n", foundStudent->id);
        printf("Фамилия: %s\n", foundStudent->surname);
        printf("Имя: %s\n", foundStudent->name);
        printf("Возраст: %d\n", foundStudent->age);
    }
    else {
        printf("Студент не найден.\n");
    }

    return 0;
}