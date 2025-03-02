# ccurse

Simple program that "curses" code written in C-family programming languages.

## Example

### test.cc

```c++
#include <iostream>

using namespace std;

int main() {
    int number;
    if (cin >> number) {
        if (number == 42) {
            cout << "correct" << endl;
        }
        else {
            cout << "nope" << endl;
        }
    }
    else {
        cout << "you didn't even try" << endl;
    }
    return 42;
}
```

### test.cursed.cc

`./ccurse < test.cc > test.cursed.cc`

```c++
#include <iostream>                           

using namespace std                           ;

int main()                                    {
    int number                                ;
    if (cin >> number)                        {
        if (number == 42)                     {
            cout << "correct" << endl         ;
                                              }
        else                                  {
            cout << "nope" << endl            ;
                                              }
                                              }
    else                                      {
        cout << "you didn't even try" << endl ;
                                              }
    return 42                                 ;
                                              }
```