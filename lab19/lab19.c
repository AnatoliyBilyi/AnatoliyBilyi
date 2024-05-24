//А)
#include <stdio.h>
int main() {
FILE *in; // Опис вказівника на файл
int ch;
if ((in = fopen("proba", "r")) != NULL) { // Відкриття файлу для читання, перевірка чи існує
while ((ch = getc(in)) != EOF) { // Отримання символу із файла
putc(ch, stdout); // Виведення символу в стандартний вивід
}
fclose(in); // Закриття файла
} else {
printf("Файл proba не відкривається \n");}
return 0;}
//------------------------------------------------------------------------------------------------------
//   Файл proba не відкривається
//Б)
#include <stdio.h>
int main() {
    FILE *ff;
    int base;
    ff = fopen("sam", "r"); // Відкриття файлу для читання
    fscanf(ff, "%d", &base); // Читання значення з файла
    fclose(ff); // Закриття файла
    ff = fopen("data", "a"); // Відкриття файлу для дописування
    fprintf(ff, "sam is %d.\n", base); // Запис значення у файл
    fclose(ff); // Закриття файла
    return 0; }
В)
#include <stdio.h>
#define LINE 80
int main() {
    FILE *ff;
    char string[LINE]; // Масив для зберігання рядка
    ff = fopen("opus", "r"); // Відкриття файлу для читання
    while (fgets(string, LINE, ff) != NULL) { // Зчитування рядків з файла
        puts(string); // Виведення рядка на екран
    }
    fclose(ff); // Закриття файла
    return 0;}
Г)
#include <stdlib.h>
#include <stdio.h>
int main() {
    int f1, f2, f3, f4, f5;
    FILE *fp;
    fp = fopen("C:\\temp\\sample.txt", "r"); // Відкриття файлу для читання
    if (fp == NULL) { // Перевірка чи файл відкрито успішно
        printf("Помилка відкриття файлу\n");
        return 1;}
    // Читання з файла
    fscanf(fp, "%d\n%d\n%d\n%d\n%d\n", &f1, &f2, &f3, &f4, &f5);
    printf("Значення: %d, %d, %d, %d, %d\n", f1, f2, f3, f4, f5);
    fclose(fp); // Закриття файла
    return 0;}
//------------------------------------------------------------------------------------------------------
//   Помилка відкриття файлу
//Приклад
// Запис файлу
#include <stdio.h>
int main() {
FILE *pf; // Вказівник на файл
int k;
// Відкриття файлу для запису
if ((pf = fopen("proba.txt", "w")) == NULL) { // Перевірка чи відкриття файлу пройшло успішно
perror("proba.txt"); // Виведення повідомлення про помилку
return 1; // Повернення коду помилки
}
// Запис даних у файл
for (k = 0; k <= 5; k++) {
fprintf(pf, "%d %d\n", k, k*k*k*k); // Запис значень у файл
}
fclose(pf); // Закриття файлу
return 0;} 
// Читання даних із файлу proba.txt
#include <stdio.h>
int main() {
FILE *pf; // Вказівник на файл
int n, nn, l;
// Відкриття файлу для читання
if ((pf = fopen("proba.txt", "r")) == NULL) { // Перевірка чи відкриття файлу пройшло успішно
perror("proba.txt"); // Виведення повідомлення про помилку
return 1; } // Повернення коду помилки
}
// Читання даних з файлу
for (l = 0; l <= 5; l++) {
fscanf(pf, "%d %d\n", &n, &nn); } // Зчитування значень з файла
fclose(pf); // Закриття файлу
return 0;} 
//---------------------------------------------------------------------
//запис в пейл
// 0 0
// 1 1
// 2 16
// 3 81
// 4 256
// 5 625
// читання
// n = 0, nn = 0
//n = 1, nn = 1
// n = 2, nn = 16
//n = 3, nn = 81
// n = 4, nn = 256
//             n = 5, nn = 625
//Завдання варіант№1
#include <stdio.h>
#define SIZE 10
void write_to_file(int arr[]) {
FILE *fp;
fp = fopen("numbers.txt", "w");
if (fp == NULL) {
printf("Ne vdalosya vidkryty fail dlya zapisu.\n"); return;
}
for (int i = 0; i < SIZE; i++) {
fprintf(fp, "%d ", arr[i]);
}
fclose(fp);
}
void read_from_file(int arr[]) {
FILE *fp;
fp = fopen("numbers.txt", "r");
if (fp == NULL) {
printf("Ne vdalosya vidkryty fail dlya chitannya.\n"); return;
}
for (int i=0; i < SIZE; i++) {
fscanf(fp, "%d", &arr[i]);
}
fclose(fp);
}
int main() {
int array1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int array2[SIZE];
write_to_file(array1);
printf("Masiv uspishno zapisany u fail 'numbers.txt'.\n"); read_from_file(array2);
printf("Masiv, prochytany z failu:\n");
for (int i = 0; i < SIZE; i++) {
}
printf("%d", array2[i]);
printf("\n");
return 0;
}
//------------------------------------------------------------------------------------------------------
//Masiv uspishno zapisany u fail 'numbers.txt'.
//           Masiv, prochytany z failu:
//           1 2 3 4 5 6 7 8 9 10
//Process exited after 0.03823 seconds with return value 0

