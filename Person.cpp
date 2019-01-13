/**
* Title : Balanced Search Trees and Hashing
* Description : Person linked list contents
*/

#include "Person.h"

///default constructor
Person::Person(){

    name=0;
}
///main constructor
Person::Person(int newName){

    name = newName;
    head = NULL;
}
///add friend to person
void Person::addFriend(string followed){
    ///empty list
    if(head==NULL){
        head = new friendzone();
        head ->friendName = followed;
        head->nextFriend=NULL;
        f_amount++;
    }
    ///find place and insert the friend
    for(friendzone*cur = head; cur!=NULL; cur=cur->nextFriend){
        if(cur->friendName==followed) return; ///if already exists

        ///add friend
        if(cur == NULL){
            cur = new friendzone();
            cur->friendName = followed;
            f_amount++;
            cur->nextFriend=NULL;
            return;
        }
    }
}

///delete friend
void Person::unFriend(string followed){
    ///no friends
    if(head==NULL){
        cout<<"empty"<<endl;
        return;
    }

    ///delete operation
    for(friendzone*cur = head; cur!=NULL; cur=cur->nextFriend){
        if(cur->nextFriend!=NULL && cur->nextFriend->friendName==followed){
            friendzone*temp=cur->nextFriend;
            temp->nextFriend=cur->nextFriend->nextFriend;
            delete temp;
            temp = NULL;

        }
    }
}
///friendlist
void Person::friendList(){
    ///empty
    if(head==NULL) {
        cout<<"empty"<<endl;
        return;
    }
    ///search and print list
    for(friendzone*cur = head; cur!=NULL; cur=cur->nextFriend){
         cout<<cur->friendName<<" ";
    }
    cout<<endl;
}
