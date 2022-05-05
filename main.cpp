#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MAXQUEUE=5;
int MAXSPECIALIZATION=20;
class Hospital{
public:
    struct Patient {
        string name;
        int specialization;
        bool statis;
        Patient(string&name,int specialization,bool statis){
            this->name=name;
            this->specialization=specialization;
            this->statis=statis;
        }
    };
    vector<deque<Patient>>spec;
    Hospital(){
        deque<Patient>deque={};
        for (int i = 0; i < MAXSPECIALIZATION; ++i) {
            spec.push_back(deque);
        }
    }
    void addNewPatient() {
        string name;
        int specialization;
        bool stat;
        cout << "Enter specialization, name, states:";
        cin >> specialization >> name >> stat;
        if (spec[specialization-1].size()==MAXQUEUE){
            cout<<"Sorry,we can not add more patient for this specialization"<<endl;
            return;
        }
        Patient p(name,specialization,stat);
        if(stat)
            spec[specialization-1].push_front(p);
        else
            spec[specialization-1].push_back(p);
    }
    void printAllPatients(){
        int i = 0;
        for(auto&v:spec) {
            i++;
            if (v.empty())continue;
            cout << "There are " << v.size() <<" patients in specialization "<<i<<endl;
            for (Patient&x: v) {
                cout << x.name << " ";
                if (x.statis)
                    cout<<"urgent"<<endl;
                else
                    cout<<"regular"<<endl;
            }
        }
    }
    string getNextPatient(){
        int specialization;
        cout<<"Enter specialization: "<<endl;
        cin >> specialization;
        if (spec[specialization-1].empty())
            return "There is no patients";
        string name = spec[specialization-1].front().name;
        spec[specialization-1].pop_front();
        return name;
    }

};
int main() {
    int c;
    Hospital hospital;
    while (true){
        cout << "\nEnter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";
        cin >> c;
        if (c==1) {
            hospital.addNewPatient();
        } else if (c==2)
            hospital.printAllPatients();

        else if (c==3) {
            cout<<hospital.getNextPatient()<<" please go with the Doctor now"<<endl;
        }
        else if(c==4)
            break;
        else
            cout << "wrong input,try again" << endl;
    }
    return 0;
}
