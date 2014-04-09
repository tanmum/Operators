// String.cpp
#include <iostream>
using namespace std;

#include "String.hpp"

String::String()
{
	s = 0;								// Always initialize
	length = 0;
}

String::String(const char *str)
{
	s = 0;								// Always initialize
	length = 0;
	initCopy(str);
}
    
String::String(const String& string)
{
	s = 0;								
	length = 0;
	initCopy(string.s);
}
    
String::String(const String *st)
{
	s = 0;								
	length = 0;
	if (st && st->s)
		initCopy(st->s);
}
    
String::String(long length)
{
	s = 0;
	String::length = 0; 

	if (length > 0)
		create(length);
}    
    
String::~String()
{
	if (s)
		{
		delete[] s;						// Deleting an array
		s = 0, length = 0;
		}
}

void String::initCopy(const char *str)
{
	if (str)
		{
		create(strLen(str));
		copy(str);
		}
}

void String::clear()
{
	if (s)
		for (long i = 0; i < length; i++)
			s[i] = 0;
}

       
long String::ln() const
{
	long l = 0;
	if (s)
		while (s[l]) 
			l++;
	return l;
}       
       
void String::stncpy(char *dest, const char *src, long n)
{
	if (dest && src)
		while ((n-- > 0) && (*dest++ = *src++))
			;
}
  
void String::copy(const char *str)
{
	if (s && str)
		stncpy(s, str, length - 1);
}

long String::maX(long l, long m)
{
	return (l >= m) ? l : m;
}

void String::create(long l)
{
	length = maX(l+1, 2*length);	// avoid too frequent re-allocations
	s = new char[length];
	clear();
}

void String::prt(FILE *f) const
{
	if (s)
		fprintf(f, "<%s>\n", s);
	else
		fprintf(f, "<>\n");
} 

long String::strLen(const char *t)
{
	long ret = 0;

	if (t)
		while (*t++)
			ret++;

	return ret;
}

void String::setTo(const char *t)
{
	if (t)
		{
		long l = strLen(t);  			// length needed
		l = (l >= 1 ? l : 1);			// consider it's at least equal to 1
		if (l > length - 1)				// allocate more space if needed
			{
			if (s) delete [] s, s = 0, length = 0;
			create(l);
			}
		copy(t);						// copy contents t is pointing to
		}
	else
		clear();
}

// Operators

String& String::operator<<(const String &s)
{
    return (*this) << s.s;
}

String& String::operator<<(const char *s)
{
    if (!s) {
        return *this;
    }
    long sLn = strLen(s);
    long totalLn = this->ln() + sLn;
    if (totalLn < this->length) {
        char* to = this->s + ln();
        const char* from = s;
        stncpy(to, from, sLn);
    } else {
        char* old = this->s;
        create(totalLn);
        stncpy(this->s, old, length);
        delete [] old;
        char* to = this->s + ln();
        const char* from = s;
        stncpy(to, from, sLn + 1);
    }
    return *this;
}

String& String::operator<<(char c)
{
    char sc[] = " ";
    sc[0] = c;
    return * this << sc;
}

String& String::operator=(const String &s)
{
    (*this) = s.s;
    return *this;
}

String& String::operator=(const char* s)
{
    setTo(s);
    return *this;
}

String& String::operator=(char c)
{
    char sc[] = " ";
    sc[0] = c;
    operator=(sc);
    return *this;
}
          


