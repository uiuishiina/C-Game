
//------  Utility.h  /・・名前空間 & IncludeFile宣言・・/  ------

#pragma once

//------  参照  ------
#include<iostream>
#include<vector>	
#include<random>
#include<cassert>

//------  名前空間  ------
namespace BombGame {

	//@brief	---  フィールドサイズ変数  ---
	static int FieldSize = 6;

	//@brief	---  爆弾の数  ---
	static int BombCount = 10;

	//@brief	---  入力変数  ---
	//@param	W A S D
	enum InputArrow { Up, Left, Down, Right };

	//@brief	---  リザルト変数  ---
	//@param	Clear  HitBomb  DropField  Error
	enum Result { Clear, HitBomb, DropField, Error = -1 };

	//@brief	---  判定変数  ---
	//@param	Live  Death  Fall  Exception
	enum Judge { Live, Death, Fall, Exception = -1 };
}