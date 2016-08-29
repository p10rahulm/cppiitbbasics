//************************************************************************************//
/*Example.
#id Name     Friends_id
0   Avik     {1,2}
1   Barath   {2,3,4,5,6}
2   chetty   {4,5,6,7,8}
3   Dinash   {6,7,8,9,10,11,12,13,14}

Input list= { 
            struct{0,{1,2}}, 
            struct{1,{2,3,4,5,6}}, 
            struct{2,{4,5,6,7,8}},
            struct{3,{6,7,8,9,10,11,12,13,14}} 
            }
            
1. Mutual friends between chetty(2) and Barath(1) -> {4,5,6} so result should be 3
2. Uniqe friends of Avik (0) -> {1} so the answer should be 1
3. Strangers to Avik(1)
    - Direct friends {1,2}
    - Friends of friends (1 level) {3,4,5,6,7,8}
    - So, not strangers {1,2,3,4,5,6,7,8}
    - Strangers - { 9,10,11,12,13,14} so the answer should be 6. 
    Note : since Dinash (3) is not a direct friend of Avik(0), but friend through 
    Barath(1). So, friends of Dinash(3) are not friends of Avik(0)
    
//----------------Do not uncommand or recreate struct fbUser------------------------------------------//
//Structure for facebook users, each hase fb unique id -> userID and list of
//friends -> friends
struct fbUser{
    int userID;
    list<int> friends;
};
//------------------------------------------------------------------------------//
    
*/
//************************************************************************************//


//List of Headers
#include<iostream>
#include "header.h"
#include <list>
using namespace std;


//------------------------------------------------------------------------------//


//    **Spcace to add you own functions**           //









//------------------------------------------------------------------------------//
//1. Mutual friends between chetty(2) and Barath(1) -> {4,5,6} so result should be 3
//---------------------------------------------------------------------------------//
int find_mutual_friends(int person1_id,int person2_id, list<fbUser> list_of_fbusers)
{
    int mutual_friends=0;
    //-----------------------------------------//
    //Please write your code here
    list<fbUser>::const_iterator ci;
    list<int> friendsof1, friendsof2;
    for (ci = list_of_fbusers.begin(); ci != list_of_fbusers.end(); ++ci) {
        std::cout << "hi" << ci->userID << " ";
        if (ci->userID == person1_id) {
            friendsof1 = ci->friends;
        }
        if (ci->userID == person2_id) {
            friendsof2 = ci->friends;
        }
    }
    list<int>::const_iterator fi;
    list<int>::const_iterator fj;
    for (fi = friendsof1.begin(); fi != friendsof1.end(); ++fi) {
        for (fj=friendsof2.begin();fj !=friendsof2.end();++fj){
            if (*fi==*fj){
                mutual_friends++;
            }
        }
        
    }
    
    //-----------------------------------------//
    return mutual_friends;
}



//---------------------------------------------------------------------------------//
//2, Uniqe friends of Avik (0) -> {1} so the answer should be 1
//---------------------------------------------------------------------------------//
int find_uniq_friends(int person_id, list<fbUser> list_of_fbusers)
{
    int uniq_friends=0;
    //-----------------------------------------//
    //Please write your code here
    list<fbUser>::const_iterator ci;
    list<int> friendsof1, notfriendsof1;
    for (ci = list_of_fbusers.begin();ci!=list_of_fbusers.end();++ci) {
        if (ci->userID==person_id){
            friendsof1 = ci->friends;
        }
        else {
            if (notfriendsof1.size() ==0){
                notfriendsof1 = ci->friends;
            }
            else {
                notfriendsof1.insert(notfriendsof1.end(), ci->friends.begin(),ci->friends.end());
            }
            
        }
        
    }
    list<int>::const_iterator fi,fj;
    for (fi=friendsof1.begin();fi!=friendsof1.end();++fi){
        uniq_friends++;
        for(fj=notfriendsof1.begin();fj!=notfriendsof1.end();++fj){
            if (*fi==*fj){
                uniq_friends--;
                break;
            }
        }
        
    }
    
    
    //-----------------------------------------//
    return uniq_friends;
}


//------------------------------------------------------------------------------//
/*3. Strangers to Avik(1)
    - Direct friends {1,2}
    - Friends of friends (1 level) {3,4,5,6,7,8}
    - So, not strangers {1,2,3,4,5,6,7,8}
    - Strangers - { 9,10,11,12,13,14} so the answer should be 6. 
    Note : since Dinash (3) is not a direct friend of Avik(0), but friend through 
    Barath(1). So, friends of Dinash(3) are not friends of Avik(0)
*/
//------------------------------------------------------------------------------//
//Funciton to find the number of strangers
int find_strangers(int person_id, list<fbUser> list_of_fbusers)
{
    int strangers=0;
    //-----------------------------------------//
    //Please write your code here
    list<fbUser>::const_iterator ci;
    list<int> friendsof1, friendsoffriends1,allinlist,uniqall,uniqfof;
    allinlist.push_back(person_id);
    
    for (ci = list_of_fbusers.begin();ci!=list_of_fbusers.end();++ci) {
        allinlist.push_back(ci->userID);
        allinlist.insert(allinlist.end(),ci->friends.begin(),ci->friends.end());
        if (ci->userID==person_id){
            friendsof1 = ci->friends;
            friendsoffriends1 = ci->friends;
        }
    }
    list<int>::const_iterator fi;
    for (ci = list_of_fbusers.begin();ci!=list_of_fbusers.end();++ci) {
        for(fi=friendsof1.begin();fi!=friendsof1.end();++fi){
            if (ci->userID== *fi){
                friendsoffriends1.insert(friendsoffriends1.end(),ci->friends.begin(),ci->friends.end());
            }    
        }
    }
    friendsoffriends1.push_back(person_id);
    cout << "allinlist size" << allinlist.size()<<endl;
    allinlist.sort();
    allinlist.unique();
    friendsoffriends1.sort();
    friendsoffriends1.unique();
    
    cout << "allinlist size after uniq" << allinlist.size()<<endl;
    //uniqall = allinlist.unique();
    //uniqfof = friendsoffriends1.unique();
    
    strangers = allinlist.size() - friendsoffriends1.size();
    
    //-----------------------------------------//
    return strangers;
}
//------------------------------------------------------------------------------//