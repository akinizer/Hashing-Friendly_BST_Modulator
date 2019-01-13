/**
* Title : Balanced Search Trees and Hashing
* Description : Friendship linked list contents
*/

#include "Friendship.h"

///constructors
Friendship::Friendship(){
    f_amount=0;
    name=0;
    tag="";
}

Friendship::Friendship(int newName, const string&newTag){
    f_amount=0;
    name = newName;
    tag = newTag;
}
