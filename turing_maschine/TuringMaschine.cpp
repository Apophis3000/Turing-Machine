#include "TuringMaschine.h"

using std::vector;
using std::string;

TuringMaschine::TuringMaschine(vector<Estate>* estates, vector<Transition>* transitions, std::vector<Tape>* tapes)
{
	this->estates = estates;
	this->transitions = transitions;

	tapeList = tapes;

	for (int i = 0; i < (int)estates->size(); i++)
	{
		if ((*estates)[i].GetType() == Start)
			curr_Estate = new Estate((*estates)[i]);
	}
}

void TuringMaschine::Calculate()
{
	while (curr_Estate->GetType() != Final)
	{
		for (int x = 0; x < (int)tapeList->size(); x++)
		{
			Tape* curr_tape = &tapeList->at(x);

			for (int i = 0; i < (int)estates->size(); i++)
			{			
				if ((curr_Estate->GetId()) == (*estates)[i].GetId())
					*curr_Estate = (*estates)[i];

				for (int j = 0; j < (int)transitions->size(); j++)
				{					
					char curr_char = curr_tape->ReadChar();
					curr_Transition = new Transition((*transitions)[j]);
					if ((curr_Estate->GetId() == curr_Transition->curr_Estate->GetId()) && (curr_char == curr_Transition->curr_Char))
					{
						curr_Estate = curr_Transition->new_Estate;
						curr_tape->WriteChar(curr_Transition->new_Char);

						curr_tape->MoveHead(curr_Transition->direction);
					}
				}
			}
		}
	}
}

string TuringMaschine::GetTape(int tapeNumber)
{
	return tapeList->at(tapeNumber).GetTape();
}