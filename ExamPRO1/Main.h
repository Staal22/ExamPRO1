#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>

std::vector<std::string> SetOne = { "Jack", "Sara", "Sina", "Rose" };
std::vector<std::string> SetTwo = { "Sara", "John", "Hana", "Sina" };
std::string namestring{};
std::string line = "\n-------------\n";
std::string equation = "0";

const char* equationC{};
long phonenumber{};
bool newP = true;
int count{};
int answer{};
char response = 'n';

char calc[5][4] = {};
char cursor[5][4] = {};

class Person {
	std::string name;
	long phone;
public:
	Person(std::string, long);
	Person();
};

Person::Person(std::string a, long b) {
	name = a;
	phone = b;
	std::ofstream outf{ "userdb.txt", std::ios::app };
	outf << "Name : " << a << " | Phone number : " << b << std::endl;
	outf.close();
}

Person::Person() {
	name = "";
	phone = 0;
}


void menu();
void task1();
void task2();
void task3();
int expression();