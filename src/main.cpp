#include "stdafx.h"
// #include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <math.h>
#include <time.h>
#include <regex>
#include <assert.h>
#include <shellapi.h>
#include "main.h"
#include "switch.h"
#include "pch.h"

using namespace std;

// dllmain.cpp : Defines the entry point for the DLL application.
#define PI 3.14159265

static double degree_to_radiant(double angle)
{
	double radiant = (angle * PI) / 180; 
	
	return radiant;
}

static double radiant_to_degree(double angle)
{
	double degree = (angle * PI) / 180; 
	
	return degree;
}

char * GetClipboardText(char * pOptBuffer1)
{

	char * pszText;
	OpenClipboard(nullptr);
    HANDLE hData = GetClipboardData(CF_TEXT);
    pszText = (char*)GlobalLock(hData);

	strcat(pOptBuffer1, pszText);
    GlobalUnlock( hData );
    CloseClipboard();

    return pOptBuffer1;
}

char * GetClipboardFile(char * pOptBuffer1)
{
    
	OpenClipboard(nullptr);
	HGLOBAL hGlobal = (HGLOBAL)GetClipboardData(CF_HDROP);
	char pszText[MAX_PATH];

	if (hGlobal)
	{
		HDROP hDrop = (HDROP)GlobalLock(hGlobal);

		UINT uFile = 0;
		unsigned int i = 0;

    	uFile = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, NULL);
    	if (uFile != 0)
    	{
			while ( i < uFile )
        	{
				DragQueryFile(hDrop, i, pszText, MAX_PATH);
				strcat(pszText,"\n");
				strcat(pOptBuffer1, pszText);
				i++;
			}
		}
		DragFinish(hDrop);

		GlobalUnlock(hGlobal);
	}
    CloseClipboard();

    return pOptBuffer1;
}


// a sample exported function
ZBRUSH_API float Version(char* pDontCare, double optValue, char* pOptBuffer1, int optBuffer1Size,
							char* pOptBuffer2, int optBuffer2Size, char** zData)
{
    return 1.01f;
}

ZBRUSH_API float MsgBoxInfo(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
							char* pOptBuffer2, int optBuffer2Size, char** zData)
{

	std::string message = pStrValue;
	MessageBoxA(0, pStrValue, "Confirm Warning Message ?", MB_OK | MB_ICONINFORMATION);
	strcpy(pOptBuffer1, message.c_str());

	return 1.0f;// Sucess
}

ZBRUSH_API float MsgBoxWarning(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
							char* pOptBuffer2, int optBuffer2Size, char** zData)
{

	std::string message = "No";
	int msgboxID = MessageBoxA(0, pStrValue, "DLL received Message", MB_YESNO | MB_ICONEXCLAMATION);

	if (msgboxID == IDYES)
		std::string message = "Yes";

		strcpy(pOptBuffer1, message.c_str());
		return 1.0f;// Sucess

	strcpy(pOptBuffer1, message.c_str());
	return 0.0f;// Fail
}

// For SmartUI plugin
ZBRUSH_API float IsSwitchType(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	
	// if the first char is a digits the button
	// path is not valid
	if (isdigit(*pStrValue))
		return 0.0f;

	int i = 0;
	int s = (sizeof switches / sizeof switches[0]) - 1;
	for (i = 0; i <=s; i++)
	{	
		if (strcmp(switches[i], pStrValue) == 0)
			return 1.0f;
	}

	return 0.0f;

}


ZBRUSH_API float Is_Digit(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	size_t size = strlen(pStrValue);
	float result = 0.0;
	
	std::string text = pStrValue;
	strcpy(pStrValue, text.c_str());

	for (int i = 0; i< size; i++)
	{
		if (isdigit(text[i]))
			result = 1.0f;
		//check for ERRORs
		else if (text[i] == NULL)
			result = -1.0f;
		else
			return 0.0f;
	}
	return result;
}

ZBRUSH_API float Is_Alpha(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	size_t size = strlen(pStrValue);
	float result = 0.0;
	
	std::string text = pStrValue;
	strcpy(pStrValue, text.c_str());

	for (int i = 0; i< size; i++)
	{
		if (isalpha(text[i]))
			result = 1.0f;
		//check for ERRORs
		else if (text[i] == NULL)
			result = -1.0f;
		else
			return 0.0f;
	}
	return result;
}

ZBRUSH_API float Is_Space(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	size_t size = strlen(pStrValue);
	float result = 0.0;
	
	std::string text = pStrValue;
	strcpy(pStrValue, text.c_str());

	for (int i = 0; i< size; i++)
	{
		if (isspace(text[i]))
			result = 1.0f;
		//check for ERRORs
		else if (text[i] == NULL)
			result = -1.0f;
		else
			return 0.0f;
	}
	return result;

}

ZBRUSH_API float Is_Punct(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	size_t size = strlen(pStrValue);
	float result = 0.0;
	
	std::string text = pStrValue;
	strcpy(pStrValue, text.c_str());

	for (int i = 0; i< size; i++)
	{
		if (ispunct(text[i]))
			result = 1.0f;
		//check for ERRORs
		else if (text[i] == NULL)
			result = -1.0f;
		else
			return 0.0f;
	}
	return result;	
}

ZBRUSH_API float Is_AlNum(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	size_t size = strlen(pStrValue);
	float result = 0.0;
	
	std::string text = pStrValue;
	strcpy(pStrValue, text.c_str());

	for (int i = 0; i< size; i++)
	{
		if (isalnum(text[i]))
			result = 1.0f;
		//check for ERRORs
		else if (text[i] == NULL)
			result = -1.0f;
		else
			return 0.0f;
	}
	return result;
}


// math
ZBRUSH_API float Sine(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	double result = sin(optValue*PI/180);
	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(result,6,pOptBuffer1);
	
	return 1.0f; // success
}

ZBRUSH_API float Cosine(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	double result = cos(optValue*PI/180);
	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(result,6,pOptBuffer1);
	
	return 1.0f; // success
}
ZBRUSH_API float Tangent(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	double result = tan(optValue*PI/180);
	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(result,6,pOptBuffer1);
	
	return 1.0f; // success
}

ZBRUSH_API float Floor(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	double result = floor(optValue);

	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(result,6,pOptBuffer1);
	
	return 1.0f; // success
}

ZBRUSH_API float Ceil(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	double result = ceil(optValue);

	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(_ceil,6,pOptBuffer1);
	
	return 1.0f; // success
}

ZBRUSH_API float Exponent(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	double result = exp(optValue);

	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(_ceil,6,pOptBuffer1);
	
	return 1.0f; // success
}

ZBRUSH_API float Power(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{	
	char * ptr;
	double result = pow(strtod(pStrValue, &ptr),optValue);

	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(_ceil,6,pOptBuffer1);
	
	return 1.0f; // success
}

ZBRUSH_API float Trunc(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	double result = trunc(optValue);

	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(result,6,pOptBuffer1);
	
	return 1.0f; // success
}

ZBRUSH_API float Round(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	double result = round(optValue);

	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(result,6,pOptBuffer1);
	
	return 1.0f; // success
}

ZBRUSH_API float Remainder(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	char * ptr;
	double value = strtod(pStrValue, &ptr);
	// float value = atof(pStrValue); // warning C4244: '=' : conversion from 'double' to 'float', possible loss of data
	double result = remainder(value, (float)optValue);

	if (result == NULL)
		return 0.0f; // error handling

	sprintf (pOptBuffer1, "%f", result);
	// _gcvt(_ceil,6,pOptBuffer1);
	
	return 1.0f; // success
}


// SHELL Stuff
ZBRUSH_API float OpenURL(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	ShellExecute(NULL, "open", pStrValue,
                NULL, NULL, SW_SHOWNORMAL);
	return 1.0f;

}

ZBRUSH_API float _ShellExecute(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	//duplicate th ebuffer
	char * cmd = _strdup(pOptBuffer1);
	FILE *fp;

	// Open the command for reading.
  	fp = _popen(cmd, "r");

	//i filas then 
  	if (fp == NULL)
	{
		return 0.0f;
  	}
	
	// Create a buffer to store the stdout/stderr
	char output[4096];
	// Read the output a line at a time - output it.
	while (fgets(output, sizeof(output), fp) != NULL)
	{
		strcat(pOptBuffer1, output);
	}
  	_pclose(fp);

	return 1.0f;

}


// clipboard
ZBRUSH_API float Get_ClipBoard_Files(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{	
	char * text = (char *)GetClipboardFile(pOptBuffer1);
	if (text == NULL)
		return 0.0f;
	return 1.0f;
}

ZBRUSH_API float Get_ClipBoard_Text(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{	
	char * text = (char *)GetClipboardText(pOptBuffer1);
	if (text == NULL)
		return 0.0f;
	return 1.0f;
}


// time.h
// https://www.cplusplus.com/reference/ctime/

ZBRUSH_API float Time_Format(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{	
	time_t rawtime;
  	struct tm * timeinfo;

	// char * time;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	if (pStrValue == NULL)
		pStrValue = "The current time is : %I:%M%p.";
		// strcpy(pStrValue,"The current time is : %I:%M%p.");
		
	strftime (pOptBuffer1,255, pStrValue,timeinfo);
	return 1.0f;

}

ZBRUSH_API float Precision_TimeStamp(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	struct timespec ts;

    timespec_get(&ts, TIME_UTC);
	strftime(pOptBuffer1, 255, pStrValue, gmtime(&ts.tv_sec));

	return 1.0f;
}

ZBRUSH_API float Start_Counter(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	char * test = (char*)timeinfo;
	strcpy(pOptBuffer1, test);

	return 1.0f;
}

ZBRUSH_API float End_Counter(char* pStrValue, double optValue, char* pOptBuffer1, int optBuffer1Size,
	char* pOptBuffer2, int optBuffer2Size, char** zData)
{	
   	
	time_t end_time;
	time(&end_time);
	
	int start_time;
	// start_time = pOptBuffer1;

	// int start_time_;
	start_time = atoi(pOptBuffer1);
	double result =  difftime((time_t)start_time, end_time);
  	// struct tm * timeinfo = {0};
	// if (timeinfo == NULL)
	// 	return 0.0f;


	// if (pStrValue == NULL)
	// 	pStrValue = "The current time is : %I:%M%p.";
		// strcpy(pStrValue,"The current time is : %I:%M%p.");
		
	// strftime (pOptBuffer1,255, pStrValue,timeinfo);

    // sprintf(pStrValue, "The system time is: %02d:%02d\n", st.wHour, st.wMinute);
    // sprintf(pOptBuffer1, " %02d:%02d:%02d:%03d\n", lt.wHour, lt.wMinute, lt.wSecond, lt.wMilliseconds);
	
	// if (pStrValue == NULL)
		// return 0.0f;

	// strcpy(pOptBuffer1, pStrValue);
	return 1.0f;

}

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
			// Initialize once for each new process.
			// Return FALSE to fail DLL load.
			// break;
		case DLL_THREAD_ATTACH:
			// Do thread-specific initialization.
			// break;
		case DLL_THREAD_DETACH:
			// Do thread-specific cleanup.
			// break;
		case DLL_PROCESS_DETACH:
			// Perform any necessary cleanup.
			break;

//	default:
//		break;
	}
	return TRUE;

}