#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int decks = 0;
	int cards = 0;
	char name[30];

	puts("This is the Cards Program.");

	//Ask the user for a number of decks
	puts("Enter a number of decks and your name: ");
	scanf("%i", &decks);

	puts("Enter your name: ");
	scanf("%s", name);

	//Check if decks is less than 1
	if(decks < 1)
	{
		puts("That is not a valid number of decks.");
		return 1; //Ends program with erroe code.
	}

	//Print out a number of cards
	cards = decks * 52;

	printf("There are %i cards\n", cards);


return 0;
}