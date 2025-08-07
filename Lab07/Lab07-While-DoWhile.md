#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int play, answer, score, guess;
    int min, max;
    char input[100];

    srand(time(NULL)); // สุ่มตัวเลขทุกครั้งไม่ให้ซ้ำ

    do {
        printf("Do you want to play game (1=play,-1=exit) :\n");

        fgets(input, sizeof(input), stdin);  // รับค่าจากผู้ใช้
        if(sscanf(input, "%d", &play) != 1 || (play != 1 && play != -1)) {
            printf("Please enter only 1 or -1.\n\n");
            play = 0;  // รีเซ็ต play เพื่อเล่นใหม่
            continue;
        }

        if (play == 1){
            answer = rand() % 100 + 1;
            score = 100;
            min = 1;
            max = 100;

            printf("\n(Score=100)\n");

            while (1) {
                printf("Guess the winning number (%d-%d) :\n", min, max);
                fgets(input, sizeof(input), stdin);

                if (sscanf(input, "%d", &guess) != 1 || guess < min || guess > max){
                    printf("Invalid input. Please enter a number between %d and %d.\n\n", min, max);
                    continue;
                }

                if (guess == answer){
                    printf("\nThat is correct! The winning number is %d.\n", answer);
                    printf("\nScore this game: %d\n\n", score);
                    break;
                }

                score -= 10;

                if (guess < answer) {
                    printf("\nSorry, the winning number is HIGHER than %d. (Score=%d)\n\n", guess, score);
                    if (guess + 1 > min) min = guess + 1;
                } else {
                    printf("\nSorry, the winning number is LOWER than %d. (Score=%d)\n\n", guess, score);
                    if (guess - 1 < max) max = guess - 1;
                }
            }
        }
    } while (play != -1);

    printf("\nSee you again.\n");
    return 0;
}

