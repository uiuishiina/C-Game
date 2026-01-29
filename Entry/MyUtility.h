
//------  Utility.h  /・・名前空間 & IncludeFile宣言・・/  ------

#pragma once
#include<iostream>
#include <iomanip>
#include<vector>
#include<random>
#include<time.h>
#include<cassert>

namespace CradSet {
	//@brief	---  スート  ---
	enum Suit {
		Spade, Heart, Diamond, Club
	};
	//@brief	---  入力  ---
	enum Input {
		END = -1, Draw = 1, Move,
	};
}