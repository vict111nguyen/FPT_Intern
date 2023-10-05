#include<iostream>

using namespace std;

template<typename T>
class Stack {
private:
	int Max = 10;
	T* m_arr = new T[Max];
	int m_top = 0;
public:
	bool isEmpty();
	void inc_arr_size();
	void pop();
    void push(T data);
    int size();
    T top();
    void insertAt(int index, T data);
    void removeAt(int index);
    void print();
};

template <typename T> 
bool Stack <T>::isEmpty(){
	return (m_top<=0);
}

template <typename T>
void Stack <T>::inc_arr_size(){
	Max = Max + 1;
	T* tmp = new T[Max];

	for(int i = 0; i < m_top; i++)
		tmp[i] = m_arr[i];

	delete [] m_arr;

	m_arr = tmp;
}

template <typename T> 
void Stack <T>::push(T data){
	if(m_top == Max)
		inc_arr_size();
	m_arr[m_top++] = data;
}

template <typename T> 
void Stack <T>::pop()
{
	if(m_top == 0)
		throw std::underflow_error("Stack Underflow!");
	else 
	m_top--;
}

template <typename T>
T Stack <T>::top(){
	return m_arr[m_top - 1];
}

template <typename T> 
int Stack <T>::size(){
	return m_top;
}

template <typename T> 
void Stack <T>::insertAt(int index, T data){
	if(m_top == Max)
		inc_arr_size();
	m_top++;
	T *s = new T[Max];
	for (int i = 0; i < m_top-1; i++)
		s[i] = m_arr[i];
	for (int i = m_top - 1; i > index; i--)
		s[i] = s[i - 1];
	s[index] = data;
	/*Tiến hành cấp phát động lại */
	delete m_arr;
	m_arr = new T[Max];
	for (int i = 0; i < m_top; i++)
		m_arr[i] = s[i];
}

template <typename T> 
void Stack <T>::removeAt(int index){
	if(isEmpty()){
		cout<<"Stack is empty !"<<endl;
		return;
	}
	if(index >= size() || index < 0){
		cout<<"Your index is bigger than Size of Stack!"<<endl;
		return;
	}
	for(int i = index;i < m_top - 1;i++){
			m_arr[i] = m_arr[i+1];
	}
	m_top--;
}

template <typename T> 
void Stack <T>:: print(){
	for(int i = m_top-1;i >= 0; i--){
		cout << "	"<< m_arr[i] << endl;
	}
}



template class Stack<string>;
template class Stack<int>;
template class Stack<char>;
template class Stack<double>;

int main(){
    Stack<string> S;
	// Stack<int> S_int;
	// Stack<char> S_char;
	// Stack<double> S_db;

	S.push("Nguyen Van A");
	// S_int.push(10);
	// S_char.push('A');
	// S_db.push(3.2);
	S.push("Tran Van B");
	S.push("Hoang Van C");
	S.push("Vu Tan D");
	S.push("Vu Huu E");
    cout << "The orginal Stack is: "<< endl;
    S.print();
	S.insertAt(4,"Hoang Van F");
    cout << "\nStack after inserting is: \n";
	S.print();

	S.removeAt(3);
	cout << "\nStack after removing is: \n";
	S.print();

    cout << "\nTop Element is: " << S.top() << endl;

    return 0;
}

