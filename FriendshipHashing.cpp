
/**
* Title : Balanced Search Trees and Hashing
* Description : Hashing for Friendship linked listcontents
*/

#include "FriendshipHashing.h"

///constructors

FriendshipHashing::FriendshipHashing(){
    boss = NULL;

}

///insert
void FriendshipHashing::insert(int str, const string&key){
    if(boss==NULL){
        boss = new Friendship(str, key);
        boss->next=NULL;

        return;
    }
    else{
        if(available(key)){
            cout<<"this friendship already exists"<<endl;
            return;
        }
        for(Friendship*cur=boss;cur!=NULL;cur=cur->next){
            if(cur->next==NULL){
                cur->next=new Friendship(str, key);
                cur->next->next=NULL;
                ///cout<<"done"<<endl;
                return;
            }
        }
    }
}
///find index
Friendship*FriendshipHashing::findAt(int index){

    if(boss==NULL) {
        cout<<"no person available"<<endl;
        return NULL;
    }
    else{
        int i = 0;
        for(Friendship*cur=boss;cur!=NULL;cur=cur->next){
            if(i == index) return cur;
            i++;
        }
     }

    return NULL;
}

///delete friend
void FriendshipHashing::unfriend(const string&key){
    if(boss==NULL){
        cout<<"friendship does not exist"<<endl;
        return;
    }
    else{
        if(available(key)){
            if(boss->tag==key){
                delete boss;
                boss = NULL;
                return;
            }

            for(int i=0; findAt(i)!=NULL; i++){
                if(findAt(i+1)->tag==key){
                    Friendship*temp=findAt(i+1);
                    findAt(i)->next=temp->next;
                    delete temp;
                    temp = NULL;
                    return;
                }
            }
        }
    }

}

///hashing
int FriendshipHashing::hash (const string &key, int tableSize){

    this->tableSize=tableSize;
   int hashVal = 0;

   for (unsigned int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];
   hashVal %=tableSize;
   if (hashVal < 0)   /* in case overflows occurs */
        hashVal += tableSize;

    insert(hashVal, key);

   return hashVal;
}

///hash info
void FriendshipHashing::printhashtable(){


     int count = 0;

    if(boss==NULL) cout<< "\nempty" <<endl;
    else{
        cout<<"\nhere are the elements with the same hash value: "<<endl;
        for(Friendship*cur=boss;cur!=NULL;cur=cur->next){

            cout<<cur->name<<", ";
            count++;

        }
        cout<<"amount: "<<count<<endl;
     }
}

///availability
bool FriendshipHashing::available(string name){
    if(boss==NULL) return false;
    for(Friendship*cur = boss;cur!=NULL;cur= cur->next){
        if(cur->tag == name) return true;
    }
    return false;

}

///find key
Friendship*FriendshipHashing::find(string name){

    if(boss==NULL || name=="") {
        cout<<"no person available"<<endl;
        return NULL;
    }
    else{
        for(Friendship*cur=boss;cur!=NULL;cur=cur->next){
            if(cur->tag==name)
                return cur;

        }
     }

    return NULL;
}
