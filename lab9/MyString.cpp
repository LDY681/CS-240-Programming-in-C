
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
	int len = 0;
	while ( *(s+len) != '\0'){
		len++;
	}
	
 	return len;
}

// Initialize _s. Allocate memory for _s and copy s into _s
void
MyString::initialize(const char * s)
{
  // Add implementation here
  // Allocate memory for _s.

  // Copy s into _s
	int strlen = slength(s);
	_s = new char[strlen];	//_s already declared in Mystring,h

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
	MyString sub;	//sub is type Mystring, so need to create a char* and store and then Mystring it
	
	if ( i > length() ){
		return "";
	}
	
	char* ssub = new char(n);

	int j;
	for ( j = 0; j < n; j++){
		ssub[j] = _s[i+j];
	}
	ssub[j] = '\0';

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
	if ( i > length() ){
		return;
	}
  // If i+n is beyond the end trunc string
	if ( i + n > length() ){
		n = length() - i;
	}
  // Remove characters
	int j, k;
	for ( k = 0; k < n; k++){
		for ( j = i; j < length() - 1; j++){
			_s[j] = _s[j+1];	//remove one and fresh
		}
	}
	_s[length() - n] = '\0';
}

// Return true if strings "this" and s are equal
bool
MyString::operator == (const MyString & s)
{
  // Add implementation here
  //
  // TODO: question, why this->cStr() didnt work?
  
  return ( strcmp(this->cStr(), s._s) == 0 );
}


// Return true if strings "this" and s are not equal
bool
MyString::operator != (const MyString &s)
{
  // Add implementation here
  return ( strcmp( this->_s, s._s) != 0 );
}

// Return true if string "this" and s is less or equal
bool
MyString::operator <= (const MyString &s)
{
  // Add implementation here
  return ( strcmp( this->_s, s._s) <= 0 );
}

// Return true if string "this" is greater than s
bool
MyString::operator > (const MyString &s)
{
  // Add implementation here
  return ( strcmp( this->_s, s._s) > 0 );
}

// Return character at position i.  Return '\0' if out of bounds.
char
MyString::operator [] (int i)
{
  // Add implementation here
	if ( i > length() ){
		return '\0';
	}
      	return _s[i];
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
  	s._s = new char[100];
	strcat(s._s, s1._s);
	strcat(s._s, s2._s);
  return s;
}

