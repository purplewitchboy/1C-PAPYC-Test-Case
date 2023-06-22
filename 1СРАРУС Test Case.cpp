Задача 1

//Есть строка арифметического выражения, в которой содержатся открывающие “(” и закрывающие скобки “)”. 
//Необходимо написать функцию, которая проверит корректность расстановки скобок. 
//При этом скобки - проверяется только последовательность расставления скобок, 
//а операторы и операнды при проверке не учитываются

//Решение:

#include <iostream>
#include <stack>   // используем стек для хранения открывающих скобок 
#include <string>


string сheckСorrectness(string S) {
    stack<char> st;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(' ) {
            st.push(S[i]);
        } 
        else if (S[i] == ')' ) {
            if (st.empty()) {
                return "неправильно";
            } 
            else if ((S[i] == ')' && st.top() == '('){
                st.pop();
            } 
            else {
                return "неправильно";
            }

    if (st.empty()) {
        return "правильно";
    } else {
        return "неправильно";
    }


    int main() {
    string S;
    getline(cin, S);
    cout << checkBrackets(S) << endl;
    return 0;
}

Задача 2

//В учебном заведении в конце каждого года обучения подводят итоги.
//В частности, составляют списки ребят, которые учились в этом году на отлично. 
//Нужно написать функцию, которая поможет преподавателям вычислить перечень ребят,
//которые “скатились” - в прошлом году были отличниками, а в текущем не попали в этот список.
//Запрещено использовать предоставляемые языком программирования функции групповой обработки элементов массивов 
//(например, сортировка, объединение, копирование).

//Входные параметры:
//- A - отличники прошлого года;
// - Nа - количество элементов в массиве A;
// - B - отличники текущего года;
// - Nb - количество элементов в массиве B.
//Результат функции:
//- Массив “скатившихся” ребят.

//Решение:

#include <iostream>

using namespace std;

void findSlackers(int A[], int Na, int B[], int Nb) {
    bool found;
    for (int i = 0; i < Na; i++) {
        found = false;
        for (int j = 0; j < Nb; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << A[i] << " ";
        }
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int Na = 5;
    int B[] = {2, 4, 6, 8};
    int Nb = 4;
    findSlackers(A, Na, B, Nb);
    return 0;
}



Задача 3 

//Есть односвязный список символов. Вывести его элементы задом наперед за один проход.

//Решение: 

#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* next;
};

void printList(Node* head) {
    if (head == NULL) {
        return;
    }
    printList(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = new Node();
    head->data = 'a';
    head->next = new Node();
    head->next->data = 'b';
    head->next->next = new Node();
    head->next->next->data = 'c';
    head->next->next->next = NULL;

    cout << "Original list: ";
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\nReversed list: ";
    printList(head);

    return 0;
}