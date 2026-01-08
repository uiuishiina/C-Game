
//------  GameMain.h  /・・ゲームメインクラスソースファイル・・/  ------

#pragma once

//------  参照  ------
#include"GameMain.h"


//@brief	---  ゲームループ関数  /・・ゲーム開始した後終了するまでループする関数・・/  ---
[[nodiscard]] BombGame::Result Game :: GameLoop()noexcept 
{

}

//@brief	---  ゲーム制御関数  /・・入力や判定など1回のループ内での処理を書く関数・・/  ---
[[nodiscard]] bool Game :: GameJudgement()noexcept 
{

}

//@brief	---  フィールド作成関数  /・・ゲームフィールドを任意のサイズで作成する関数・・/  ---
[[nodiscard]] bool Game :: CreateField(const int size = BombGame::FieldSize)noexcept {

	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
		}
	}
}

//@brief	---  フィールド表示関数  ---
void Game :: ShowField()noexcept {

}

//@brief	---  プレイヤー入力受付関数  /・・入力待機した後入力された値を返す関数・・/  ---
[[nodiscaard]] BombGame::InputArrow Game :: InputPlayer()noexcept {

}

//@brief	---  リザルト関数  /・・ゲーム終了処理関数・・/  ---
void Game :: Result(BombGame::Result result)noexcept {

}