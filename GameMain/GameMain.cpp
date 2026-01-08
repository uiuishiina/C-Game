
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
		if (GameJudgement(Input)) {
			
		}
	}
}

//@brief	---  判定処理関数  /・・判定処理を書く関数・・/  ---
//@param	input	入力値
[[nodiscard]] BombGame::Judge Game::GameJudgement(BombGame::InputArrow const input)noexcept
{


	return BombGame::Live;
}

//@brief	---  フィールド作成関数  /・・ゲームフィールドを任意のサイズで作成する関数・・/  ---
//@param	size	フィールド幅 Default = BombGame::FieldSize
//@param	Bomb	爆弾の数	Default = BombGame::BombCount
[[nodiscard]] bool Game :: CreateField(const int size,const int Bomb)noexcept {
	
	//フィールド配列初期化
	Field_.clear();
	Field_.resize(size * size);
	std::fill(Field_.begin(), Field_.end(), std::pair<bool, bool>(false, false));

	//重複を避けるため配列から数値を取得
	std::vector<int> v = {};
	for (int i = 1; i < (size * size) - 1; i++) { v.push_back(i); }
	auto v_t = (int)v.size();

	for (int i = 0; i < Bomb; i++) {
		if (v_t == 0) { break; }
		Field_.at(RandomInt(&v_t, v)).second = true;
	}

	//フィールドサイズ設定
	Fieldsize_ = size;
	return true;
}

//@brief	---  フィールド表示関数  ---
void Game :: ShowField(bool Debug) noexcept {

	//サイズ確認
	assert(Fieldsize_ != 0 && "フィールドサイズ0");

	//表示
	for (int i = 1; i < Fieldsize_ * Fieldsize_; i++) {
		std::cout << " ";

		if (PlayerPos_ == i) {
			std::cout << "@";
		}
		else {
			//スタート位置
			if (i == 1) {
				std::cout << "S";	continue;
			}
			//Debug ON OFF
			switch (Debug)
			{
			case true:	//Debug ON
				if (Field_.at(i).second) {
					std::cout << "+";
				}
				else {
					std::cout << "-";
				}
				break;
			case false://Debug OFF
				if (Field_.at(i).first) {
					std::cout << "*";
				}
				else {
					std::cout << "-";
				}
				break;
			}
		}

		//改行
		if (i != 1 && i % Fieldsize_ == 0) { 
			std::cout << std::endl; }
	}
	std::cout << " G";
}

//@brief	---  プレイヤー入力受付関数  /・・入力待機した後入力された値を返す関数・・/  ---
[[nodiscaard]] BombGame::InputArrow Game::InputPlayer()noexcept {
	
	//
	BombGame::InputArrow Input;
	

	return BombGame::Up;
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