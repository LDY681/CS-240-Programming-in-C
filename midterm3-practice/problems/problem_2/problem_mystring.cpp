
// String Implementation
// IMPORTANT: Do not use any of the functions in the string C runtime library
// Example. Do not use strcpy, strcmp, etc. Implement your own

// IMPORTANT: See the MyString.h file for a description of
// what each method needs to do.

#include <stdio.h>
#include "MyString.h"
#include <string.h>
// My own implementation of strlen
int
MyString::slength(const char *s) const
{
	int count = 0;
	while ( *(s+count) != '\0' ){
		count++;
	}
	return count;
}

// Initialize _s. Allocate memory for _s and copy s into _s
void
MyString::initialize(const char * s)
{
	//TODO:malloc doesnt work in c++, use new
	
	
  // Add implementation here
  // Allocate memory for _s.

  // Copy s into _s
  	_s = new char [100];
	int strlen = slength(s);
	int i;
	for (i = 0; i < strlen; i++){
		_s[i] = s[i];
	}
	_s[i] = '\0';
}

// Create a MyString from a C string
MyString::MyString(const char * s)
{
  initialize(s);
}

// Create a MyString from a copy of another string
MyString::MyString(const MyString &s)
{
  initialize(s._s);
}

// Create a MyString with an empty string
MyString::MyString()
{
  _s = new char[1];
  *_s = 0;
}

// Assignment operator. Without this operator the assignment is
// just a shallow copy that will copy the pointer _s. If the original _s
// goes away then the assigned _s will be a dangling reference.
MyString &
MyString::operator = (const MyString & other) {
  if (this != &other) // protect against invalid self-assignment
  {
    // deallocate old memory
    delete [] _s;

    // Initialize _s with the "other" object.
    initialize(other._s);

    // by convention, always return *this
    return *this;
  }
}

// Obtain a substring of at most n chars starting at location i
// if i is larger than the length of the string return an empty string.
MyString
MyString::substring(int i, int n)
{
  // Add implementation here

  // Make sure that i is not beyond the end of string

  // Allocate memory for substring

  // Copy characters of substring
  MyString sub;	//this is the substring we gonna return
	
  	if (i > slength(_s)){
		return "";		
	}

	char * ssub = new char [n];
	int j;
	for (j = 0; j < n; j++){
		*(ssub+j) = *(_s+i+j);
	} 
	ssub[j] = '\0';	//DONT FORGET THIS!!!
	sub = MyString(ssub);	


  // Return substring
  return sub;
}

// Remove at most n chars starting at location i
void
MyString::remove(int i, int n)
{
  // Add implementation here

  // If i is beyond the end of string return

  // If i+n is beyond the end trunc string

  // Remove characters
	if ( i > slength(_s)){
		return;
	}
	if ( i+n > slength(_s)){
		n = slength(_s) - i;
	}
	
	//remove characters
	int j,k;
	for (j = 0; j < n; j++){
		for (k = i; k < slength(_s)-1; k++){
			_s[k] = _s[k+1];
		}
	}
	_s[slength(_s) -n] = '\0';
	return;
}

// Return true if strings "this" and s are equal
bool
MyString::operator == (const MyString & s)
{
  // Add implementation here
	if (strcmp(this->_s, s._s) == 0 ){
		return true;
	}
	return false;
}


// Return true if strings "this" and s are not equal
bool
MyString::operator != (const MyString &s)
{
  // Add implementation here
	if (strcmp(this->_s, s._s) != 0 ){
		return true;
	}
	return false;
}

// Return true if string "this" and s is less or equal
bool
MyString::operator <= (const MyString &s)
{
  // Add implementation here
	if (strcmp(this->_s, s._s) <= 0 ){
		return true;
	}
	return false;
}

// Return true if string "this" is greater than s
bool
MyString::operator > (const MyString &s)
{
	if (strcmp(this->_s, s._s) > 0 ){
		return true;
	}
	return false;
}

// Return character at position i.  Return '\0' if out of bounds.
char
MyString::operator [] (int i)
{
	if (i > slength(_s)){
		return '\0';
	}

	return *(_s+i);
}

// Return C representation of string
const char *
MyString::cStr()
{
  // Add implementation here
  return _s;
}

// Get string length of this string.
int
MyString::length() const
{
  // Add implementation here
  return slength(_s);
}

// Destructor. Deallocate the space used by _s
MyString::~MyString()
{
  // Add implementation here
  delete [] _s;
}

// Concatanate two strings (non member method)
MyString operator + (const MyString &s1, const MyString &s2)
{
  // Add implementation here

  // Allocate memory for the concatenated string

  // Add s1

  // Add s2

  MyString s;
  	char * ss1 = strdup(s1._s);
	char * ss2 = strdup(s2._s);
	char* ss3 = new char[300];
	strcat(ss3,ss1);
	strcat(ss3,ss2);
	s = MyString(ss3);
  return s;
}

