
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

	//@brief	---  入力変数  ---
	//@param	W A S D
	enum InputArrow { Up, Left, Down, Right };

	//@brief	---  リザルト変数  ---
	//@param	Clear HitBomb DropField
	enum Result { Clear, HitBomb, DropField };
}

