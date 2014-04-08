// String.hpp

#ifndef STRING_HPP
#define STRING_HPP

#include <stdio.h>

class String						// The FILE data type is defined in stdio.h
{
private:

	long length;					// character string length
	char *s;						// Actual data

	void stncpy(char *dest, char *src, long n); // Copy n characters of src into dest									
	void initCopy(char *str);		// Initial Copy of char string	
	void create(long i);			// create a character string of length i
	long strLen(char *t);			// Return length of t	
	void copy(char *str);			// Copy contents of str into local char string
	long maX(long l, long m);		// returns biggest long

public:
	String();						// String empty constructor
	String(char *str);				// String initialized with a char string	
	String(String& st);				// String initialized with a String	reference
	String(String *sp);				// String initialized with a String	pointer
	String(long l);					// String with initial length of l	
	
	~String();						// Destructor to clean up when object is gone

	void prt(FILE *f = stderr);		// Print out current contents into f, or stderr by default
	long ln();						// Return current content's length 
	void clear();					// Clear out entire contents
	void setTo(char *t);			// Set String to t char string
	char *getStr(){return s;};		// Get char string

	// Add Operators:
    String& operator << (String& s);
    String& operator << (char* s);
    String& operator << (char c);
    String& operator = (String& s);
    String& operator = (char* s);
    String& operator = (char c);

};


#endif
