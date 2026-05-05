#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int knightLife = 20;
int monsterLife = 20;
int RoundLog = 1;
int knightattack_sec;
int monsterattack_sec;

int knightattack()
{
    return 5 + rand() % (8);
}
int heal()
{
    return 8 + rand() % (8);
}
int specialattack()
{
    return 8 + rand() % (18);
}
int monsterattack()
{
    return 8 + rand() % (5);
}
void printRoundlog(int knightattack_sec, int monsterattack_sec)
{
    printf("---Round%d---\n", RoundLog);
    printf("You attacked the monster and dealt %d damage\n", knightattack_sec);
    printf("The monster attacked and dealt %d damage\n", monsterattack_sec);
}

void printStatus()
{
    printf("Knight HP: %d\n", knightLife);
    printf("Monster HP: %d\n", monsterLife);
}
int main()
{
    srand(time(NULL));
    while (knightLife > 0 && monsterLife > 0)
    {
        char action;
        printf("Choose your action (A)ttack, (H)eal, (S)pecial Attack: %c", action);
        scanf(" %c", &action);
        int knightattack_sec = 0;
        int monsterattack_sec = 0;

        switch (action)
        {
        case 'A':
            knightattack_sec = knightattack();
            monsterattack_sec = monsterattack();
            monsterLife -= knightattack_sec;
            knightLife -= monsterattack_sec;
            printRoundlog(knightattack_sec, monsterattack_sec);
            printStatus();
            RoundLog++;
            break;

        case 'H':
            knightattack_sec = heal();
            monsterattack_sec = monsterattack();
            knightLife += knightattack_sec;
            knightLife -= monsterattack_sec;
            printf("\n--- Round %d ---\n", RoundLog);
            printf("You healed for %d HP!\n", knightattack_sec);
            printf("The monster attacked for %d damage!\n", monsterattack_sec);
            printStatus();
            RoundLog++;
            break;

        case 'S':
            if ((RoundLog > 1) && (RoundLog - 1) % 3 == 0)
            {
                knightattack_sec = specialattack();
                monsterattack_sec = monsterattack();
                monsterLife -= knightattack_sec;
                knightLife -= monsterattack_sec;
                printRoundlog(monsterattack_sec, monsterattack_sec);
                printStatus();
                RoundLog++;
            }
            else
            {
                printf("This skill is not available\n");
            }
            break;
        default:
            break;
        }
    }
    if (knightLife == 0)
    {
        printf("You Lost");
    }
    else if (monsterLife == 0)
    {
        printf("you win");
    }
    return 0;
}
