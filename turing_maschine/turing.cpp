#include<stdio.h>
#include<iostream>
#include<string>

#include "TuringMaschine.h"

using std::cout;
using std::string;
using std::vector;

void Decrement(string word)
{
	Tape* tape = new Tape(word, "01");

	Estate* s0 = new Estate("S0", Start);
	Estate* s1 = new Estate("S1", Default);
	Estate* s2 = new Estate("S2", Default);
	Estate* s3 = new Estate("S3", Default);
	Estate* s4 = new Estate("S4", Default);
	Estate* sf = new Estate("Sf", Final);

	vector<Estate>* estates = new vector<Estate>();
	estates->push_back(*s0);
	estates->push_back(*s1);
	estates->push_back(*s2);
	estates->push_back(*s3);
	estates->push_back(*s4);
	estates->push_back(*sf);

	vector<Transition>* transitions = new vector<Transition>();
	transitions->push_back(*(new Transition(s0, '$', s1, '$', Right)));
	transitions->push_back(*(new Transition(s1, '0', s1, '0', Right)));
	transitions->push_back(*(new Transition(s1, '1', s1, '1', Right)));
	transitions->push_back(*(new Transition(s1, '#', s2, '#', Left)));
	transitions->push_back(*(new Transition(s2, '0', s2, '0', Left)));
	transitions->push_back(*(new Transition(s2, '1', s3, '0', Right)));
	transitions->push_back(*(new Transition(s3, '0', s3, '1', Right)));
	transitions->push_back(*(new Transition(s3, '1', s3, '0', Right)));
	transitions->push_back(*(new Transition(s3, '#', s4, '#', Left)));
	transitions->push_back(*(new Transition(s4, '#', s4, '#', Left)));
	transitions->push_back(*(new Transition(s4, '0', s4, '0', Left)));
	transitions->push_back(*(new Transition(s4, '1', s4, '1', Left)));
	transitions->push_back(*(new Transition(s4, '$', sf, '$', Left)));

	vector<Tape>* tapes = new vector<Tape>();
	tapes->push_back(*tape);

	TuringMaschine* tm = new TuringMaschine(estates, transitions, tapes);

	cout << "Tape before processing: " << tm->GetTape(0) << "\n";
	tm->Calculate();
	cout << "Tape after processing: " << tm->GetTape(0) << "\n\n";
}

void Subtraction(string word)
{
	Tape* tape = new Tape(word, "|");

	Estate* s0 = new Estate("S0", Start);
	Estate* s1 = new Estate("S1", Default);
	Estate* s2 = new Estate("S2", Default);
	Estate* s3 = new Estate("S3", Default);
	Estate* s4 = new Estate("S4", Default);
	Estate* s5 = new Estate("S5", Default);
	Estate* s6 = new Estate("S6", Default);
	Estate* s7 = new Estate("S7", Default);
	Estate* s8 = new Estate("S8", Default);
	Estate* sf = new Estate("Sf", Final);

	vector<Estate>* estates = new vector<Estate>();
	estates->push_back(*s0);
	estates->push_back(*s1);
	estates->push_back(*s2);
	estates->push_back(*s3);
	estates->push_back(*s4);
	estates->push_back(*s5);
	estates->push_back(*s6);
	estates->push_back(*s7);
	estates->push_back(*s8);
	estates->push_back(*sf);

	vector<Transition>* transitions = new vector<Transition>();
	transitions->push_back(*(new Transition(s0, '$', s1, '$', Right)));
	transitions->push_back(*(new Transition(s1, '|', s1, '|', Right)));
	transitions->push_back(*(new Transition(s1, '#', s2, '#', Right)));
	transitions->push_back(*(new Transition(s2, '#', s2, '#', Right)));
	transitions->push_back(*(new Transition(s2, '|', s3, '|', Right)));	
	transitions->push_back(*(new Transition(s3, '|', s4, '|', Left)));
	transitions->push_back(*(new Transition(s3, '#', s6, '#', Left)));
	transitions->push_back(*(new Transition(s4, '|', s5, '#', Left)));
	transitions->push_back(*(new Transition(s5, '#', s5, '#', Left)));
	transitions->push_back(*(new Transition(s5, '|', s2, '#', Right)));
	transitions->push_back(*(new Transition(s5, '$', s2, '$', Right)));
	transitions->push_back(*(new Transition(s6, '|', s7, '#', Left)));
	transitions->push_back(*(new Transition(s7, '#', s7, '#', Left)));
	transitions->push_back(*(new Transition(s7, '$', sf, '$', Neutral)));
	transitions->push_back(*(new Transition(s7, '|', s8, '#', Left)));
	transitions->push_back(*(new Transition(s8, '|', s8, '|', Left)));
	transitions->push_back(*(new Transition(s8, '$', sf, '$', Neutral)));

	vector<Tape>* tapes = new vector<Tape>();
	tapes->push_back(*tape);

	TuringMaschine* tm = new TuringMaschine(estates, transitions, tapes);

	cout << "Tape before processing: " << tm->GetTape(0) << "\n";
	tm->Calculate();
	cout << "Tape after processing: " << tm->GetTape(0) << "\n\n";
}

void Increment(string word)
{
	Tape* tape = new Tape(word, "|");

	Estate* s0 = new Estate("S0", Start);
	Estate* s1 = new Estate("S1", Default);
	Estate* sf = new Estate("Sf", Final);

	vector<Estate>* estates = new vector<Estate>();
	estates->push_back(*s0);
	estates->push_back(*s1);
	estates->push_back(*sf);

	vector<Transition>* transitions = new vector<Transition>();
	transitions->push_back(*(new Transition(s0, '$', s1, '$', Right)));
	transitions->push_back(*(new Transition(s1, '|', s1, '|', Right)));
	transitions->push_back(*(new Transition(s1, '#', sf, '|', Neutral)));

	vector<Tape>* tapes = new vector<Tape>();
	tapes->push_back(*tape);

	TuringMaschine* tm = new TuringMaschine(estates, transitions, tapes);

	cout << "Tape before processing: " << tm->GetTape(0) << "\n";
	tm->Calculate();
	cout << "Tape after processing: " << tm->GetTape(0) << "\n\n";
}

void Addition(string word)
{
	Tape* tape = new Tape(word, "|&");
	
	Estate* s0 = new Estate("S0", Start);
	Estate* s1 = new Estate("S1", Default);
	Estate* s2 = new Estate("S2", Default);
	Estate* s3 = new Estate("S3", Default);
	Estate* s4 = new Estate("S4", Default);
	Estate* sf = new Estate("Sf", Final);

	vector<Estate>* estates = new vector<Estate>();
	estates->push_back(*s0);
	estates->push_back(*s1);
	estates->push_back(*s2);
	estates->push_back(*s3);
	estates->push_back(*s4);
	estates->push_back(*sf);

	vector<Transition>* transitions = new vector<Transition>();
	transitions->push_back(*(new Transition(s0, '$', s1, '$', Right)));
	transitions->push_back(*(new Transition(s1, '|', s1, '|', Right)));
	transitions->push_back(*(new Transition(s1, '&', s2, '|', Right)));
	transitions->push_back(*(new Transition(s2, '|', s2, '|', Right)));
	transitions->push_back(*(new Transition(s2, '#', s3, '#', Left)));
	transitions->push_back(*(new Transition(s3, '|', s4, '#', Left)));
	transitions->push_back(*(new Transition(s4, '|', s4, '|', Left)));
	transitions->push_back(*(new Transition(s4, '$', sf, '$', Neutral)));

	vector<Tape>* tapes = new vector<Tape>();
	tapes->push_back(*tape);

	TuringMaschine* tm = new TuringMaschine(estates, transitions, tapes);

	cout << "Tape before processing: " << tm->GetTape(0) << "\n";
	tm->Calculate();
	cout << "Tape after processing: " << tm->GetTape(0) << "\n\n";

	delete tm;
	delete tape;
	delete estates;
	delete transitions;
}

int main(int argc, char* argv[])
{
	cout << "Turing machine examples:\n";
	cout << "($ = tape start, # = tape end / minus, & = plus)\n\n";

	cout << "Test unary increment (TM: ||): \n";
	Increment("||");

	cout << "Test binary decrement (TM: 10110):\n";
	Decrement("10110");

	cout << "Test addition (TM: ||&|):\n";
	Addition("||&|");	
	
	cout << "Test subtraction (TM: |||||||#|):\n";
	Subtraction("|||||||#|");

	std::cout << std::endl;
	std::cin.get();
}
