#include <iostream>
#include <string>//for using string also
using namespace std;
int main(){
    //when using char
    char firstName[20], lastName[20];
    //when using string
    string name;
    //cout<<"Enter your first name: ";
    //cin>>firstName;
    //cout<<"Enter your last name: ";
    //cin>>lastName;
    //cout<<"Your name is "<<firstName<<" "<<lastName;//
    cout<<"Enter your name: ";
    getline(cin, name);
    cout<<"Your name is "<<name<<endl;//string output
    return 0;
}
