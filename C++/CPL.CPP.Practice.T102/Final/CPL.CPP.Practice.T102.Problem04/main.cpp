#include<iostream>
#include<iomanip>

#define W_ACCOUNT 10
#define W_NAME 20
#define W_DEPARTMENT 15
#define W_JOB 15
#define W_PROJECTNAME 15

using namespace std;
class Employees{
private:
    string m_account;
    string m_name;
    string m_department;
    string m_job;
public:
    virtual void showInformation(){
        cout << setw(W_ACCOUNT) << left << m_account
            << setw(W_NAME) << m_name
            << setw(W_DEPARTMENT) << m_department
            << setw(W_JOB) << m_job << endl;
    }
    virtual void DisplayDailyWork() = 0;
    void setAccount(string acc){m_account = acc;}
    string getAccount(){return m_account;}
    void setName(string name){m_name = name;}
    string getName(){return m_name;}
    void setDepartment(string department){m_department = department;}
    string getDepartment(){return m_department;}
    void setJob(string job){m_job = job;}
    string getJob(){return m_job;}
};

class Developer : public Employees
{
private: 
    string m_projectName;
public:
    void showInformation(){
        cout << setw(W_ACCOUNT) << left << getAccount()
            << setw(W_NAME) << getName()
            << setw(W_DEPARTMENT) << getDepartment()
            << setw(W_JOB) << getJob() 
            << setw(W_PROJECTNAME) << m_projectName << endl;
    }
    void DisplayDailyWork(){
        cout << "Coding in project: " << m_projectName <<endl;
    }
};

class Manager: public Employees{
private:
    string m_customerName;
public:
    void showInformation(){
        cout << setw(W_ACCOUNT) << left << getAccount()
            << setw(W_NAME) << getName()
            << setw(W_DEPARTMENT) << getDepartment()
            << setw(W_JOB) << getJob() 
            << setw(W_PROJECTNAME) << m_customerName << endl;
    }
    void DisplayDailyWork(){
        cout << "Working with customer: " << m_customerName <<endl;
    }
};
int main(){

    return 0;
}