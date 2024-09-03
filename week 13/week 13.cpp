// week 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyStack.hpp"
#include "Queue.hpp"
int main()
{
    /*MyStack<int, 10> s;
    s.push(3);
    s.push(4);
    s.push(5);
    std::cout << s.peek()<<std::endl;
    s.pop();
    std::cout << s.peek()<<std::endl;
    s.pop();
    s.pop();
    std::cout << s.isFull() << std::endl;
    std::cout << s.isEmpty() << std::endl;*/

    MyQueue<int> q;
    q.push(4);
    q.push(3);
    std::cout << q.peek() << std::endl;
    q.push(5);
    q.push(6);
    q.pop();
    std::cout << q.peek() << std::endl;
    q.push(7);
    q.push(8);
    std::cout << q.peek() << std::endl;

    MyQueue<int> q2(q);
    std::cout << q2.peek() << std::endl;

    q.pop();
    std::cout << q.peek() << std::endl;
    q.pop();
    std::cout << q.peek() << std::endl;
    q.pop();
    std::cout << q.peek() << std::endl;
    q.pop();
    std::cout << q.peek() << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
