#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// 定義 Stack 的節點結構
struct Node {
    char data;  // 存儲字符 (運算子或括號)
    Node* next; // 指向下一個節點
};

// 使用 linked list 實作 Stack
class Stack {
private:
    Node* top; // 指向堆疊頂端
public:
    Stack() { top = nullptr; } // 初始化堆疊

    // Push 操作：將元素放入堆疊
    void push(char ch) {
        Node* newNode = new Node; // 創建新節點
        newNode->data = ch;       // 存入數據
        newNode->next = top;      // 讓新節點指向目前的頂端
        top = newNode;            // 更新頂端指標
    }

    // Pop 操作：移除並回傳頂端元素
    char pop() {
        if (isEmpty()) return '\0'; // 若堆疊為空，回傳空字符
        char ch = top->data;         // 取得頂端元素
        Node* temp = top;            // 暫存頂端節點
        top = top->next;             // 移動頂端指標
        delete temp;                 // 釋放記憶體
        return ch;                   // 回傳彈出的元素
    }

    // Peek 操作：取得頂端元素但不移除
    char peek() {
        return (top ? top->data : '\0');
    }

    // 判斷堆疊是否為空
    bool isEmpty() {
        return top == nullptr;
    }
};

// 判斷運算子(加減乘除) 的優先順序
int precedence(char op) {
    if (op == '+' || op == '-') return 1; // set precedence of + and - to 1
    if (op == '/' || op == '*') return 2; // precedence of * and / to 2
    return 0; // precedence of anything else to 0
}

// 將中序表達式 (infix) 轉換為後序表達式 (postfix)
void InfixToPostfix(const char* infix, char* postfix) {
    int j = 0;
    Stack s; // create stack
    for (int i = 0; infix[i] != '\0'; i++) { // loop through all of infix
        char ch = infix[i]; // get current character
        int _ascii = int(ch); // get current character's decimal value
        if ((_ascii <= 57 && _ascii >= 48) || (_ascii <= 90 && _ascii >= 65) || (_ascii <= 122 && _ascii >= 97)) { // determine if current character is 0-9, A-Z or a-z
            postfix[j] = ch; // put directly into postfix
            j++;
        }else if (ch == '(') { // put ( directly into stack
            s.push(ch);
        }else if (ch == ')') { 
            while (!s.isEmpty() && s.peek() != '(') { // pop until (
                postfix[j] = s.pop(); // put popped into postfix
                j++;
            }
            s.pop(); // pop ( without putting into postfix
        }else { //  process +-*/
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) { // check precedence
                postfix[j] = s.pop(); // pop into postfix
                j++;
            }
            s.push(ch); // push current into stack
        }
    }
    // pop all remaining characters in stack
    while (!s.isEmpty()) {
        postfix[j] = s.pop();
        j++;
    }
    postfix[j] = '\0'; // end postfix
}

int main() {
    char infix[100], postfix[100];
    cout << "Enter an Infix expression: ";
    cin >> infix; // 輸入中序表達式

    InfixToPostfix(infix, postfix); // 轉換為後序表達式
    cout << "Postfix expression: " << postfix << endl; // 輸出後序表達式

    return 0;
}
