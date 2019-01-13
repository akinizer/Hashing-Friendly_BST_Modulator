/**
* Title : Balanced Search Trees and Hashing
* Description : Hashing for Person linked list
*/
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;
class PersonHashing{
///private variables and functions
private:

    int tableSize;
    bool available(string name);

public:
///public variables and functions
    Person*boss;
    Person*find(string name);

    PersonHashing();
    void insert(int name, const string &key);
    int hash (const string &key, int tableSize);
    void printhashtable();

};

///***function contents***///

///default constructor
PersonHashing::PersonHashing(){
    boss = NULL;

}

///insertion operation
void PersonHashing::insert(int str, const string &key){
    ///if list is empty, add a node with contents
    if(boss==NULL){
        boss = new Person(str);
        boss->name = str;
        boss->nick = key;
        boss->next=NULL;

    }
    ///otherwise find the available slot in the hash and insert contents
    else{
        ///if already inserted
        if(available(key)){
            cout<<"this person exists"<<endl;
            return;
        }
        ///otherwise find an available hash slot and insert
        for(Person*cur=boss->next;;cur=cur->next){
            if(cur==NULL){
                cur=new Person(str);
                cur->name=str;
                cur->next=NULL;
                return;
            }
        }
    }
}

///hashing operation
int PersonHashing::hash (const string &key, int newSize){
    ///initial variables
    tableSize=newSize;
    int hashVal = 0;

    ///convert the hash value
    for (unsigned int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];

    hashVal %=tableSize;

    ///overflow situation, rearrange hash value
    if (hashVal < 0)
        hashVal += tableSize;

    ///insert the hashed value
    insert(hashVal, key);

    ///return the value
    return hashVal;
}

///print out the information for hash
void PersonHashing::printhashtable(){

     int count = 0;
    ///empty
    if(boss==NULL) cout<< "\nempty" <<endl;

    ///print
    else{
        cout<<"\nhere are the elements with the same hash value: "<<endl;
        for(Person*cur=boss;cur!=NULL;cur=cur->next){

            cout<<cur->name<<", ";
            count++;

        }
     cout<<"amount: "<<count<<endl;
     }
}

///if key is in table
bool PersonHashing::available(string name){
    for(Person*cur = boss;cur!=NULL;cur= cur->next){
        if(cur->nick==name) return true;
    }
    return false;

}

///find key's node
Person*PersonHashing::find(string name){

    if(boss==NULL) {
        cout<<"no person available"<<endl;
        return NULL;
    }
    else{
        for(Person*cur=boss;cur!=NULL;cur=cur->next){
            if(cur->nick==name)
                return cur;

        }
     }

    return NULL;
}



