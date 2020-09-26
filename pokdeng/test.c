#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int deck[], int i, int j)
{
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
}
void shuffle_card(int deck[], int n)
{
    int i;
    for ( i = n - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);
        swap(deck, i, j);
    }
}
void showCards(int deck[], int n){
    int i, card, suit;
    for (i = 0; i < n; ++i)
    {
            card =  1 + deck[i] % 13;
            suit =  3 + deck[i] / 13;
            if (card == 1 )
                printf("A%c  ", suit);
            if (card > 1 && card < 11)
                printf("%d%c   ", card, suit);
            if (card == 11)
                printf("J%c   ", suit);
            if (card == 12)
                printf("Q%c   ", suit);
            if (card == 13)
                printf("K%c   ", suit);
            if (i == 12 || i == 25 || i == 38 || i == 51)
                printf("\n");
    }
}
int main()
{
    int deck[52], P[52][52] = {0}, i, j, k, cardsNum, numPlayer;
    int numDeck = 52;
    int n = sizeof(deck) / sizeof(deck[0]);
    srand(time(NULL));

    for (i = 0, j = 0; i < n; ++i, ++j)
            deck[i] = i ;
    showCards(deck, n);
    shuffle_card(deck, n);
    printf("\nThis is shuffled deck.\n");
    showCards(deck, n);


    printf("How many people do you wanna play ? ");
    scanf("%d", &numPlayer);
    cardsNum = 2;
    for(i = 0, j = 51; i < numPlayer; i++) {
        for(P[i][k] = deck[j];
    }

    for(i = 0; i < numPlayer; i++)
    {
        printf("\nPlayer %d:\n", i + 1);
        showCards(P[i], cardsNum);
        printf("\n");

    }

    return 0;
}
