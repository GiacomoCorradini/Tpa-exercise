#include <iostream>
#include <Company.h>

using std::cout;
using std::endl;

int main(){

    Company c;
    cout << c << endl;

        // Company:
        // name rank tasks

    c.add_employee('x',9);
    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 []

    c.add_employee('z',2);
    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 []
        // z 2 []

    c.add_employee('y',6);
    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 []
        // y 6 []
        // z 2 []

    c.add_task('a',3,'x');
    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 [('a', 3)]
        // y 6 []
        // z 2 []

    c.add_task('b',5,'x');
    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 [('a', 3), ('b', 5)]
        // y 6 []
        // z 2 []

    c.add_task('c',12,'x');
    c.add_task('d',1,'x');
    c.add_task('e',8,'y');
    c.add_task('f',2,'y');
    c.add_task('g',8,'y');
    c.add_task('h',10,'z');
    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 [('a', 3), ('b', 5), ('c', 12), ('d', 1)]
        // y 6 [('e', 8), ('f', 2), ('g', 8)]
        // z 2 [('h', 10)]
/*
    cout << vec2str(c.work()) << endl;

        // DEBUG: Employee x gives task ('a', 3) to employee y
        // DEBUG: Employee y gives task ('e', 8) to employee x
        // DEBUG: Employee z gives task ('h', 10) to employee y
        // DEBUG: Total performed work this step: []
        // []

    cout << c << endl;
    >> Company:
    >> name rank tasks
    >> x 9 [('b', 5), ('c', 12), ('d', 1), ('e', 8)]
    >> y 6 [('f', 2), ('g', 8), ('a', 3), ('h', 10)]
    >> z 2 []
    cout << vec2str(c.work()) << endl;

        // DEBUG: Employee x gives task ('b', 5) to employee y
        // DEBUG: Employee y gives task ('f', 2) to employee z
        // DEBUG: Employee z executes task ('f', 2)
        // DEBUG: Total performed work this step: ['f']
        // ['f']

    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 [('c', 12), ('d', 1), ('e', 8)]
        // y 6 [('g', 8), ('a', 3), ('h', 10), ('b', 5)]
        // z 2 []

    cout << vec2str(c.work()) << endl;

        // DEBUG: Employee x executes task ('c', 12)
        // DEBUG: Employee y gives task ('g', 8) to employee x
        // DEBUG: Total performed work this step: ['c']
        // ['c']

    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 [('d', 1), ('e', 8), ('g', 8)]
        // y 6 [('a', 3), ('h', 10), ('b', 5)]
        // z 2 []

    cout << vec2str(c.work()) << endl;

        // DEBUG: Employee x gives task ('d', 1) to employee y
        // DEBUG: Employee y executes task ('a', 3)
        // DEBUG: Total performed work this step: ['a']
        // ['a']

    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 [('e', 8), ('g', 8)]
        // y 6 [('h', 10), ('b', 5), ('d', 1)]
        // z 2 []

    cout << vec2str(c.work()) << endl;

        // DEBUG: Employee x executes task ('e', 8)
        // DEBUG: Employee y gives task ('h', 10) to employee x
        // DEBUG: Total performed work this step: ['e']
        // ['e']

    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 [('g', 8), ('h', 10)]
        // y 6 [('b', 5), ('d', 1)]
        // z 2 []

    cout << vec2str(c.work()) << endl;

        // DEBUG: Employee x executes task ('g', 8)
        // DEBUG: Employee y executes task ('b', 5)
        // DEBUG: Total performed work this step: ['g', 'b']
        // ['g', 'b']

    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 [('h', 10)]
        // y 6 [('d', 1)]
        // z 2 []

    cout << vec2str(c.work()) << endl;

        // DEBUG: Employee x executes task ('h', 10)
        // DEBUG: Employee y gives task ('d', 1) to employee z
        // DEBUG: Employee z executes task ('d', 1)
        // DEBUG: Total performed work this step: ['h', 'd']
        // ['h', 'd']

    cout << c << endl;

        // Company:
        // name rank tasks
        // x 9 []
        // y 6 []
        // z 2 []
*/
}