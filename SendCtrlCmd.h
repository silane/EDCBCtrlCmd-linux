#pragma once

#include <mutex>
#include "Util.h"
#include "StructDef.h"

#include "CtrlCmdDef.h"

class CSendCtrlCmd
{
public:
	CSendCtrlCmd(void);
	~CSendCtrlCmd(void);

	//TCP/IPモード時の接続先を設定
	//引数：
	// ip			[IN]接続先IP
	// port			[IN]接続先ポート
	void SetNWSetting(
		wstring ip,
		DWORD port
		);

	//接続処理時のタイムアウト設定
	// timeOut		[IN]タイムアウト値（単位：ms）
	void SetConnectTimeOut(
		DWORD timeOut
		);

	//Program.txtを追加で再読み込みする
	//戻り値：
	// エラーコード
	DWORD SendAddloadReserve() const;

	//EPGデータを再読み込みする
	//戻り値：
	// エラーコード
	DWORD SendReloadEpg() const;

	//設定情報を再読み込みする
	//戻り値：
	// エラーコード
	DWORD SendReloadSetting() const;

	//EpgTimerSrv.exeを終了する
	//戻り値：
	// エラーコード
	DWORD SendClose() const;

	//EpgTimerSrv.exeのパイプ接続GUIとしてプロセスを登録する
	//戻り値：
	// エラーコード
	//引数：
	// processID			[IN]プロセスID
	DWORD SendRegistGUI(DWORD processID) const;

	//EpgTimerSrv.exeのパイプ接続GUI登録を解除する
	//戻り値：
	// エラーコード
	//引数：
	// processID			[IN]プロセスID
	DWORD SendUnRegistGUI(DWORD processID) const;
	
	//EpgTimerSrv.exeのTCP接続GUIとしてプロセスを登録する
	//戻り値：
	// エラーコード
	//引数：
	// port					[IN]ポート
	DWORD SendRegistTCP(DWORD port) const;

	//EpgTimerSrv.exeのTCP接続GUI登録を解除する
	//戻り値：
	// エラーコード
	//引数：
	// port					[IN]ポート
	DWORD SendUnRegistTCP(DWORD port) const;

	//予約一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]予約一覧
	DWORD SendEnumReserve(
		vector<RESERVE_DATA>* val
		) const;

	//予約情報を取得する
	//戻り値：
	// エラーコード
	//引数：
	// reserveID		[IN]取得する情報の予約ID
	// val				[OUT]予約情報
	DWORD SendGetReserve(DWORD reserveID, RESERVE_DATA* val) const;

	//予約を追加する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]追加する予約一覧
	DWORD SendAddReserve(vector<RESERVE_DATA>* val) const;

	//予約を削除する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]削除する予約ID一覧
	DWORD SendDelReserve(vector<DWORD>* val) const;

	//予約を変更する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]変更する予約一覧
	DWORD SendChgReserve(vector<RESERVE_DATA>* val) const;

	//チューナーごとの予約一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]予約一覧
	DWORD SendEnumTunerReserve(vector<TUNER_RESERVE_INFO>* val) const;

	//録画済み情報一覧取得
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]録画済み情報一覧
	DWORD SendEnumRecInfo(
		vector<REC_FILE_INFO>* val
		) const;
	
	//録画済み情報を削除する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]削除するID一覧
	DWORD SendDelRecInfo(vector<DWORD>* val) const;

	//サービス一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val				[OUT]サービス一覧
	DWORD SendEnumService(
		vector<EPGDB_SERVICE_INFO>* val
		) const;

	//サービス指定で番組情報を一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// service			[IN]ONID<<32 | TSID<<16 | SIDとしたサービスID
	// val				[OUT]番組情報一覧
	DWORD SendEnumPgInfo(
		ULONGLONG service,
		vector<EPGDB_EVENT_INFO*>* val
		) const;

	//指定イベントの番組情報を取得する
	//戻り値：
	// エラーコード
	//引数：
	// pgID				[IN]ONID<<48 | TSID<<32 | SID<<16 | EventIDとしたID
	// val				[OUT]番組情報
	DWORD SendGetPgInfo(
		ULONGLONG pgID,
		EPGDB_EVENT_INFO* val
		) const;

	//指定キーワードで番組情報を検索する
	//戻り値：
	// エラーコード
	//引数：
	// key				[IN]検索キー（複数指定時はまとめて検索結果が返る）
	// val				[OUT]番組情報一覧
	DWORD SendSearchPg(
		vector<EPGDB_SEARCH_KEY_INFO>* key,
		vector<EPGDB_EVENT_INFO*>* val
		) const;

	//番組情報一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val				[OUT]番組情報一覧
	DWORD SendEnumPgAll(
		vector<EPGDB_SERVICE_EVENT_INFO*>* val
		) const;

	//自動予約登録条件一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]条件一覧
	DWORD SendEnumEpgAutoAdd(
		vector<EPG_AUTO_ADD_DATA>* val
		) const;

	//自動予約登録条件を追加する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendAddEpgAutoAdd(
		vector<EPG_AUTO_ADD_DATA>* val
		) const;

	//自動予約登録条件を削除する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendDelEpgAutoAdd(
		vector<DWORD>* val
		) const;

	//自動予約登録条件を変更する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendChgEpgAutoAdd(
		vector<EPG_AUTO_ADD_DATA>* val
		) const;

	//自動予約登録条件一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]条件一覧	
	DWORD SendEnumManualAdd(
		vector<MANUAL_AUTO_ADD_DATA>* val
		) const;

	//自動予約登録条件を追加する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendAddManualAdd(
		vector<MANUAL_AUTO_ADD_DATA>* val
		) const;

	//プログラム予約自動登録の条件削除
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendDelManualAdd(
		vector<DWORD>* val
		) const;

	//プログラム予約自動登録の条件変更
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendChgManualAdd(
		vector<MANUAL_AUTO_ADD_DATA>* val
		) const;


	DWORD SendChkSuspend() const;

	DWORD SendSuspend(
		WORD val
		) const;

	DWORD SendReboot() const;

	DWORD SendEpgCapNow() const;

	//指定ファイルを転送する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]ファイル名
	// resVal		[OUT]ファイルのバイナリデータ
	// resValSize	[OUT]resValのサイズ
	DWORD SendFileCopy(
		wstring val,
		BYTE** resVal,
		DWORD* resValSize
		) const;

	//PlugInファイルの一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]1:ReName、2:Write
	// resVal		[OUT]ファイル名一覧
	DWORD SendEnumPlugIn(
		WORD val,
		vector<wstring>* resVal
		) const;

	//TVTestのチャンネル切り替え用の情報を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]ONID<<32 | TSID<<16 | SIDとしたサービスID
	// resVal		[OUT]チャンネル情報
	DWORD SendGetChgChTVTest(
		ULONGLONG val,
		TVTEST_CH_CHG_INFO* resVal
		) const;

	//ネットワークモードのEpgDataCap_Bonのチャンネルを切り替え
	//戻り値：
	// エラーコード
	//引数：
	// chInfo				[OUT]チャンネル情報
	DWORD SendNwTVSetCh(
		SET_CH_INFO* val
		) const;

	//ネットワークモードで起動中のEpgDataCap_Bonを終了
	//戻り値：
	// エラーコード
	//引数：
	// chInfo				[OUT]チャンネル情報
	DWORD SendNwTVClose(
		) const;

	//ネットワークモードで起動するときのモード
	//戻り値：
	// エラーコード
	//引数：
	// val				[OUT]モード（1:UDP 2:TCP 3:UDP+TCP）
	DWORD SendNwTVMode(
		DWORD val
		) const;

	//ストリーム配信用ファイルを開く
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]開くファイルのサーバー側ファイルパス
	// resVal			[OUT]制御用CtrlID
	DWORD SendNwPlayOpen(
		wstring val,
		DWORD* resVal
		) const;

	//ストリーム配信用ファイルを閉じる
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]制御用CtrlID
	DWORD SendNwPlayClose(
		DWORD val
		) const;

	//ストリーム配信開始
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]制御用CtrlID
	DWORD SendNwPlayStart(
		DWORD val
		) const;

	//ストリーム配信停止
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]制御用CtrlID
	DWORD SendNwPlayStop(
		DWORD val
		) const;

	//ストリーム配信で現在の送信位置と総ファイルサイズを取得する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN/OUT]サイズ情報
	DWORD SendNwPlayGetPos(
		NWPLAY_POS_CMD* val
		) const;

	//ストリーム配信で送信位置をシークする
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]サイズ情報
	DWORD SendNwPlaySetPos(
		NWPLAY_POS_CMD* val
		) const;

	//ストリーム配信で送信先を設定する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]サイズ情報
	DWORD SendNwPlaySetIP(
		NWPLAY_PLAY_INFO* val
		) const;

	//ストリーム配信用ファイルをタイムシフトモードで開く
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]予約ID
	// resVal			[OUT]ファイルパスとCtrlID
	DWORD SendNwTimeShiftOpen(
		DWORD val,
		NWPLAY_TIMESHIFT_INFO* resVal
		) const;

//コマンドバージョン対応版
	//予約一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]予約一覧
	DWORD SendEnumReserve2(
		vector<RESERVE_DATA>* val
		) const;

	//予約情報を取得する
	//戻り値：
	// エラーコード
	//引数：
	// reserveID		[IN]取得する情報の予約ID
	// val				[OUT]予約情報
	DWORD SendGetReserve2(DWORD reserveID, RESERVE_DATA* val) const;

	//予約を追加する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]追加する予約一覧
	DWORD SendAddReserve2(vector<RESERVE_DATA>* val) const;

	//予約を変更する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]変更する予約一覧
	DWORD SendChgReserve2(vector<RESERVE_DATA>* val) const;

	//予約追加が可能か確認する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]予約情報
	// resVal			[OUT]追加可能かのステータス
	DWORD SendAddChkReserve2(RESERVE_DATA* val, WORD* resVal) const;


	//EPGデータファイルのタイムスタンプ取得
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]取得ファイル名
	// resVal			[OUT]タイムスタンプ
	DWORD SendGetEpgFileTime2(wstring val, LONGLONG* resVal) const;

	//EPGデータファイル取得
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]ファイル名
	// resVal		[OUT]ファイルのバイナリデータ
	// resValSize	[OUT]resValのサイズ
	DWORD SendGetEpgFile2(
		wstring val,
		BYTE** resVal,
		DWORD* resValSize
		) const;

	//自動予約登録条件一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]条件一覧
	DWORD SendEnumEpgAutoAdd2(
		vector<EPG_AUTO_ADD_DATA>* val
		) const;

	//自動予約登録条件を追加する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendAddEpgAutoAdd2(
		vector<EPG_AUTO_ADD_DATA>* val
		) const;

	//自動予約登録条件を変更する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendChgEpgAutoAdd2(
		vector<EPG_AUTO_ADD_DATA>* val
		) const;

	//自動予約登録条件一覧を取得する
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]条件一覧	
	DWORD SendEnumManualAdd2(
		vector<MANUAL_AUTO_ADD_DATA>* val
		) const;

	//自動予約登録条件を追加する
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendAddManualAdd2(
		vector<MANUAL_AUTO_ADD_DATA>* val
		) const;

	//プログラム予約自動登録の条件変更
	//戻り値：
	// エラーコード
	//引数：
	// val			[IN]条件一覧
	DWORD SendChgManualAdd2(
		vector<MANUAL_AUTO_ADD_DATA>* val
		) const;

	//録画済み情報一覧取得
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]録画済み情報一覧
	DWORD SendEnumRecInfo2(
		vector<REC_FILE_INFO>* val
		) const;

	//録画済み情報一覧取得
	//戻り値：
	// エラーコード
	//引数：
	// val			[OUT]録画済み情報一覧
	DWORD SendChgProtectRecInfo2(
		vector<REC_FILE_INFO>* val
		) const;

//タイマーGUI（EpgTimer_Bon.exe）用

	//ダイアログを前面に表示
	//戻り値：
	// エラーコード
	DWORD SendGUIShowDlg(
		) const;

	//予約一覧の情報が更新された
	//戻り値：
	// エラーコード
	DWORD SendGUIUpdateReserve(
		) const;

	//EPGデータの再読み込みが完了した
	//戻り値：
	// エラーコード
	DWORD SendGUIUpdateEpgData(
		) const;

	//情報更新を通知する
	//戻り値：
	// エラーコード
	//引数：
	// val				[IN]通知情報
	DWORD SendGUINotifyInfo2(NOTIFY_SRV_INFO* val) const;

//Viewアプリ（EpgDataCap_Bon.exe）を起動
	//戻り値：
	// エラーコード
	//引数：
	// exeCmd			[IN]コマンドライン
	// PID				[OUT]起動したexeのPID
	DWORD SendGUIExecute(
		wstring exeCmd,
		DWORD* PID
		) const;

	//スタンバイ、休止、シャットダウンに入っていいかの確認をユーザーに行う
	//戻り値：
	// エラーコード
	DWORD SendGUIQuerySuspend(
		BYTE rebootFlag,
		BYTE suspendMode
		) const;

	//PC再起動に入っていいかの確認をユーザーに行う
	//戻り値：
	// エラーコード
	DWORD SendGUIQueryReboot(
		BYTE rebootFlag
		) const;

	//サーバーのステータス変更通知
	//戻り値：
	// エラーコード
	//引数：
	// status			[IN]ステータス
	DWORD SendGUIStatusChg(
		WORD status
		) const;


//Viewアプリ（EpgDataCap_Bon.exe）用

	//BonDriverの切り替え
	//戻り値：
	// エラーコード
	//引数：
	// bonDriver			[IN]BonDriverファイル名
	DWORD SendViewSetBonDrivere(
		wstring bonDriver
		) const;

	//使用中のBonDriverのファイル名を取得
	//戻り値：
	// エラーコード
	//引数：
	// bonDriver			[OUT]BonDriverファイル名
	DWORD SendViewGetBonDrivere(
		wstring* bonDriver
		) const;

	//チャンネル切り替え
	//戻り値：
	// エラーコード
	//引数：
	// chInfo				[OUT]チャンネル情報
	DWORD SendViewSetCh(
		SET_CH_INFO* chInfo
		) const;

	//放送波の時間とPC時間の誤差取得
	//戻り値：
	// エラーコード
	//引数：
	// delaySec				[OUT]誤差（秒）
	DWORD SendViewGetDelay(
		int* delaySec
		) const;

	//現在の状態を取得
	//戻り値：
	// エラーコード
	//引数：
	// status				[OUT]状態
	DWORD SendViewGetStatus(
		DWORD* status
		) const;

	//現在の状態を取得
	//戻り値：
	// エラーコード
	DWORD SendViewAppClose(
		) const;

	//識別用IDの設定
	//戻り値：
	// エラーコード
	//引数：
	// id				[IN]ID
	DWORD SendViewSetID(
		int id
		) const;

	//識別用IDの取得
	//戻り値：
	// エラーコード
	//引数：
	// id				[OUT]ID
	DWORD SendViewGetID(
		int* id
		) const;

	//予約録画用にGUIキープ
	//戻り値：
	// エラーコード
	DWORD SendViewSetStandbyRec(
		DWORD keepFlag
		) const;

	//ストリーム制御用コントロール作成
	//戻り値：
	// エラーコード
	//引数：
	// ctrlID				[OUT]制御ID
	DWORD SendViewCreateCtrl(
		DWORD* ctrlID
		) const;

	//ストリーム制御用コントロール削除
	//戻り値：
	// エラーコード
	//引数：
	// ctrlID				[IN]制御ID
	DWORD SendViewDeleteCtrl(
		DWORD ctrlID
		) const;

	//制御コントロールの設定
	//戻り値：
	// エラーコード
	//引数：
	// val					[IN]設定値
	DWORD SendViewSetCtrlMode(
		SET_CTRL_MODE val
		) const;

	//録画処理開始
	//戻り値：
	// エラーコード
	//引数：
	// val					[IN]設定値
	DWORD SendViewStartRec(
		SET_CTRL_REC_PARAM val
		) const;

	//録画処理開始
	//戻り値：
	// エラーコード
	//引数：
	// val					[IN]設定値
	// resVal				[OUT]ドロップ数
	DWORD SendViewStopRec(
		SET_CTRL_REC_STOP_PARAM val,
		SET_CTRL_REC_STOP_RES_PARAM* resVal
		) const;

	//録画中のファイルパスを取得
	//戻り値：
	// エラーコード
	//引数：
	// val					[OUT]ファイルパス
	DWORD SendViewGetRecFilePath(
		DWORD ctrlID,
		wstring* resVal
		) const;

	//録画処理開始
	//戻り値：
	// エラーコード
	DWORD SendViewStopRecAll(
		) const;

	//ファイル出力したサイズを取得
	//戻り値：
	// エラーコード
	//引数：
	// resVal					[OUT]ファイル出力したサイズ
	DWORD SendViewGetWriteSize(
		DWORD ctrlID,
		__int64* resVal
		) const;

	//EPG取得開始
	//戻り値：
	// エラーコード
	//引数：
	// val					[IN]取得チャンネルリスト
	DWORD SendViewEpgCapStart(
		vector<SET_CH_INFO>* val
		) const;

	//EPG取得キャンセル
	//戻り値：
	// エラーコード
	DWORD SendViewEpgCapStop(
		) const;

	//EPGデータの検索
	//戻り値：
	// エラーコード
	// val					[IN]取得番組
	// resVal				[OUT]番組情報
	DWORD SendViewSearchEvent(
		SEARCH_EPG_INFO_PARAM* val,
		EPGDB_EVENT_INFO* resVal
		) const;

	//現在or次の番組情報を取得する
	//戻り値：
	// エラーコード
	// val					[IN]取得番組
	// resVal				[OUT]番組情報
	DWORD SendViewGetEventPF(
		GET_EPG_PF_INFO_PARAM* val,
		EPGDB_EVENT_INFO* resVal
		) const;

	//Viewボタン登録アプリ起動
	//戻り値：
	// エラーコード
	DWORD SendViewExecViewApp(
		) const;

//TVTest連携のストリーミング配信専用
	//ストリーミング配信制御IDの設定
	//戻り値：
	// エラーコード
	DWORD SendViewSetStreamingInfo(
		TVTEST_STREAMING_INFO* val
		) const;

protected:
	mutable std::mutex mutex;

	DWORD connectTimeOut;
	wstring ip;
	DWORD port;

protected:
	//PublicAPI排他制御用
	BOOL Lock(LPCWSTR log = NULL, DWORD timeOut = 60*1000) const;
	void UnLock(LPCWSTR log = NULL) const;

	DWORD SendTCP(wstring ip, DWORD port, DWORD timeOut, CMD_STREAM* sendCmd, CMD_STREAM* resCmd) const;
};
