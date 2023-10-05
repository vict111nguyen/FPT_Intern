#include "String.h"

Mystring::Mystring(){
    m_size = 0;
    m_str = new char[m_size+1];
    m_str[0] = NULL; //'\0'
}
Mystring::Mystring(const char *ch){
    m_size = get_length(ch);
    m_str = new char[m_size +1];
    copy(m_str, ch, m_size+1);
}

istream& operator>>(istream& is, Mystring& obj)
{
    is>>obj.str;
    return is;
}
 
// Overloading the stream
// insertion operator
ostream& operator<<(ostream& os, const Mystring& obj)
{
    os << obj.str;
    return os;
}
 
// Function for swapping string
void Mystring::swp(Mystring& rhs)
{
    Mystring temp{ rhs };
    rhs = *this;
    *this = temp;
}
 
// Function to copy the string
void *Mystring::copy(void * dest, const char* src, int len)
{
    char *cpySrc = (char *)src;
    char *cpyDest = (char *)dest;
    for (int i = 0; i < len; i++) {
        [i] = len[pos + i];
    }
    s[len] = '\0';
}
int Mystring::get_length()
{
    this->str;
    int i=0;
    while(str[i] != '\0') {
      i++;
    }
    return i;
}
Mystring::Mystring() : str{ nullptr }
{
    str = new char[1];
    str[0] = '\0';
}

Mystring::Mystring(char* val)
{
    if (val == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
 
    else {
 
        str = new char[get_length() + 1];
 
        // Copy character of val[]
        // using strcpy
        copy(str, get_length(),0);
        str[get_length()] = '\0';
    }
}
//Copy Constructor 
Mystring::Mystring(const Mystring& source)
{
    str = new char[get_length() + 1];
    copy(str,get_length(),0);
}