#include <stdio.h>

int main(void) {
    int score;

    while (1) {
        int found = 0;
      
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1)
            return 0;
        if (score == 1)
            break;
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
      
        for (int TD2 = 0; TD2 <= score / 8; ++TD2) {
            for (int TD1 = 0; TD1 <= score / 7; ++TD1) {
                for (int TD = 0; TD <= score / 6; ++TD) {
                    for (int FG3 = 0; FG3 <= score / 3; ++FG3) {
                        for (int safties = 0; safties <= score / 2; ++safties) {
                            if (8*TD2 + 7*TD1 + 6*TD + 3*FG3 + 2*safties == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       TD2, TD1, TD, FG3, safties);
                                found = 1;
                            }
                        }
                    }
                }
            }
        }

        if (!found) {
            printf("No combinations found.\n");
        }
        printf("\n");
      
    }
    return 0;
}
