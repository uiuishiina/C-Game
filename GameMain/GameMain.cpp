
//------  GameMain.h  /・・ゲームメインクラスソースファイル・・/  ------

#pragma once

//------  参照  ------
#include"GameMain.h"

//@brief	---  ゲーム開始関数  ---
void Game::EntryGame() {

	//ランダム初期化
	srand((unsigned int)time(NULL));
	//cin例外処理有効化
	std::cin.exceptions(std::ios::failbit);

	Initialization();
	Show();
}

//@brief	---  初期化関数  ---
[[nodiscard]] bool Game :: Initialization(const int Value_)noexcept {

	//リセット
	AllCrad_.clear();
	Field_.clear();
	AllCrad_.resize(4);
	Field_.resize(7);

	//全カードセット
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < Value_; j++) {
			AllCrad_.at(i).push_back(std::pair<int, CradSet::Suit>(j + 1, (CradSet::Suit)i));
		}
	}

	//フィールドセット
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < i+2; j++) {
			Field_.at(i).push_back(Drow(AllCrad_.at(rand() % 4)));
		}
	}

	return true;
}

//@brief	---  シャッフル関数  ---
void Game :: Shuffle(std::vector<std::pair<int, CradSet::Suit>>& V)noexcept {

}

//@brief	---  表示関数  ---
void Game :: Show(const bool Debug)noexcept {
	//フィールド表示
	for (auto& p : Field_) {
		for (auto& pp : p) {
			//着色
			switch ((int)pp.second & 1)
			{
			/*case CradSet::Spade:
				std::cout << "\033[1;37m";
				break;
			case CradSet::Heart:
				std::cout << "\033[1;31m";
				break;
			case CradSet::Diamond:
				std::cout << "\033[1;31m";
				break;
			case CradSet::Club:
				std::cout << "\033[1;37m";
				break;*/
			case 0:
				std::cout << "\033[1;37m";
				break;
			case 1:
				std::cout << "\033[1;31m";
				break;
			default:
				break;
			}
			std::cout << std::setw(4);
			std::cout << pp.first << "\033[m";
		}
		std::cout << "\n";
	}
}

//@brief	---  ランダムドロー関数  ---
[[nodiscard]] std::pair<int, CradSet::Suit> Game :: Drow(std::vector<std::pair<int, CradSet::Suit>>& V)noexcept {
	//長さに応じてランダムにとる
	const auto value = rand() % V.size();
	//取得して消去
	const auto v = V.at(value);
	V.erase(V.begin() + value);

	return v;
}