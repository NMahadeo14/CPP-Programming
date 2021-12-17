/***********************************************************************
// 244-200 Workshop 1: Compiling modular source code
// File	w1.cpp
// Version 1.0
// Date	2020/01/10
// Author	Fardad Soleimanloo
// Description
// This provides some source code in a single file to break
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name Devin Mahadeo   Date 2020-01-13    Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include "Word.h"
using namespace sdds;

int main()
{
	programTitle();
	wordStats(true);

	return 0;
}
