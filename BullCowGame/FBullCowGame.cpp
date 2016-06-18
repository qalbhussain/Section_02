#include "FBullCowGame.h"
#include<iostream>

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "Planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}


//check if the guess is valid of not and return the suitable error message
EGuessStatus FBullCowGame::IsGuessValid(FString Guess) const
{
	/*Psuedocode Programming*/

	if (false) //check if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) //check if the guess isn't in lowercase letters
	{
		return EGuessStatus::Lower_Case;
	}
	else if (Guess.length() != GetHiddenWordLength()) //check if the guess has wrong lenght
	{

		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::OK;
	}

}


//receives a Vlid guess increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 MyHiddenWordChar = 0; MyHiddenWordChar < HiddenWordLenght; MyHiddenWordChar++) {
		//compare letters against the hidden word
		for (int32 GuessChar = 0; GuessChar < HiddenWordLenght; GuessChar++) {
			//if they match then
			if (Guess[GuessChar] == MyHiddenWord[MyHiddenWordChar]) {

				//if they are in same place
				if (MyHiddenWordChar == GuessChar) {
					//increment bull
					BullCowCount.Bulls++;
				}
				//else
				else {
					//increment cows
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
