
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
	Shuffle(Deck_);
	Show();

	while (1) {
		switch (PlayerInput())
		{
		case CradSet::Input::Draw:
			Drow(Deck_);
			break;
		case CradSet::Input::Move:
			CradMove(Cardselection());
			break;
		case CradSet::Input::END:
			break;
		default:
			std::cout << "れいがい";
			break;
		}
		Show();
	}

}

//@brief	---  初期化関数  ---
[[nodiscard]] bool Game :: Initialization(const int Value_)noexcept {

	//リセット
	AllCrad_.clear();
	Field_.clear();
	Deck_.clear();
	SetSort_.clear();
	AllCrad_.resize(4);
	Field_.resize(7);
	SetSort_.resize(4);
	for (int i = 0; i < 4; i++) {
		SetSort_.at(i).push_back(std::pair<int, CradSet::Suit>(0, (CradSet::Suit)i));
	}
	

	//全カードセット
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < Value_; j++) {
			AllCrad_.at(i).push_back(std::pair<int, CradSet::Suit>(j + 1, (CradSet::Suit)i));
		}
	}

	//フィールドセット
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < i+2; j++) {
			int ans;
			while (true) {
				auto a = rand() % 4;
				if (0 != AllCrad_.at(a).size()) {
					ans = a;
					break;
				}
			}
			Field_.at(i).push_back(RamdomDrow(AllCrad_.at(ans)));
		}
	}

	//残ったのはデッキへ
	for (auto& p: AllCrad_) {
		for (auto& pp : p) {
			Deck_.push_back(pp);
		}
	}
	AllCrad_.clear();

	return true;
}

//@brief	---  シャッフル関数  ---
void Game :: Shuffle(std::vector<std::pair<int, CradSet::Suit>>& V)noexcept {
	// シャッフル
	std::random_device seed_gen;
	std::uint32_t seed = seed_gen();
	std::mt19937 engine(seed);
	std::shuffle(V.begin(), V.end(), engine);
	//std::cout << "シャッフル";
}

//@brief	---  表示関数  ---
void Game :: Show(const bool Debug)noexcept {
	//フィールド表示
	for (int i = 0; i < Field_.size();i++) {
		auto& p = Field_.at(i);
		std::cout << "\nフィールド" << i + 1;
		if (p.at(0).first == 0) {
			std::cout << "なし" << "\n";
		}
		for (int i = 0; i < p.size();i++) {
			if (Debug) {
				const auto V = p.at(i);
				switch ((int)V.second & 1)
				{
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
				std::cout << V.first << "\033[m";
				continue;
			}
			if (i+1 != p.size()) {
				std::cout << std::setw(4);
				std::cout << "*";
				continue;
			}
			const auto V = p.at(i);
			//着色
			switch ((int)V.second & 1)
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
			std::cout << V.first << "\033[m";
		}
		std::cout << "\n";
	}
	//デッキの上表示
	std::cout << "\nデッキ\n";
	if ((int)Deck_.front().second & 1) {
		std::cout << "\033[1;37m";
	}
	else {
		std::cout << "\033[1;31m";
	}
	std::cout << std::setw(4) << Deck_.at(0).first << "\033[m";

	//セットフィールド
	for (int i = 0; i < SetSort_.size(); i++) {
		std::cout << "\nセットフィールド" << i + 1 << "\n";
		switch ((int)SetSort_.at(i).back().second & 1)
		{
		case 0:
			std::cout << "\033[1;37m";
			break;
		case 1:
			std::cout << "\033[1;31m";
			break;
		default:
			break;
		}
		std::cout << std::setw(4) << SetSort_.at(i).back().first << "\033[m";
	}
}

//@brief	---  ドロー関数  ---
void Game :: Drow(std::vector<std::pair<int, CradSet::Suit>>& Deck_)noexcept {
	
	auto v = Deck_.at(0);
	Deck_.erase(Deck_.begin());
	Deck_.push_back(v);
	if (DeckFirst_.first == 0) {
		DeckFirst_ = v;
	}
	else if(DeckFirst_ == v) {
		Shuffle(Deck_);
		DeckFirst_ = Deck_.back();
	}
}

//@brief	---  ランダム関数  ---
[[nodiscard]] std::pair<int, CradSet::Suit> Game :: RamdomDrow(std::vector<std::pair<int, CradSet::Suit>>& V)noexcept {
	//長さに応じてランダムにとる
	const auto value = rand() % V.size();
	//取得して消去
	auto v = V.at(value);
	V.erase(V.begin() + value);

	return v;
}