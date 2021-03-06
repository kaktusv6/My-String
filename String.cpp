#include "String.h"

/* class String ======================================= */

/* methods class String ======================================= */

String::String()
{
	srep = new Srep(0, "");
}
String::String(const String& _string)
{
	_string.srep->n++;
	srep = _string.srep;
}
String::String(const char* _str)
{
	srep = new Srep((int)strlen(_str), _str);
}
String& String::operator=(const String& _string)
{
	_string.srep->n++;
	if (--srep->n == 0) delete srep;
	srep = _string.srep;
	return *this;
}
String& String::operator=(const char* _str)
{
	if (srep->n == 1)
		srep = new Srep((int)strlen(_str), _str);
	else
	{
		srep->n--;
		srep = new Srep((int)strlen(_str), _str);
	}
	return *this;
}
Cref String::operator[](int i)
{
	check(i);
	return Cref(*this, i);
}
char String::operator[](int i) const
{
	check(i);
	return srep->str[i];
}
void String::check(int i) const
{
	if (i < 0 || srep->length <= i)
		throw Range();
}
void String::write(int i, char ch)
{
	srep = srep->getOwnCopy();
	srep->str[i] = ch;
}
char String::read(int i) const
{
	return srep->str[i];
}
String String::read(int iBegin, int iEnd) const
{
	String str = "";
	for (int i = iBegin; i <= iEnd; ++i)
		str += this->operator[](i);
	return str;
}
int String::size() const
{
	return srep->length;
}
String& String::operator+= (const String& string)
{
	Srep* srep = this->srep->getOwnCopy();
	strcat(srep->str, string.srep->str);
	srep->length += string.srep->length;
	this->srep = srep;
	return *this;
}
String& String::operator+= (const char c)
{
	Srep* srep = this->srep->getOwnCopy();
	srep->str[srep->length] = c;
	srep->str[++srep->length] = '\0';
	this->srep = srep;
	return *this;
}
String& String::operator+= (const char* str)
{
	Srep* srep = this->srep->getOwnCopy();
	strcat(srep->str, str);
	srep->length += strlen(str);
	this->srep = srep;
	return *this;
}
Sref String::copy(int index, int count)
{
	check(index);
	check(count == 0 ? index : index + count - 1);
	return Sref(*this, index, index + count - 1);
}
String::~String()
{
	if(--srep->n == 0)delete srep;
}

/* friend functions class String ======================================= */

std::ostream& operator<< (std::ostream& out, const String& string)
{
	out << string.srep->str;
	return out;
}
std::istream& operator>> (std::istream& in, String& string)
{
	string.srep = string.srep->getOwnCopy();
	in >> string.srep->str;
	string.srep->length = (int)strlen(string.srep->str);
	return in;
}
bool operator== (const String& str, const char* ch)
{
	return strcmp(str.srep->str, ch) == 0;
}
bool operator== (const String& str1, const String& str2)
{
	return strcmp(str1.srep->str, str2.srep->str) == 0;
}
bool operator!= (const String& str, const char* ch)
{
	return strcmp(str.srep->str, ch) != 0;
}
bool operator!= (const String& str1, const String& str2)
{
	return strcmp(str1.srep->str, str2.srep->str) != 0;
}
String operator+ (const String& str, const char* ch)
{
	String string(str.srep->str);
	strcat(string.srep->str, ch);
	string.srep->length = (int)strlen(string.srep->str);
	return string;
}
String operator+ (const String& str1, const String& str2)
{
	String string(str1.srep->str);
	strcat(string.srep->str, str2.srep->str);
	string.srep->length = (int)strlen(string.srep->str);
	return string;
}

/* methods class Srep ======================================= */

Srep::Srep(int _length, const char* _str) : length(_length)
{
	n = 1;
	str = new char[_length + 1];
	strcpy(str, _str);
}
Srep* Srep::getOwnCopy()
{
	if (n == 1) return this;
	n--;
	return new Srep(length, str);
}
void Srep::assign(int _length, const char* _str)
{
	if (_length != length)
	{
		delete[] str;
		length = _length;
		str = new char[_length + 1];
	}
	strcpy(str, _str);
}
Srep::~Srep()
{
	delete[] str;
}

/* methods class Cref ======================================= */

Cref::Cref(String& _string, int i) : string(_string), index(i)
{}
Cref::operator char() const
{
	return string.read(index);
}
void Cref::operator=(char ch)
{
	string.write(index, ch);
}

/* methods class Sref ======================================= */

Sref::Sref(String& str, int _iBegin, int _iEnd) : string(str),
												  iBegin(_iBegin),
												  iEnd(_iEnd)
{  }
Sref::operator String() const
{
	return string.read(iBegin, iEnd);
}

/* friend functions class Sref ======================================= */

bool operator== (const char ch[], const Sref& sref)
{
	return sref == ch;
}
