#pragma once
class student
{
public:
	string nazwisko;
	string imie;
	int albumNr;
	string grupa;
	int rok;

	friend istream& operator>>(istream& input, student& student);
	friend ostream& operator<<(ostream& output, student& student);
};
