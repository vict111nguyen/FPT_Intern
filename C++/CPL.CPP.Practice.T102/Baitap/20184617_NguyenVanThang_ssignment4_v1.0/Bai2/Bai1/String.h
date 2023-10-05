#ifndef String_h
#define String_h
#include <iostream>
using namespace std;

class Mystring{
private: 
    char* m_str;
    int m_size;
public:
    Mystring();
    Mystring(const char *ch);
    Mystring(const Mystring &str);
    ~Mystring();
    friend ostream &operator<<(ostream& os, const Mystring& obj);
    friend istream &operator>>(istream& is, Mystring& obj);
    //Operator + overload for char, char*, 1 phần tử kiểu tham chiểu Mystring
    Mystring operator+(const char c);
    Mystring operator+(const char *ch);
    Mystring operator+(const Mystring &str);
    //Operator += overload for char, char*, 1 phần tử kiểu tham chiểu Mystring
    Mystring operator+=(const char c);
    Mystring operator+=(const char *ch);
    Mystring operator+=(const Mystring &str);
    //Operator = overload for char, char*, 1 phần tử kiểu tham chiểu Mystring
    Mystring operator=(const char c);
    Mystring operator=(const char *ch);
    Mystring operator=(const Mystring &str);
    // Operator ==
    bool operator==(const Mystring &str); 
    int get_length(const char *s);
    
    void *copy(void *dest, const void *src, size_t num);
    void reverse();
    void del();
    int compare(const char *str1, const char *str2);
};

#endif 