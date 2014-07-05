#ifndef _Turing_Maschine_h
#define _Turing_Maschine_h

#include<vector>
#include<algorithm>
#include "Estate.h"
#include "Tape.h"

struct Transition
{
	Estate* curr_Estate;
	char curr_Char;
	Estate* new_Estate;
	char new_Char;
	Direction direction;
	
	Transition(Estate* curr_Estate, char curr_Char, Estate* new_Estate, char new_Char, Direction direction)
	{
		this->curr_Estate = curr_Estate;
		this->curr_Char = curr_Char;
		this->new_Estate = new_Estate;
		this->new_Char = new_Char;
		this->direction = direction;
	}
};

class TuringMaschine
{
private:
	std::vector<Estate>* estates;
	std::vector<Transition>* transitions;
	std::vector<Tape>* tapeList;

	Estate* curr_Estate;
	Transition* curr_Transition;
public:
	TuringMaschine(std::vector<Estate>*, std::vector<Transition>*, std::vector<Tape>*);
	void Calculate();
	std::string GetTape(int tapeNumber);
};

#endif