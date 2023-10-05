#include <iostream>
using namespace std;

template <typename T> 
class Queue
{
private:
    struct Node{
        T m_data;
        Node* pNext;
        Node() {
            this->pNext = NULL;
        }
    };
    Node *m_front;
    Node *rear;
public:
    Queue(){
       this -> m_front = NULL;
       this -> rear = NULL;
    }
    bool isEmpty();
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
    return m_front == NULL;
}

template <typename T> 
void Queue <T>::enqueue(T data){
    Node *p;
	p = new Node;
	p->m_data = data;
	p->pNext = NULL;
	if (m_front!=NULL){
		rear->pNext = p;
	}else{
		m_front = p;
	}
	rear = p;
}

template <typename T> 
void Queue <T>::dequeue(){
    if (m_front == NULL){
        cout<<"Queue is empty";
        return;
	}
    else{
		T res = m_front->m_data;
		Node *p = m_front->pNext;
		delete m_front;
		m_front = p;
		if(m_front == NULL){
			rear = NULL;
		}
	}
}

template <typename T> 
T Queue <T>::front(){
    if(isEmpty()){
        throw runtime_error(std::string("Queue is empty"));
    }
    return m_front->m_data;
}

template <typename T> 
T Queue <T>::back(){
    if(isEmpty()){
        throw runtime_error(std::string("Queue is empty"));
    }
    return rear->m_data;
}

template <typename T> 
int Queue <T>::size(){
    Node* tmp = m_front;
    int i=0;
    while(tmp != NULL){
        i++;
        tmp = tmp->pNext;
    }
    return i;
}

template <typename T> 
void Queue <T>::insertAt(int index, T data){
    if(index > size() || index < 0){
        cout<<"Your index is bigger than Size of Queue!"<<endl;
        return;
    }
    Node* node = new Node;
    node->m_data = data;
    int count = 0;
    Node* temp = m_front;
    while(temp != NULL && count < index){
        if(count == index-1){
            if(temp->pNext != NULL){
                node->pNext = temp->pNext;
            }
            temp->pNext = node;
            break;
        }
        count++;
        temp = temp->pNext;
    }
}

template <typename T> 
void Queue <T>::removeAt(int index){
    if(isEmpty()){
        cout<<"Stack is empty !"<<endl;
        return;
    }

    if(index >= size() || index < 0){
        cout<<"Your index is bigger than Size of Queue!"<<endl;
        return;
    }

    if(index == 0){
        m_front = m_front->pNext;
        return;
    }

    int count = 0;
    Node* temp = m_front;
    while(temp != NULL){
        if(count == index - 1){
            temp->pNext = temp->pNext->pNext;
            break;
        }
        count++;
        temp = temp->pNext;
    }
}

template <typename T> 
void Queue <T>:: print (){
    Node  *p;
	p = m_front;
	while (p!= NULL){
		cout << p -> m_data << endl;
		p = p -> pNext;
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
