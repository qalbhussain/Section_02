#pragma once
#include<string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Lower_Case,
	Wrong_Lenght
};


class FBullCowGame {
public:
	//constructor
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus IsGuessValid(FString) const;


	void Reset();

	//provide a method for counting bulls and cows and increasing try #
	FBullCowCount SubmitGuess(FString);


private:
	int32 MyCurrentTry;
	int32  MyMaxTries;
	FString MyHiddenWord;
	bool bIsGuessTrue;

};