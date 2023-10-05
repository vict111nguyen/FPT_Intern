#include<iostream>

using namespace std;

template <typename T>
class Queue {
private:
	int Max = 10;
	T* m_arr = new T[Max];
	int m_front = 0;
    int m_rear = -1;
    int count = 0;
public:

	bool isEmpty();
	void inc_arr_size();
	void enqueue(T data);
	void dequeue();
	T front();
	T back();
	int size();
	void insertAt(int index, T data);
	void removeAt(int index);
	void print();
};

template <typename T> 
bool Queue <T>::isEmpty(){
	return m_front == -1;
}

template <typename T> 
void Queue <T>::inc_arr_size(){
	Max = Max + 1;
	T* tmp = new T[Max];

	for(int i = 0; i < count; i++)
		tmp[i] = m_arr[i];

	delete [] m_arr;

	m_arr = tmp;
}

template <typename T> 
void Queue <T>::enqueue(T data){
	if(count == Max)
		inc_arr_size();
	m_rear++;
	m_arr[m_rear] = data;
	count++; 
}

template <typename T> 
void Queue <T>::dequeue()
{
	if(isEmpty()){
		cout<<"Queue is empty !"<<endl;
		return;
	}
	m_front++;
	count--;
}

template <typename T> 
T Queue <T>::front()
{
	if(isEmpty()){
		throw runtime_error(std::string("Queue is empty"));
	}
	return m_arr[m_front];
}

template <typename T> 
T Queue <T>::back()
{
	if(isEmpty()){
		throw runtime_error(std::string("Queue is empty"));
	}
	return m_arr[m_rear];
}

template <typename T> 
int Queue <T>::size(){
	return count;
}

template <typename T> 
void Queue <T>::insertAt(int index, T data){
	if(count == Max)
		inc_arr_size();
	if(index >= size() || index < 0){
		cout<<"Your index is bigger than Size of Queue!"<<endl;
		return; 
	}
	count++;   
	m_rear++;
	T *q = new T[Max];
	for (int i = m_front; i < m_rear; i++)
		q[i] = m_arr[i];
	for (int i = m_rear; i > index + m_front; i--)
	{
		q[i] = q[i - 1];
	}
	q[index+m_front] = data;
	/*Tiến hành cấp phát động lại */
	delete m_arr;
	m_arr = new T[Max];
	for (int i = m_front; i <= m_rear; i++)
		m_arr[i] = q[i];
}

template <typename T> 
void Queue <T>::removeAt(int index){
	if(isEmpty()){
		cout<<"Queue is empty !"<<endl;
		return;
	}
	if(index >= size() || index < 0){
		cout<<"Your index is bigger than Size of Queue!"<<endl;
		return;
	}
	for(int i = index + m_front; i < m_rear; i++){
		m_arr[i] = m_arr[i+1];
	}
	count--;
	m_rear--;
}

template <typename T> 
void Queue <T>:: print (){
	for(int i = m_front;i <= m_rear; i++){
		cout << m_arr[i] << endl;
	}
}
template class Queue<string>;
template class Queue<int>;
template class Queue<char>;
template class Queue<double>;

int main()
{
	Queue<string> Q;
	// Queue<int> Q_int;
	// Queue<char> Q_char;
	// Queue<double> Q_db;

	Q.enqueue("Nguyen Van A");
	// Q_int.enqueue(10);
	// Q_char.enqueue('A');
	// Q_db.enqueue(3.2);
	Q.enqueue("Tran Van B");
	Q.enqueue("Hoang Van C");
	Q.enqueue("Vu Tan D");
	Q.enqueue("Vu Huu E");
    cout << "The orginal Queue is: "<< endl;
    Q.print(); 
	//Q.dequeue();
    Q.dequeue();
    cout << "\nQueue after dequeue: \n";
    Q.print();
    cout << "\nFront element of queue: " << Q.front() << endl;
    cout << "\nBack element of queue: " << Q.back() << endl;
    Q.insertAt(3,"Hoang Anh F");
    cout << "\nQueue after insert: \n";
    Q.print();
    cout <<"\nSize of queue: " << Q.size();
    Q.removeAt(2);
    cout << "\nQueue after removed: \n";
    Q.print();
	return 0;
}