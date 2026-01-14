
//------  GameMain.h  /・・ゲームメインクラスソースファイル・・/  ------

#pragma once

//------  参照  ------
#include"GameMain.h"


//@brief	---  ゲームループ関数  /・・ゲーム開始した後終了するまでループする関数・・/  ---
[[nodiscard]] BombGame::Result Game :: GameLoop()noexcept 
{
	while (1) {
		//入力処理
		const auto Input = InputPlayer();
		//判定処理
		switch (GameJudgement(Input)){
		case BombGame::Live:
				break;
		case BombGame::Death:
			return BombGame::HitBomb;
				break;
		case BombGame::Fall:
			return BombGame::DropField;
		case BombGame::Goal:
			return BombGame::Clear;
				break;
		}
		ShowField();
	}
}

//@brief	---  判定処理関数  /・・判定処理を書く関数・・/  ---
//@param	input	入力値
[[nodiscard]] BombGame::Judge Game::GameJudgement(BombGame::InputArrow const input)noexcept
{
	switch (input)
	{
	case BombGame::Up:
		PlayerPos_.first -= 1;
		break;
	case BombGame::Left:
		PlayerPos_.second -= 1;
		break;
	case BombGame::Down:
		PlayerPos_.first += 1;
		break;
	case BombGame::Right:
		PlayerPos_.second += 1;
		break;
	}
	std::cout << PlayerPos_.first << " " << PlayerPos_.second << "\n";

	//落下判定
	if (PlayerPos_.first < 0 || PlayerPos_.first >= Fieldsize_) {
		return BombGame::Fall;
	}
	if (PlayerPos_.second < 0 || PlayerPos_.second >= Fieldsize_) {
		return BombGame::Fall;
	}

	//爆弾で死亡
	if (Field_.at(PlayerPos_.first).at(PlayerPos_.second).second) {
		return BombGame::Death;
	}

	//ゴール
	if (PlayerPos_.first == Fieldsize_ - 1 && PlayerPos_.second == Fieldsize_ - 1) {
		return BombGame::Goal;
	}

	return BombGame::Live;
}

//@brief	---  フィールド作成関数  /・・ゲームフィールドを任意のサイズで作成する関数・・/  ---
//@param	size	フィールド幅 Default = BombGame::FieldSize
//@param	Bomb	爆弾の数	Default = BombGame::BombCount
[[nodiscard]] bool Game :: CreateField(const int size,const int Bomb)noexcept {
	
	//フィールド配列初期化
	std::vector<std::vector<std::pair<bool, bool>>> a(size, std::vector<std::pair<bool, bool>>(size, std::pair<bool, bool>(false, false)));

	//Field_ = (size, std::vector<std::pair<bool, bool>>(size),(false,false));
	
	//重複を避けるため配列から数値を取得
	std::vector<std::vector<bool>> v(size, std::vector<bool>());
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			v.at(i).push_back(false);
		}
	}
	auto v_t1 = (int)v.size();
	auto v_t2 = (int)v.at(0).size();
	//爆弾作成
	for (int i = 0; i < Bomb; i++) {
		if (v_t1 == 0) { break; }
		auto pos = RandomInt(&v_t1, &v_t2, v);
		a.at(pos.first).at(pos.second).second = true;
	}

	Field_ = a;
	//フィールドサイズ設定
	Fieldsize_ = size;
	return true;
}

//@brief	---  フィールド表示関数  ---
void Game :: ShowField(bool Debug) noexcept {

	//サイズ確認
	assert(Fieldsize_ != 0 && "フィールドサイズ0");

	//表示
	for (int i = 0; i < Fieldsize_; i++) {
		for (int j = 0; j < Fieldsize_; j++) {
			std::cout << " ";
			if (PlayerPos_.first == i && PlayerPos_.second == j) {
				std::cout << "@";
			}
			else if (i == Fieldsize_-1 && j == Fieldsize_-1) {
				std::cout << "G";
			}
			else {
				//スタート位置
				if (i == 0 && j == 0) {
					std::cout << "S";	continue;
				}
				//Debug ON OFF
				switch (Debug)
				{
				case true:	//Debug ON
					if (Field_.at(i).at(j).second) {
						std::cout << "+";
					}
					else {
						std::cout << "-";
					}
					break;
				case false://Debug OFF
					if (Field_.at(i).at(j).first) {
						std::cout << "*";
					}
					else {
						std::cout << "-";
					}
					break;
				}
			}
		}
		std::cout << std::endl;
	}
}

//@brief	---  プレイヤー入力受付関数  /・・入力待機した後入力された値を返す関数・・/  ---
[[nodiscaard]] BombGame::InputArrow Game::InputPlayer() {

	int num = 0;
	while (true) {
		std::cout << "\nどの方向へ移動しますか?　１= 上 ,2 = 左 ,3 = 下 ,4 = 右" << std::endl;
		//例外がないか
		try {
			std::cin >> num;
		}
		catch (...) {
			std::cout << "数値以外が入力されました" << std::endl;
			std::cin.clear();
			std::cin.seekg(0);
			continue;
		}
		//列挙型の範囲か
		try {
			CheckInput(num);
		}
		catch (const char* pLog) {
			std::cout << "指定された範囲外の数値が入力されました。" << pLog << std::endl;
			std::cin.clear();
			std::cin.seekg(0);
			continue;
		}
		break;
	}
	return (BombGame::InputArrow)num;
}

//@brief	---  入力例外処理関数  /・・入力が例外ではないか調査する関数・・/  ---
void Game :: CheckInput(int num) {
	if (num > 4) { throw "入力された数値が５以上です。入力する数値は４以下にしてください"; }
	if (num < 1) { throw "入力された数値が1以下です。入力する数値は１以上の整数値にしてください"; }
	std::cout << "入力された値は" << num << " です。\n";
}

//@brief	---  リザルト関数  /・・ゲーム終了処理関数・・/  ---
void Game :: Result(BombGame::Result result)noexcept {

	//リザルトスイッチ
	switch (result)
	{
	case BombGame::Clear:
		std::cout << "ゴール";
		break;
	case BombGame::HitBomb:
		std::cout << "バーン";
		break;
	case BombGame::DropField:
		std::cout << "場外";
		break;
	default:
		assert(false && "リザルト異常");
		break;
	}
}