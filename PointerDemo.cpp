#include <iostream>

using namespace std;

int main()
{
    char name[] = "Rick Ster";
    char *p = name;

    while (*p != ' ')
        p++;

    char *pspace = p;
    p++;
    cout << p;
    p = name;

    while (p != pspace)
        cout << *p++;

    return 0;
}
