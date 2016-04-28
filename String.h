#pragma once

#ifndef STRING_MYSTRING_H
#define STRING_MYSTRING_H

#include <string.h>
#include <iostream>

class Srep;
class Cref;
class Sref;

class String
{
	Srep *srep;
public:
	String();
	String(const char*);
	String(const String&); // конструктор копирования

	String& operator=(const char*);
	String& operator=(const String&);
	String& operator+=(const String&);
	String& operator+=(const char*);

	friend std::ostream& operator<< (std::ostream&, const String&);
	friend std::istream& operator>> (std::istream&, String&);
	friend bool operator== (const String&, const char*);
	friend bool operator== (const String&, const String&);
	friend bool operator!= (const String&, const char*);
	friend bool operator!= (const String&, const String&);
	friend String operator+ (const String&, const char*);
	friend String operator+ (const String&, const String&);

	Cref operator[](int);
	char operator[](int) const;

	Sref copy(int, int) const;
	void check(int) const;
	void write(int, char);

	char read(int) const;
	char* read(int, int) const;
	
	int size() const;
	~String();
};

class Srep
{
public:
	char* str;
	int length;	int n = 0; // число обращений к строке

	Srep* getOwnCopy();

	void assign(int, const char*);

	~Srep();
private:
	friend class String;
	/* конструктор копирования и операция присвоения
	 * перемещены в private область
	 * чтобы не было лишних копирований
	 * */
	Srep(int, const char*);
	Srep(const Srep&);
	Srep& operator=(const Srep&);
};

class Cref {
	friend class String;
	String& string;
	int index;
	Cref(String&, int);
public:
	operator char() const;

	void operator=(char);
};

class Sref
{
	friend  class String;
	String& string;
	int iBegin;
	int iEnd;
	Sref(String&, int, int);
public:
	operator char*() const;
};

class Range
{
public:
	Range() {}
};

#endif //STRING_MYSTRING_H
