
//------  GameMain.h  /・・ゲームメインクラスヘッダー・・/  ------

#pragma once

//------  参照  ------
#include"../Entry/MyUtility.h"

//@brief	---  ゲームメインクラス  ---
class Game final
{
public:
	Game() = default;
	~Game() = default;

	//@brief	---  ゲーム開始関数  /・・クラス内にアクセスする関数・・/  ---
	void EntryGame() {

		//フィールド作成
		if (!CreateField()) {
			assert(false && "フィールド作成失敗");
			return;
		}

		//ループから抜けたときリザルト
		Result(GameLoop());
	};//End Game
private:
	
	//@brief	---  ゲームループ関数  /・・ゲーム開始した後終了するまでループする関数・・/  ---
	[[nodiscard]] BombGame::Result GameLoop()noexcept;

	//@brief	---  ゲーム制御関数  /・・入力や判定など1回のループ内での処理を書く関数・・/  ---
	[[nodiscard]] bool GameJudgement()noexcept;

	//@brief	---  フィールド作成関数  /・・ゲームフィールドを任意のサイズで作成する関数・・/  ---
	[[nodiscard]] bool CreateField(const int size = BombGame::FieldSize)noexcept;

	//@brief	---  フィールド表示関数  ---
	void ShowField()noexcept;

	//@brief	---  プレイヤー入力受付関数  /・・入力待機した後入力された値を返す関数・・/  ---
	[[nodiscaard]] BombGame::InputArrow InputPlayer()noexcept;

	//@brief	---  リザルト関数  /・・ゲーム終了処理関数・・/  ---
	void Result(BombGame::Result result)noexcept;

	//------  クラス変数  ------
	std::vector<std::pair<int, bool>> Field_{};	//フィールド
};