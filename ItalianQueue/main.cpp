#include <iostream>
#include <stdexcept>

#include <ItalianQueue_V1.h>
#include <ItalianQueue_V2.h>

using namespace std;

void run_italian_queue(ItalianQueueV1<string>* pq){
    
    cout << *pq << endl;

        //ItalianQueue:
        //
        // _head: NULL
        // _tail: NULL
        // tails_: {
        // }

    pq->enqueue("a","x"); // "a" is the element,"x" is the group
    cout << *pq << endl;

        // ItalianQueue: a
        // x
        // _head: Node(a,x)
        // _tail: Node(a,x)
        // tails_: {
        // x : Node(a,x)
        // }

    pq->enqueue("c","y"); // "c" belongs to new group "y", goes to the end of the queue
    cout << *pq << endl;

        // ItalianQueue: a->c
        // x y
        // _head: Node(a,x)
        // _tail: Node(c,y)
        // tails_: {
        // y : Node(c,y),
        // x : Node(a,x)
        // }

    pq->enqueue("d","y"); // "d" belongs to existing group "y", goes to the end of the group
    cout << *pq << endl;

        // ItalianQueue: a->c->d
        // x y y
        // _head: Node(a,x)
        // _tail: Node(d,y)
        // tails_: {
        // y : Node(d,y),
        // x : Node(a,x)
        // }
    
    pq->enqueue("b","x"); // "b" belongs to existing group "x", goes to the end of the group
    cout << *pq << endl;

        // ItalianQueue: a->b->c->d
        // x x y y
        // _head: Node(a,x)
        // _tail: Node(d,y)
        // tails_: {
        // y : Node(d,y),
        // x : Node(b,x)
        // }

    pq->enqueue("f","z"); // "f" belongs to new group, goes to the end of the queue
    cout << *pq << endl;

        // ItalianQueue: a->b->c->d->f
        // x x y y z
        // _head: Node(a,x)
        // _tail: Node(f,z)
        // tails_: {
        // z : Node(f,z),
        // y : Node(d,y),
        // x : Node(b,x)
        // }

    pq->enqueue("e","y"); // "e" belongs to an existing group "y", goes to the end of the group
    cout << *pq << endl;

        // ItalianQueue: a->b->c->d->e->f
        // x x y y y z
        // _head: Node(a,x)
        // _tail: Node(f,z)
        // tails_: {
        // z : Node(f,z),
        // y : Node(e,y),
        // x : Node(b,x)
        // }

    cout << "pq->tail(): " << pq->tail() << endl; // f
    cout << "pq->tail_group(): " << pq->tail_group() << endl; // z
    cout << "pq->top(): " << pq->top() << endl; // a
    cout << "pq->top_group(): " << pq->top_group() << endl; // x
    cout << "pq->size(): " << pq->size() << endl; // 6
    pq->enqueue("g","z"); // "g" belongs to an existing group "z", goes to the end of the group
    cout << *pq << endl;

        // ItalianQueue: a->b->c->d->e->f->g
        // x x y y y z z
        // _head: Node(a,x)
        // _tail: Node(g,z)
        // tails_: {
        // z : Node(g,z),
        // y : Node(e,y),
        // x : Node(b,x)
        // }

    pq->enqueue("h","z"); // "h" belongs to an existing group "z", goes to the end of the group
    cout << *pq << endl;

        // ItalianQueue: a->b->c->d->e->f->g->h
        // x x y y y z z z
        // _head: Node(a,x)
        // _tail: Node(h,z)
        // tails_: {
        // z : Node(h,z),
        // y : Node(e,y),
        // x : Node(b,x)
        // }

    pq->enqueue("h","z"); // 'h' belongs to an existing group 'z', goes at the end of the group
    cout << *pq << endl;

        // ItalianQueue: a->b->c->d->e->f->g->h->h
        // x x y y y z z z z
        // head_: Node(a,x)
        // tail_: Node(h,z)
        // tails_: {
        // z : Node(h,z),
        // y : Node(e,y),
        // x : Node(b,x)
        // }
        // Dequeue is always from the head, without taking in consideration the group:

    pq->dequeue();

        // "a"

    cout << *pq << endl;

        // ItalianQueue: b->c->d->e->f->g->h->h
        // x y y y z z z z
        // head_: Node(b,x)
        // tail_: Node(h,z)
        // tails_: {
        // z : Node(h,z),
        // y : Node(e,y),
        // x : Node(b,x)
        // }

    pq->dequeue();

        // "b"

    cout << *pq << endl;

        // ItalianQueue: c->d->e->f->g->h->h
        // y y y z z z z
        // head_: Node(c,y)
        // tail_: Node(h,z)
        // tails_: {
        // z : Node(h,z),
        // y : Node(e,y)
        // }

    pq->dequeue();

        // "c"

    cout << *pq << endl;

        // ItalianQueue: d->e->f->g->h->h
        // y y z z z z
        // head_: Node(d,y)
        // tail_: Node(h,z)
        // tails_: {
        // z : Node(h,z),
        // y : Node(e,y)
        // }
        // DEBUG: Queue destructor
        // DEBUG: Node(d,y) destructor
        // DEBUG: Node(e,y) destructor
        // DEBUG: Node(f,z) destructor
        // DEBUG: Node(g,z) destructor
        // DEBUG: Node(h,z) destructor
        // DEBUG: Node(h,z) destructor
}

int main() {
    cout << "---- ItalianQueueV1" << endl;
    ItalianQueueV1<string> q1 = ItalianQueueV1<string>();
    run_italian_queue(&q1);

    cout << "---- ItalianQueueV2" << endl;
    ItalianQueueV2<string> q2 = ItalianQueueV2<string>();
    run_italian_queue(&q2);
}