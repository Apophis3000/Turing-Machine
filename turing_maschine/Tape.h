#ifndef _Tape_h
#define _Tape_h

#include<string>
#include<vector>
#include "Direction.h"

class Tape
{
private:
	int headPosition;
	std::string tape;
	std::string alphabet;
public:
	Tape(std::string word, std::string alphabet);
	void WriteChar(char);
	char ReadChar();
	std::string GetTape();
	void MoveHead(Direction);
};

#endif