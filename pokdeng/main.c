#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

void swap(int deck[], int i, int j)
{
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
    temp = NULL;
}

void shuffle_card(int deck[])
{
    srand(time(NULL));
    for (int i = 0; i<52; i++)
    {
        int j = rand() % 52;
        swap(deck, i, j);
    }
}

void display_card(int deck[], int num)
{
    for (int i=0; i<num; i++)
    {
        int section = deck[i]%13;
        int suit = 3+(deck[i]-1)/13;
        if (section > 10 || section == 0) {
            int cards[3] = {'K', 'J', 'Q'};
            printf("%c%c\t", cards[section%10], suit);
        } else if (section == 1) {
            printf("A%c\t", suit);
        } else {
            printf("%d%c\t", section, suit);
        }
        if ((i+1)%13==0){
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    int deck[52];
    int numPlayers = 0;
    int players[52][2];
    int cardPick = 2;
    for (int i=0;i<52;i++)
    {
        deck[i] = i+1;
    }
    display_card(deck, 52);
    printf("This is shuffled deck.\n");
    shuffle_card(deck);
    display_card(deck, 52);
    printf("How many people do you wanna play ? ");
    scanf("%d", &numPlayers);
    for (int j=0;j<cardPick;j++)
    {
        for (int i=0;i<numPlayers;i++)
        {
            int index = 51-(i+(j*numPlayers));
            printf("Player %d pick card %d index %d.\n", i, j, index);
            players[i][j] = deck[index];
        }
    }
    int most = 0;
    int winner = 0;
    for (int i=0;i<numPlayers;i++)
    {
        int points = 0;
        for (int j=0;j<cardPick;j++)
        {
            int point = players[i][j]%13;
            if (point < 10)
            {
                points += point;
            }
        }
        if (points > 10)
        {
            points -= 10;
        }
        if (most < points)
        {
            most = points;
            winner = i;
        }
        printf("Player %d cards have %d points.\n", i, points);
        display_card(players[i], 2);
    }
    printf("Player %d is winner", winner);
    return 0;
}
