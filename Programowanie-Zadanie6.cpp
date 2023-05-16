// Programowanie-Zadanie6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <fstream>

using namespace std;

#include "student.h"


int main()
{
	ifstream fileIn("dataInput.txt");
	ofstream fileOut("dataOutput.txt");
	student studentData;
	vector<student> students;


	while (fileIn >> studentData) {
		students.push_back(studentData);

	} // zapisujemy dane z "fileIn.txt" do wektora students

	fileIn.close();


	for_each(students.begin(), students.end(), [](student s) {
		cout << "Nazwisko: " << s.nazwisko << ", Imie: " << s.imie << ", Numer Albumu: " << s.albumNr << ", Grupa: " << s.grupa << ", Rok: " << s.rok << endl;
		}); // wyswietlamy studentow


	// Wyswietlamy liczbe 3rd-year students za pomoca count_if()
	int studentsNum = count_if(students.begin(), students.end(), [](student s) {
		return s.rok == 3;
		});
	cout << "\nThird-year students number: " << studentsNum << endl;
	//


	//// Wyswietlamy liczbe 3rd-year students za pomoca iteratora
	//int studentsNum = 0;
	//for (vector<student>::iterator st = students.begin(); st != students.end(); st++) {
	//	if (st->rok == 3) {
	//		studentsNum++;
	//	}
	//}
	//cout << "\nThird year students number: " << studentsNum << endl;
	////


	// Dane wychodzace
	fileOut << "Number of third-year students: " << studentsNum << endl << endl;
	for_each(students.begin(), students.end(), [&fileOut](student s) {
		if (s.rok == 3) {
			fileOut << s;
		}
		});
	//

	fileOut.close();


}