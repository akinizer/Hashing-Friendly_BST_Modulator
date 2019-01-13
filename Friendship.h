/**
* Title : Balanced Search Trees and Hashing
* Description : Friendship linked list
*/

class Friendship{
///variables and functions
public:
    int name;
    string tag;
    int f_amount;
    Friendship*next;

    Friendship();
    Friendship(int name, const string&tag);
};

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
