#include <iostream>
using namespace std;

template <typename T> 
class Stack
{
private:
    struct Node{
        T m_data;
        Node* pNext;
        Node() {
            this->pNext = NULL;
        }
    };
    Node* head;
public:
    Stack(){
       this->head = NULL;
    }
    void pop();
    void push(T data);
    int size();
    void top();
    bool isEmpty();
    void insertAt(int index, T data);
    void removeAt(int index);
    void print();
};

template <typename T> 
void Stack <T>::push(T data){
    Node* node = new Node;
    node->m_data = data;
    if(head == NULL){
        head = node;
        return;
    }
    Node* temp = head;
    while(temp->pNext != NULL){
        temp = temp->pNext;
    }
    temp->pNext = node;
}

template <typename T> 
void Stack <T>::pop(){
    if(head == NULL){
        cout<<"Stack is empty !"<<endl;
        return;
    }
    if(head->pNext == NULL){
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        if(temp->pNext->pNext == NULL){
            temp->pNext = NULL;
            break;
        }
        temp = temp->pNext;
    }
}


template <typename T> 
bool Stack <T>::isEmpty(){
    return head == NULL;
}

template <typename T> 
int Stack <T>::size(){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->pNext;
    }
    return len;
}

template <typename T>
void Stack <T>::top(){
    if(head == NULL){
        cout << "Stack is empty !" << endl;
        return;
    }
    if(head->pNext == NULL){
        cout <<  head->m_data;
    }
    int count = 0;
    T res;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == size()){
            res = temp->m_data;
            break;
        }
        temp = temp->pNext;
    }
    cout << res;
}

template <typename T> 
void Stack <T>::insertAt(int index, T data){
    if(index > size() || index < 0){
        cout<<"Your index is bigger than Size of Stack!"<<endl;
        return;
    }
    Node* node = new Node;
    node->m_data = data;
    int count = 0;
    Node* temp = head;
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
void Stack <T>::removeAt(int index){
    if(isEmpty()){
        cout<<"Stack is empty !"<<endl;
        return;
    }

    if(index >= size() || index < 0){
        cout<<"Your index is bigger than Size of Stack!"<<endl;
        return;
    }

    if(index == 0){
        head = head->pNext;
        return;
    }

    int count = 0;
    Node* temp = head;
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
void Stack <T>:: print(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while(temp != NULL){
        cout << temp->m_data<< endl;
        temp = temp->pNext;
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

    cout << "\nTop Element is: " ; S.top(); cout << endl;

    return 0;
}
