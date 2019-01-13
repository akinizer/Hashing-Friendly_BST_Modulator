/**
* Title : Balanced Search Trees and Hashing
* Description : Main function with input checking functions
*/

#include <iostream>
#include <string>
#include "PersonHashing.h"
#include "FriendshipHashing.h"
using namespace std;

///hashes
PersonHashing hashP;
FriendshipHashing hashF;

///input control system
void checkInput(string);

///repeat input reading till X is inserted
void loop(){
    string input="";
     while(input!="X"&&input!="x"){
        cout<<" \nEnter input: ";
        cin>>input;
        cout<<endl;
    }

}

///check a substring
bool check(string input, string str){
    return (input.find(str)>=0 && input.find(str)<input.length());
}

///index of a substring
size_t index(string input, string str){
    if(!check(input,str)) return 999;
    return input.find(str);
}

///input control system, decides which control operation of P, F, U, Q, L or X will be applied
void checkInput(string input, int size){
    ///variables
    string sub1="",sub2="";
    int hashNo=-1;

    ///input length condition
    if(input.length()<3){
        cout<<endl;
        return;
    }

    ///control operations

    ///add person
    else if(input.substr(0,2)=="P ") {

        sub1=input.substr(2);

        hashNo = hashP.hash(sub1, size);

        cout<<endl;

    }

    ///add friendship
    else if(input.substr(0,2)=="F "){
        ///get inputs, sub1, sub2
        sub1=input.substr(2);

        sub2=sub1.substr(sub1.find(" ")+1);

        sub1=input.substr(2, input.find(sub2)-3);

        ///hashing
        hashNo = hashF.hash(sub1 + sub2, size);

        ///check validity
        if(!hashP.find(sub1)) {
            cout<<endl;
            return;
        }

        hashP.find(sub1)->addFriend(sub2);

        cout<<endl;

    }
    ///listing
    else if(input.substr(0,2)=="L "){
        ///inputs
        sub1=input.substr(2);

        sub2=sub1.substr(sub1.find(" ")+1);

        sub1=input.substr(2, input.find(sub2)-3);

        ///validity
        if(hashP.boss==NULL) {
            cout<<"no people found"<<endl;
            return;
        }

        ///scan the list
        string str="";
        for(Friendship*cur = hashF.boss; cur!=NULL; cur=cur->next){
            if((cur->tag).find(sub1)==0){
               str = str + cur->tag + " ";
            }

        }

        ///validity2
        if(str.length()==0){
            cout<<"the list is empty"<<endl;
        }

        else cout<<str<<endl<<endl;

    }
    ///unfriending
    else if(input.substr(0,2)=="U "){
        ///inputs
        sub1=input.substr(2);

        sub2=sub1.substr(sub1.find(" ")+1);

        sub1=input.substr(2, input.find(sub2)-3);

        ///validity

        if(hashF.boss==NULL) {
            cout<<"forever alone"<<endl;
            return;
        }

        ///scanning to unfriend

        string key = sub1 + sub2;

        for(Friendship*cur=hashF.boss;cur!=NULL;cur=cur->next){
            if(key == cur->tag) {
                hashF.unfriend(key);
                cout<<endl;
                return;
            }
        }

        cout<<"friendship not found"<<endl<<endl;
    }

    ///ask friendship availablity
    else if(input.substr(0,2)=="Q "){

        ///inputs, validity, scan
        sub1=input.substr(2);

        sub2=sub1.substr(sub1.find(" ")+1);

        sub1=input.substr(2, input.find(sub2)-3);

        if(hashF.boss==NULL) {
            cout<<"no people found"<<endl;
            return;
        }

        string key = sub1 + sub2;
        if(hashF.find(key)!=NULL)cout<<"yes"<<endl;
        else cout<<"no"<<endl<<endl;
    }

    return;

}

///main function
int main(){

    ///initial values, ask to get input
    int tablesize=0;
    string entry="";

    cout<<"Table size: ";
    cin>>tablesize;

    cout<<"\nProgram: "<<endl;

    ///loop of program
    while(entry!="x" && entry!="X"){

        getline(cin, entry);            ///competible with input which contains space
        checkInput(entry, tablesize);   ///input control

    }

    ///print hash info
    hashP.printhashtable();
    hashF.printhashtable();

    cout << "\nEnd of program" << endl;
    return 0;
}
