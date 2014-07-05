#include "Tape.h"

using std::string;

Tape::Tape(string word, string alphabet)
{
	this->alphabet = alphabet + "$#";
	headPosition = 0;
	tape.push_back('$');

	for (int i = 0; i < (int)word.size(); i++)
	{
		if (this->alphabet.find(word[i]) == string::npos)
			return;
		tape.push_back(word[i]);
	}
	tape.push_back('#');
}

char Tape::ReadChar()
{	
	return tape[headPosition];
}

void Tape::WriteChar(char ch)
{
	if ((headPosition < 0) || (alphabet.find(ch) == string::npos))
		return;
	tape[headPosition] = ch;
}

string Tape::GetTape()
{
	return tape;
}

void Tape::MoveHead(Direction direction)
{
	switch (direction)
	{
		case Right: headPosition++;
			break;
		case Left: headPosition--;
			break;
		default:
			break;
	}

	if (headPosition > (int)tape.size()-1)
		tape.push_back('#');
	if (headPosition < 0)
		headPosition = 0;
}