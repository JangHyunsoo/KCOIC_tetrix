#pragma once

typedef struct _tagPosition {
	int x;
	int y;
	_tagPosition(int iX, int iY) {
		x = iX;
		y = iY;
	}
	_tagPosition(struct _tagPosition& tPos) {
		x = tPos.x;
		y = tPos.y;
	}
	_tagPosition(int arrPos[2]) {
		x = arrPos[0];
		y = arrPos[1];
	}
}POSITION, *PPOSITION, POS, *PPOS;