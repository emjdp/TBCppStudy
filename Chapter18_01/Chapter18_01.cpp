// Chapter18_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <cstddef>
#include <iostream>
#include <locale>

int main(void)
{
	// c-style string example
	//{
	//	char *strHello = new char[7];
	//	strcpy_s(strHello, sizeof(char) * 7, "hello!");
	//	std::cout << strHello << std::endl;
	//}

	// basic_string<>, string, wstring
	{
		std::string string;
		std::wstring wstring;

		wchar_t wc;
	}

	// wstring example
	{
		// Stackoverflow.com
		// C++ Code to cout international characters using Visual Studio 2015 [cl
		// https://stackoverflow.com/questions/33404685/c-code-to-cout-internatio

		const std::wstring texts[] =
		{
			L"Ñá", //Spanish
			L"forêt intérêt", //French
			L"Gesäß", //German
			L"取消波蘇日奇諾", //Chinese
			L"日本人のビット", //Japanese
			L"немного русский", //Russian
			L"ένα κομμάτι της ελληνικής", // Greek
			L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
			L"کمی از ایران", // Persian (I know it, from 300 movie)
			L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
			L"Но какво, по дяволите, е това?" //Bulgarian
		};

		std::locale::global(std::locale(""));
		std::wcout.imbue(std::locale());

		for (size_t i = 0; i < 11; ++i)
			std::wcout << texts[i] << std::endl;
	}

	return 0;
}

