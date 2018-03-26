#ifndef __UTIL_H__
#define __UTIL_H__

// MFCで使う時用
//#define _MFC
#ifdef _MFC
#ifdef _DEBUG
#undef new
#endif
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#else
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#endif
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define TRUE 1
#define FALSE 0
#define SOCKET_ERROR (-1)
typedef int BOOL;
typedef BOOL *LPBOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef int INT;
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef int64_t LONGLONG;
typedef uint64_t ULONGLONG;
//typedef long long __int64;
#define __int64 long long
typedef char CHAR;
typedef CHAR *LPSTR;
typedef const CHAR *LPCSTR;
typedef wchar_t WCHAR;
typedef WCHAR *LPWSTR;
typedef const WCHAR *LPCWSTR;
typedef int SOCKET;
typedef void *HANDLE;

typedef struct _SYSTEMTIME { 
   WORD wYear; 
   WORD wMonth; 
   WORD wDayOfWeek; 
   WORD wDay; 
   WORD wHour; 
   WORD wMinute; 
   WORD wSecond; 
   WORD wMilliseconds; 
} SYSTEMTIME;
void ZeroMemory(void *Destination,size_t Length);
char *strnlwr(char *str,size_t size);
wchar_t*wcsnlwr(wchar_t *str,size_t size);
void OutputDebugString(LPCWSTR lpOutputString);
#define closesocket close
#define vsprintf_s vsnprintf
#define _vscprintf(format,argptr) vsnprintf(NULL,0,format,argptr)
#define vswprintf_s vswprintf
#define _vscwprintf(format,argptr) vswprintf(NULL,0,format,argptr)
#define strcpy_s(dist,size,src) strncpy(dist,src,size)
#define wcscpy_s(dist,size,src) wcsncpy(dist,src,size)
#define _strlwr_s strnlwr
#define _wcslwr_s wcsnlwr

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }

//セキュリティをNULLにして各種作成
/*HANDLE _CreateEvent(BOOL bManualReset, BOOL bInitialState, LPCTSTR lpName );
HANDLE _CreateFile( LPCTSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile );
HANDLE _CreateFile2( LPCTSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile );
HANDLE _CreateMutex( BOOL bInitialOwner, LPCTSTR lpName );
HANDLE _CreateFileMapping( HANDLE hFile, DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCTSTR lpName );
HANDLE _CreateNamedPipe( LPCTSTR lpName, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut );
BOOL _CreateDirectory( LPCTSTR lpPathName );
//ボリュームのマウントを考慮して実ドライブの空きを取得する
BOOL _GetDiskFreeSpaceEx(
  LPCTSTR lpDirectoryName,                 // ディレクトリ名
  PULARGE_INTEGER lpFreeBytesAvailable,    // 呼び出し側が利用できるバイト数
  PULARGE_INTEGER lpTotalNumberOfBytes,    // ディスク全体のバイト数
  PULARGE_INTEGER lpTotalNumberOfFreeBytes // ディスク全体の空きバイト数
);
void _OutputDebugString(const TCHAR *pOutputString, ...);
void GetLastErrMsg(DWORD err, wstring& msg);*/

#endif
