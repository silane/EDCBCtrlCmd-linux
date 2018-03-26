#include "Util.h"

#include <wctype.h>

void ZeroMemory(void *Destination,size_t Length)
{
	memset(Destination,0,Length);
}

char *strnlwr(char *str,size_t size)
{
	for(size_t i=0;i<size;i++)
	{
		if(str[i]=='\0')
			break;
		str[i]=tolower((unsigned char)str[i]);
	}

	return str;
}

wchar_t *wcsnlwr(wchar_t *str,size_t size)
{
	for(size_t i=0;i<size;i++)
	{
		if(str[i]==L'\0')
			break;
		str[i]=(wchar_t)towlower((wint_t)str[i]);
	}

	return str;
}

void OutputDebugString(LPCWSTR lpOutputString)
{
}
