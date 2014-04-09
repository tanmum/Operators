// String.hpp

#ifndef STRING_HPP
#define STRING_HPP

#include <stdio.h>

class String						// The FILE data type is defined in stdio.h
{
private:

	long length;					// character string length
	char *s;						// Actual data

	void stncpy(char *dest, const char *src, long n); // Copy n characters of src into dest
	void initCopy(const char *str);		// Initial Copy of char string
	void create(long i);			// create a character string of length i
	long strLen(const char *t);			// Return length of t
	void copy(const char *str);			// Copy contents of str into local char string
	long maX(long l, long m);		// returns biggest long

public:
	String();						// String empty constructor
	String(const char *str);				// String initialized with a char string
	String(const String& st);				// String initialized with a String	reference
	String(const String *sp);				// String initialized with a String	pointer
	String(long l);					// String with initial length of l	
	
	~String();						// Destructor to clean up when object is gone

	void prt(FILE *f = stderr) const;		// Print out current contents into f, or stderr by default
	long ln() const;						// Return current content's length
	void clear();					// Clear out entire contents
	void setTo(const char *t);			// Set String to t char string
	const char *getStr(){return s;};		// Get char string

	// Add Operators:
    String& operator << (const String& s);
    String& operator << (const char* s);
    String& operator << (char c);
    String& operator = (const String& s);
    String& operator = (const char* s);
    String& operator = (char c);

};


#endif
