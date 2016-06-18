/*
This is Main CPP file
i'm Playing with Git stuff
I've learned alot of stuff
*/


#include<iostream>
#include<string>
#include "main.h"
#include"FBullCowGame.h"

using FText = std::string;
using int32 = int; 

//funtions prototype
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //initialize an instance of class: FBullCowGame() and make it global so it can access from everywhere

int main() {
	
	
	//Print Intro of Game
	PrintIntro();

	do {
		//play the game
		PlayGame();
	} while (AskToPlayAgain());
	

	return 0;	//exit the game
}



//declaration of function PrintIntro
void PrintIntro()
{
	//introduce the game
	int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows :) ";
	std::cout << std::endl;
	std::cout << "Can you guess this " << WORD_LENGTH << " letter word, i'm thinking of?\n";
	std::cout << std::endl;

	return;
}

//play the game
void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();
	//Get the Guess From player
	for (int32 count = 0; count <= MaxTries; count++)
	{
		FText Guess = GetValidGuess();
		

		//submit a valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bull = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows;

		std::cout << std::endl;
	}

}

//get Valid guess from user
FText GetValidGuess() 
{	

	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do {
	//get a guess from player
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";	
	std::cout << "Try " << CurrentTry << ".Enter your Guess:";
	std::getline(std::cin, Guess);

	//checking if the guess is valid
	Status = BCGame.IsGuessValid(Guess);
	
	

		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please Enter a word without repeating letters !" << std::endl;
			break;
		case EGuessStatus::Lower_Case:
			std::cout << "Please Enter all lower case letters !" << std::endl;
			break;
		case EGuessStatus::Wrong_Lenght:
			std::cout << "Please Enter a " << BCGame.GetHiddenWordLength() << " letter Word !" << std::endl;
			break;
		default:
			return Guess;
			break;
		}
		std::cout << std::endl;

	} while (Status != EGuessStatus::OK); //keep looping until we get no errors or we get Status == OK
	

}

bool AskToPlayAgain()
{
	FText Response = "";

	std::cout << "Do you want to Play again? " << std::endl;
	std::getline(std::cin, Response);
	return ((Response[0] == 'y')|| (Response[0] == 'Y'));
}
