//passing by reference is using parameters
#include <iostream>
#include <string>
using namespace std;
struct student {//struct is the equivalent of class
string name;
int age;
student *what;
};
// creating a new temporary structure s with data of s1
void display1(student s) {
    cout << "Student Name " << s.name << endl;
    cout << "Student Age " << s.age << endl;
}
// creating a new temporary pointer s with data of s1
void display2(student *s) {
    
    cout << "Student Name " << s->name << endl;
    cout << "Student Age " << s->age << endl;
    
    //endl means \n
}
int main() {
    student s1, s2, *s3;
    s3 = new student;//creating anonymous structure sx and s3 pointing to it
    //note: to point to sx e.g using s2:  s2.what = s3
    s1.name ="Mamat";
    s1.age = 22;
    s2.name ="Minah";
    s2.age = 33;
    s3->name ="Joyah";//. is used for structures and -> is for pointers
    s3->age = 44;
    display1(s1);
    display1(s2);
    display2(s3);
    s1.what = &s2;
    s3->what = &s1;
    
    display2(s1.what);//displays s2 info bcuz s1(which pointed to s2) was passed to pointer s
    display2(s3->what);//displays s1 info bcuz s3(which pointed to s1) was passed to pointer s
    cout<<"END "<<s3->what->what->name<<endl;
    return 0;
}
