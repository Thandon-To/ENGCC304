#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int play, answer, guess, score;
    int min, max;

    srand(time(NULL));

    do {
        printf("Do you want to play game (1=play, -1=exit): ");
        scanf("%d", &play);

        if (play == 1) {
            answer = rand() % 100 + 1;
            score = 100;
            min = 1;
            max = 100;

            printf("\n(Score=100)\n");

            while (1) {
                printf("Guess the winning number (%d-%d): ", min, max);
                scanf("%d", &guess);

                if (guess < min || guess > max) {
                    printf("Invalid input, please enter a number between %d and %d.\n\n", min, max);
                    continue;
                }

                if (guess == answer) {
                    printf("\nThat is correct! The winning number is %d.\n", answer);
                    printf("Score this game: %d\n\n", score);
                    break;
                }

                score -= 10;

                if (guess < answer) {
                    printf("\nSorry, the winning number is HIGHER than %d. (Score=%d)\n\n", guess, score);
                    if (guess + 1 > min)
                        min = guess + 1;
                } else {
                    printf("\nSorry, the winning number is LOWER than %d. (Score=%d)\n\n", guess, score);
                    if (guess - 1 < max)
                        max = guess - 1;
                }
            }
        }

    } while (play != -1);

    printf("See you again.\n");
    return 0;
}

