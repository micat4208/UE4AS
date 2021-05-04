#include "SaveData.h"

FSaveData::FSaveData()
{

}

FSaveData::FSaveData(float bestScore, FDateTime dateTime)
{

	BestScore	= bestScore;

	Year		= dateTime.GetYear();
	Month		= dateTime.GetMonth();
	Day			= dateTime.GetDay();
	Hours		= dateTime.GetHour();
	Minutes		= dateTime.GetMinute();
	Seconds		= dateTime.GetSecond();
}