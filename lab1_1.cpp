#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <iostream>

// Функция для вычисления разницы между максимальным и минимальным элементами массива
int differenceMinMax(int arr[], int size) {
    if (size <= 0) return 0; // Обработка пустого массива

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal - minVal;
}

// Функция для инициализации массива случайными числами
void initializeRandom(int arr[], int size) {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Случайные числа от 0 до 99
    }
}

// Функция для вычисления суммы значений в каждом столбце двумерного массива
void sumColumns(int arr[][10], int rows, int cols) { //максимальный размер столбца - 10. Для более гибкого решения - используйте динамическое выделение памяти
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += arr[i][j];
        }
        printf("Сумма элементов в столбце %d: %d\n", j + 1, sum);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int size, rows, cols;

    // Задание 3: Создание массива произвольного размера
    printf("Введите размер одномерного массива: ");
    scanf_s("%d", &size);

    int* arr1 = (int*)malloc(size * sizeof(int));
    if (arr1 == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 1;
    }

    // Задание 2: Инициализация массива случайными числами
    initializeRandom(arr1, size);

    printf("Одномерный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Задание 1: Разница между максимальным и минимальным элементами
    int diff = differenceMinMax(arr1, size);
    printf("Разница между максимальным и минимальным элементами: %d\n", diff);

    free(arr1); // Освобождение памяти


    // Задание 4: Сумма значений в каждом столбце двумерного массива
    printf("Введите количество строк и столбцов двумерного массива (макс. 10 столбцов): ");
    scanf_s("%d %d", &rows, &cols);

    if (cols > 10) {
        printf("Количество столбцов превышает максимальное значение (10).\n");
        return 1;
    }

    int arr2[100][10]; //максимальное количество строк - 100.  Для гибкости использовать динамическое выделение памяти.

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr2[i][j] = rand() % 100;
        }
    }

    printf("Двумерный массив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    sumColumns(arr2, rows, cols);

    return 0;
}