
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

		//ランダム初期化
		srand((unsigned)time(NULL));

		//フィールド作成
		if (!CreateField()) {
			assert(false && "フィールド作成失敗");
			return;
		}

		ShowField(true);

		//ループから抜けたときリザルト
		//Result(GameLoop());
	};//End Game

private:
	
	//@brief	---  ゲームループ関数  /・・ゲーム開始した後終了するまでループする関数・・/  ---
	[[nodiscard]] BombGame::Result GameLoop()noexcept;

	//@brief	---  判定処理関数  /・・判定処理を書く関数・・/  ---
	//@param	input	入力値
	[[nodiscard]] BombGame::Judge GameJudgement(BombGame::InputArrow const input)noexcept;

	//@brief	---  フィールド作成関数  /・・ゲームフィールドを任意のサイズで作成する関数・・/  ---
	//@param	size	フィールド幅 Default = BombGame::FieldSize
	//@param	Bomb	爆弾の数	Default = BombGame::BombCount
	[[nodiscard]] bool CreateField(const int size = BombGame::FieldSize, const int Bomb = BombGame::BombCount)noexcept;

	//@brief	---  ランダム関数  ---
	[[nodiscard]] int RandomInt(int* value,std::vector<int>& v) noexcept {
		auto a = rand() % *value;
		int x = v.at(a);
		v.erase(v.begin() + a);
		--*value;
		return x;
	}

	//@brief	---  フィールド表示関数  ---
	void ShowField(bool Debug = false)noexcept;

	//@brief	---  プレイヤー入力受付関数  /・・入力待機した後入力された値を返す関数・・/  ---
	[[nodiscard]] BombGame::InputArrow InputPlayer()noexcept;

	//@brief	---  リザルト関数  /・・ゲーム終了処理関数・・/  ---
	void Result(BombGame::Result result)noexcept;


private:
	//------  クラス変数  ------
	std::vector<std::pair<bool, bool>> Field_{};	//フィールド	@param 可視性　爆弾の可否
	int Fieldsize_ = 0;		//フィールドサイズ
	int PlayerPos_ = 1;
};