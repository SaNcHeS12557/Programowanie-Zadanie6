#include <iostream>
#include <stdlib.h>

using namespace std;

#include "student.h"

istream& operator>>(istream& input, student& student) {
	input >> student.nazwisko >> student.imie >> student.albumNr >> student.grupa >> student.rok;
	return input;
};

ostream& operator<<(ostream& output, student& student) {
	output << student.nazwisko << endl << student.imie << endl << student.albumNr << endl << student.grupa << endl << student.rok << endl;
	return output;
};