#include "FBullCowGame.h"
#include<map>

#define TMap std::map

using int32 = int;

//constructor 
FBullCowGame::FBullCowGame() { Reset(); }


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGuessTrue; }

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLenghtToMaxTries = { {3,5},{4,5},{5,8}, {6,15} };
	return WordLenghtToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "pla";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bIsGuessTrue = false;
	return;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		//Letter = islower(Letter);
		if (!islower(Letter))
		{
			return false;
		}
	}

	return true;
}

//check if the guess is valid of not and return the suitable error message
EGuessStatus FBullCowGame::IsGuessValid(FString Guess) const
{
	/*Psuedocode Programming*/

	if (!IsIsogram(Guess)) //check if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) //check if the guess isn't in lowercase letters
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
	if (BullCowCount.Bulls == HiddenWordLenght) {
		bIsGuessTrue = true;
	}
	else
	{
		bIsGuessTrue = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) {

		Letter = tolower(Letter); //handle mixed cases letters
		if (LetterSeen[Letter]) {
			return false; //we do not have an isogram
		}
		else
		{
			LetterSeen[Letter] = true; // pass the letter to TMap
		}
	}


	return true;
}
