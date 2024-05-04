#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include<fstream>
#include<sstream>
#include<string>
#include<list>
struct Variable          //our variable

{
    string name;
    string datatype;
    string value;

};
struct node //node to carry the variable
{
    Variable data;
    node* next;
    node(Variable val):data(val),next(nullptr){}
};
class stackv {    //Linked list stack
public:
    node *top;

    stackv() {
        top = NULL;
    }

    bool isempty() {
        return top == NULL;
    }

    void push(Variable x) {
        node *n = new node(x);
        n->data = x;
        n->next = top;
        top = n;


    }

    Variable Top() {
        if (top != nullptr)
            return top->data;

    }

    Variable pop() {
        Variable x;
        if (isempty()) {

        } else {
            node *temp;
            temp = top;
            top = top->next;
            x = temp->data;
            delete temp;
            return x;

        }
    }
    void display() {  //display our stack
        node *curr = top;
        cout << "Stack Contents: \n";
        while (curr != nullptr) {
            cout << "Name: " << curr->data.name
                 << " , Type: " << curr->data.datatype
                 << " , Value: " << curr->data.value << ";" << endl;
                 curr=curr->next;
        }
    }
};
void ProcessLine(string line,stackv& s) // to read each line
{
    string name;
    string value;

    stackv st;
    string datatype;
    stringstream ss(line);  // make a string to store the lines and read it  by this stringstream ss
    getline(ss,datatype,' ');
    getline(ss,name,'=');
    getline(ss,value,';');// ss is the important things

    Variable v;
    /*if(line=="int main()"|| line=="{" || line=="}")
    {
        return;
    }*/
    if (datatype == "int" || datatype == "double" || datatype == "char" ||
        datatype == "float") // if the datatype string have any things of those strings do what in the condition
    { //this mean that this a decleration not a update for the the variable
        v.datatype = datatype;
        v.name = name;
        v.value = value;
        s.push(v);
        s.display();
        cout << endl;

    } else //else is mean that the datatype doesnot have a datatype which mean that the line have only a update for the variable not a decleration
    {
        stringstream ss1(datatype); //so we will make a stringstream to carry all the datatype string and categorize it in different types

        string name;
        string value;
        //string ass;
       // string  semi;
        getline(ss,name,'=');
        getline(ss,value,';');// ss is the important things
// the ss1 will read the datatype and divide it in the types we intialize up
        while (!s.isempty())
            //search method we use another stack to store the variables while searching in our stack
        {
            if (s.top->data.name == name) {
                s.top->data.value = value;
                break;
            } else {
                st.push(s.top->data);
                s.pop();
            }
        }
        while (!st.isempty()) {
            s.push(st.top->data);
            st.pop();
        }

        s.display();
    }
}


 void ProcessFile(const string& filename) //to open the file
 { ifstream input(filename);
     string line;
     stackv s;
     while(getline(input,line))
     {
         if (line == "int main()" ||line=="{"||line=="}") // to avoid any other strings not include what we want
         { continue;}
         if(line == "return 0") //to stop
         {
           cout<<"reached return 0\n";
             s.display();
           while(!s.isempty())
           {
              s.pop();
           }

           break;

         }
         ProcessLine(line,s); // to call the function in the will loop to read each line

     }
     input.close();
 }


int main()
{
    ProcessFile("code.txt");

}