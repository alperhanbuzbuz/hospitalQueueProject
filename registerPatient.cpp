#include <iostream>
#include <queue>
#include <list>

using namespace std;


class Human{

    protected:
            string name;
            int age;
            bool isDisabled;

    public:

        Human(string initName,int initAge,bool initIsDisabled){

            name = initName;
            age = initAge;
            isDisabled = initIsDisabled;
            
        }

        void print(){

            string isDisabledStr;
            isDisabledStr = (isDisabled) ? "Disabled" : "Not Disabled";

            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
            cout << isDisabledStr << endl;
        }

        string getName() const { return name; }
        int getAge() const { return age; }
        bool getIsDisabled() const { return isDisabled; }
    
};


class Patient : public Human{

    int patientNo;
    int priorty;
public:

    Patient(int patientNo,Human& h) : patientNo(patientNo),Human(h),priorty(0){
        calculatePriorty();
    }

    Patient(int patientNo,string name,int age,bool isDisabled) : patientNo(patientNo),Human(name,age,isDisabled),priorty(0){
        calculatePriorty();
    }

    void calculatePriorty(){
        if(isDisabled){
            priorty += 30;
        }
        if (age > 65){
            priorty += age - 65;
        }
    }

    bool operator <(const Patient& p)const{
        return priorty < p.priorty;
    }

    void print(){
        cout << patientNo << endl;
        Human :: print();
        cout << priorty << endl;
    }
};

class registerPatient
{

    list<Patient> patientQueue;
    priority_queue<Patient> examinationQueue;
public:

    void registerQueue(Human& h){
        Patient p(patientQueue.size()+1,h);
        patientQueue.push_back(p);
        examinationQueue.push(p);
    }

    void printQueue(){
        if (patientQueue.empty())
        {
            cout << "There is no patient!";
        }
        else
        {
            list<Patient>::iterator iter = patientQueue.begin();
            while (iter != patientQueue.end())
            {
                Patient patient = *iter;
                iter++;
                patient.print();
            }
            cout << endl;
        }
        
        
    }


};



int main() {
    
    Human alper = Human("alper",22,0);
    Human mahmut = Human("mahmut",72,0);
    Human selen = Human("selen",32,1);

    registerPatient reception;

    reception.registerQueue(alper);
    reception.registerQueue(mahmut);
    reception.registerQueue(selen);

    reception.printQueue();


    return 0;
}


