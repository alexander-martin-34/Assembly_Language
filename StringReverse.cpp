#include <iostream>
using namespace std;

void ReverseIt(char* o, char* r)
{
    //o points to the first letter of the first name
    //r points to the first char of the output buffer,
    //where the reversed name will go
    //
    //make a copy of o into p1, so that it (p1) can be changed
    //without losing the original address
    
    char* p1 = o, *p2;

    //p1 points to the first char of the name.
    //increment it until it points to the null which
    //marks the end of the string

    while (*p1 != '\0') p1++;
    
    //p1 points to the end of the string.
    //decrement it until it points to a space which
    //should be 1 char before the start of the last name

    while (*p1 != ' ') p1--;

    //p1 now points to the space before the last name
    //make a copy of it (to p2).  I'll use p2 to mark 
    //the end of the second part of the name

    p2 = p1;

    //p1 still points to the space before the last name
    //increment is, so it point to the first char of the last name

    p1++;

    //p1 points to the first char of the last name
    //r points to the first char of the buffer where the
    //reversed name should go.
    //
    //copy chars from where p1 points (last name) to
    //where r points (output buffer), incrementing each as you go,
    //until we reach the end ('\0') of the original string 

    while (*p1 != '\0') *r++ = *p1++;

    //append a comma and space onto the output buffer, 
    //incrementing the r pointer as we go

    *r++ = ',';  *r++ = ' ';

    //o points to the first char of the original name
    //r points to the first empty char of the output buffer
    //p2 points to the last space in the original name
    //
    //copy chars from the start of the original name (o)
    //to where r points, incrementing o & r as we go,
    //until o reaches p2 (the last space)

    while (o != p2) (*r++ = *o++);

    //make sure the output buffer gets properly null terminated

    *r = '\0';
}

int main()
{
    char original[] = "Conan The Barbarian\0";
    char reversed[100];

    ReverseIt(original, reversed);

    cout << original << " reversed is " << reversed << endl;
}

