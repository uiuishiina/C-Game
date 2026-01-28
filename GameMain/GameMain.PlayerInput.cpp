//------  GameMain.PlayerINput.h  /・・ゲームメイン入力関数ファイル・・/  ------

#pragma once

//------  参照  ------
#include"GameMain.h"

//@brief	---  プレイヤー入力関数  ---
[[nodiscard]] CradSet::Input Game::PlayerInput()noexcept {
	int Doing_;
	//動作指定箇所
	while (true) {
		std::cout << "\n動作を指定　１= デッキドロー ,2 = カード移動 ,000 = 終了" << std::endl;
		//例外がないか
		try {
			std::cin >> Doing_;
		}
		catch (...) {
			std::cout << "数値以外が入力されました" << std::endl;
			std::cin.clear();
			std::cin.seekg(0);
			continue;
		}
		//例外処理
		try {
			ThrowCIN(Doing_);
		}
		catch (const char* pLog) {
			std::cin.clear();
			std::cin.seekg(0);
			continue;
		}
		break;
	}

	return (CradSet::Input)Doing_;
}
//@brief	---  カードセレクト関数  ---
[[nodiscard]] std::pair<int, int> Game :: Cardselection()noexcept {
	int F, S;
	std::pair<int, int> value = {};
	//セレクト
	while (true) {
		std::cout << "\n移動するカードを指定" << std::endl;
		//カード指定箇所
		while (true) {
			std::cout << "\nどのカードを移動しますか	0 = デッキ ,1～7 = フィールド番号" << std::endl;
			//例外がないか
			try {
				std::cin >> F;
			}
			catch (...) {
				std::cout << "数値以外が入力されました" << std::endl;
				std::cin.clear();
				std::cin.seekg(0);
				continue;
			}
			break;
		}
		//移動場所指定箇所
		while (true) {
			std::cout << "\nどこに移動しますか	1～４ = 置き場" << std::endl;
			//例外がないか
			try {
				std::cin >> S;
			}
			catch (...) {
				std::cout << "数値以外が入力されました" << std::endl;
				std::cin.clear();
				std::cin.seekg(0);
				continue;
			}
			break;
		}
		value = { F,S };
		//例外処理
		try {
			ThrowCIN(value);
		}
		catch (const char* pLog) {
			std::cin.clear();
			std::cin.seekg(0);
			continue;
		}
		break;
	}
	
	return value;
}

//@brief	---  カード移動関数  ---
//@param	移動する情報
void Game :: CradMove(std::pair<int, int> value)noexcept {

	if (Field_.size() < value.first) {
		std::cout << "value.first";
		return;
	}
	if (value.second == 0) {
		std::cout << "value.second";
		return;
	}
	//チェック
	{
		std::pair<int, CradSet::Suit> v;
		if (value.first == 0) {
			v = Deck_.front();
		}
		else {
			v = Field_.at(value.first - 1).back();
		}
		//色チェック
		if ((SetSort_.at(value.second - 1).back().second & 1) == (v.second & 1)) {
			std::cout << "------  ガードの色が同じです  ------\n";
			return;
		}
		//数字チェック
		if ((SetSort_.at(value.second - 1).back().first + 1) != v.first) {
			std::cout << "------  カードの数字がルールに違反しています  ------\n";
			return;
		}
	}
	//移動
	{
		std::pair<int, CradSet::Suit> pair_;
		if (value.first == 0) {
			pair_ = Deck_.front();
			Deck_.pop_back();
		}
		else {
			pair_ = Field_.at(value.first - 1).back();
			Field_.at(value.first - 1).pop_back();
		}
		SetSort_.at(value.second - 1).push_back(pair_);
	}
}