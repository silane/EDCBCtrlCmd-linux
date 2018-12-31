#ifndef __CTRL_CMD_UTIL2_H__
#define __CTRL_CMD_UTIL2_H__

#include "StructDef.h"

////////////////////////////////////////////////////////////////////////////////////////////
//コマンド送信用バイナリ作成関数

DWORD GetVALUESize2(WORD ver, int8_t val );
BOOL WriteVALUE2(WORD ver, int8_t val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, int8_t* val, BYTE* buff, DWORD buffSize, DWORD* readSize );
DWORD GetVALUESize2(WORD ver, uint8_t val );
BOOL WriteVALUE2(WORD ver, uint8_t val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, uint8_t* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, int16_t val );
BOOL WriteVALUE2(WORD ver, int16_t val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, int16_t* val, BYTE* buff, DWORD buffSize, DWORD* readSize );
DWORD GetVALUESize2(WORD ver, uint16_t val );
BOOL WriteVALUE2(WORD ver, uint16_t val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, uint16_t* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, int32_t val );
BOOL WriteVALUE2(WORD ver, int32_t val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, int32_t* val, BYTE* buff, DWORD buffSize, DWORD* readSize );
DWORD GetVALUESize2(WORD ver, uint32_t val );
BOOL WriteVALUE2(WORD ver, uint32_t val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, uint32_t* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, int64_t val );
BOOL WriteVALUE2(WORD ver, int64_t val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, int64_t* val, BYTE* buff, DWORD buffSize, DWORD* readSize );
DWORD GetVALUESize2(WORD ver, uint64_t val );
BOOL WriteVALUE2(WORD ver, uint64_t val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, uint64_t* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<uint16_t>* val);
BOOL WriteVALUE2(WORD ver, vector<uint16_t>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<uint16_t>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<uint32_t>* val);
BOOL WriteVALUE2(WORD ver, vector<uint32_t>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<uint32_t>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<int64_t>* val);
BOOL WriteVALUE2(WORD ver, vector<int64_t>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<int64_t>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, wstring val );
BOOL WriteVALUE2(WORD ver, wstring val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, wstring* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<wstring>* val );
BOOL WriteVALUE2(WORD ver, vector<wstring>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<wstring>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, SYSTEMTIME* val );
BOOL WriteVALUE2(WORD ver, SYSTEMTIME* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, SYSTEMTIME* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, REC_FILE_SET_INFO* val );
BOOL WriteVALUE2(WORD ver, REC_FILE_SET_INFO* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, REC_FILE_SET_INFO* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<REC_FILE_SET_INFO>* val );
BOOL WriteVALUE2(WORD ver, vector<REC_FILE_SET_INFO>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<REC_FILE_SET_INFO>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, REC_SETTING_DATA* val );
BOOL WriteVALUE2(WORD ver, REC_SETTING_DATA* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, REC_SETTING_DATA* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, RESERVE_DATA* val );
BOOL WriteVALUE2(WORD ver, RESERVE_DATA* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, RESERVE_DATA* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<RESERVE_DATA>* val );
BOOL WriteVALUE2(WORD ver, vector<RESERVE_DATA>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<RESERVE_DATA>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );
DWORD GetVALUESize2(WORD ver, vector<RESERVE_DATA*>* val );
BOOL WriteVALUE2(WORD ver, vector<RESERVE_DATA*>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<RESERVE_DATA*>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, NOTIFY_SRV_INFO* val );
BOOL WriteVALUE2(WORD ver, NOTIFY_SRV_INFO* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, NOTIFY_SRV_INFO* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, EPGDB_CONTENT_DATA* val );
BOOL WriteVALUE2(WORD ver, EPGDB_CONTENT_DATA* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, EPGDB_CONTENT_DATA* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<EPGDB_CONTENT_DATA>* val );
BOOL WriteVALUE2(WORD ver, vector<EPGDB_CONTENT_DATA>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<EPGDB_CONTENT_DATA>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, EPGDB_SEARCH_DATE_INFO* val );
BOOL WriteVALUE2(WORD ver, EPGDB_SEARCH_DATE_INFO* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, EPGDB_SEARCH_DATE_INFO* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<EPGDB_SEARCH_DATE_INFO>* val );
BOOL WriteVALUE2(WORD ver, vector<EPGDB_SEARCH_DATE_INFO>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<EPGDB_SEARCH_DATE_INFO>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, EPGDB_SEARCH_KEY_INFO* val );
BOOL WriteVALUE2(WORD ver, EPGDB_SEARCH_KEY_INFO* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, EPGDB_SEARCH_KEY_INFO* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, EPG_AUTO_ADD_DATA* val );
BOOL WriteVALUE2(WORD ver, EPG_AUTO_ADD_DATA* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, EPG_AUTO_ADD_DATA* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<EPG_AUTO_ADD_DATA>* val );
BOOL WriteVALUE2(WORD ver, vector<EPG_AUTO_ADD_DATA>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<EPG_AUTO_ADD_DATA>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, MANUAL_AUTO_ADD_DATA* val );
BOOL WriteVALUE2(WORD ver, MANUAL_AUTO_ADD_DATA* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, MANUAL_AUTO_ADD_DATA* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<MANUAL_AUTO_ADD_DATA>* val );
BOOL WriteVALUE2(WORD ver, vector<MANUAL_AUTO_ADD_DATA>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<MANUAL_AUTO_ADD_DATA>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, REC_FILE_INFO* val );
BOOL WriteVALUE2(WORD ver, REC_FILE_INFO* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, REC_FILE_INFO* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

DWORD GetVALUESize2(WORD ver, vector<REC_FILE_INFO>* val );
BOOL WriteVALUE2(WORD ver, vector<REC_FILE_INFO>* val, BYTE* buff, DWORD buffSize, DWORD* writeSize );
BOOL ReadVALUE2(WORD ver, vector<REC_FILE_INFO>* val, BYTE* buff, DWORD buffSize, DWORD* readSize );

#endif
