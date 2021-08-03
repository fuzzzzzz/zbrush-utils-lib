#pragma once
#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
*  in your project.
*/

#define ZBRUSH_API extern "C" __declspec(dllexport)



	//ZBrush expects these arguments for a dll function, though it's best to only use the first three
	// pDontCare == string input
	// optValue  == number input
	// 

// ZBrush lib
ZBRUSH_API float Version(char* pDontCare, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float MsgBoxInfo(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float MsgBoxWarning(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);
							

// Smart UI
ZBRUSH_API float IsSwitchType(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

// Strings
ZBRUSH_API float Is_Digit(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Is_Alpha(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Is_Space(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Is_Punct(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Is_AlNum(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);


// Math 
ZBRUSH_API float Sine(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Cosine(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Tangent(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Floor(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Ceil(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Exponent(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Power(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Trunc(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Round(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Remainder(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);


// shell 
ZBRUSH_API float OpenURL(char* pSometext, double optValue, char* pOptBuffer1, int optBuffer1Size,
		char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float _ShellExecute(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData);


// clipboard 
ZBRUSH_API float Get_ClipBoard_Files(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Get_ClipBoard_Text(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData);

// time
ZBRUSH_API float Time_Format(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Precision_TimeStamp(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float Start_Counter(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData);

ZBRUSH_API float End_Counter(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData);
#endif // __MAIN_H__