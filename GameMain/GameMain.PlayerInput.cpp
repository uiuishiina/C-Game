//------  GameMain.PlayerINput.h  /・・ゲームメイン入力関数ファイル・・/  ------

#pragma once

//------  参照  ------
#include"GameMain.h"

//@brief	---  プレイヤー入力関数  ---
void Game::PlayerInput()noexcept {
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
}