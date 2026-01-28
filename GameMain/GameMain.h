
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

	//@brief	---  ゲーム開始関数  ---
	void EntryGame();
private://------  関数  ------

	//@brief	---  初期化関数  ---
	[[nodiscard]] bool Initialization(const int Value_ = 13)noexcept;

	//@brief	---  シャッフル関数  ---
	void Shuffle(std::vector<std::pair<int, CradSet::Suit>>& V)noexcept;

	//@brief	---  表示関数  ---
	void Show(const bool Debug = false)noexcept;

	//@brief	---  ドロー関数  ---
	void Drow(std::vector<std::pair<int, CradSet::Suit>>& Deck_)noexcept;

	//@brief	---  ランダム関数  ---
	[[nodiscard]] std::pair<int, CradSet::Suit> RamdomDrow(std::vector<std::pair<int, CradSet::Suit>>& V)noexcept;

	//@brief	---  プレイヤー入力関数  ---
	[[nodiscard]] CradSet::Input PlayerInput()noexcept;

	//@brief	---  CIN例外処理関数  ---
	void ThrowCIN(int num) {
		if (num < 0 || num >= 3) {
			throw "Plese check Input value";
		}
	}
	void ThrowCIN(std::pair<int,int> value) {
		if (value.first < 0 || value.first >= Field_.size()) {
			throw "Plese check Input value(first)";
		}
		if (value.second <= 0 || value.second >= SetSort_.size()) {
			throw "Plese check Input value(second)";
		}
		if (value.first == value.second) {
			throw "Same value.";
		}
	}
	
	//@brief	---  カードセレクト関数  ---
	[[nodiscard]] std::pair<int, int> Cardselection()noexcept;

	//@brief	---  カード移動関数  ---
	void CradMove(std::pair<int, int> value)noexcept;
	
private://------  変数  ------
	std::vector<std::vector<std::pair<int, CradSet::Suit>>>	AllCrad_;	//全カード
	std::vector<std::pair<int, CradSet::Suit>>				Deck_;		//デッキ
	std::vector<std::vector<std::pair<int, CradSet::Suit>>> Field_;		//フィールド
	std::vector<std::vector<std::pair<int, CradSet::Suit>>> SetSort_;	//置き場
	std::pair<int, CradSet::Suit>							DeckFirst_;
};