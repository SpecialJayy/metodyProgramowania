#include <iosfwd>
#include <iostream>
#include <vector>
#include <string>
#include "../libraries/libFile.h"
#include "../libraries/LinkedList.h"
using namespace std;

struct Expr {
    string str;
    char main_op;
};

int getPriority(const char op) {
    if (op == '=') return 0;
    if (op == '<' || op == '>') return 1;
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/' || op == '%') return 3;
    if (op == '^') return 4;
    if (op == '~') return 5;
    return -1;
}

bool isRightAssociative(char op) {
    return op == '=' || op == '^' || op == '~';
}

string cleanString(const string &s, const bool isInf) {
    string cleaned;
    for (char c : s) {
        if ((c >= 'a' && c <= 'z') || c == '=' || c == '<' || c == '>' ||
            c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
            c == '^' || c == '~') {
            cleaned += c;
        } else if (isInf && (c == '(' || c == ')')) {
            cleaned += c;
        }
    }
    return cleaned;
}

bool validateINF(const string &s) {
    if (s.empty()) return false;
    int balance = 0;
    bool expectOperand = true;
    for (char c : s) {
        if (c == '(') {
            if (!expectOperand) return false;
            balance++;
        } else if (c == ')') {
            if (expectOperand) return false;
            balance--;
            if (balance < 0) return false;
        } else if (c >= 'a' && c <= 'z') {
            if (!expectOperand) return false;
            expectOperand = false;
        } else if (c == '~') {
            if (!expectOperand) return false;
        } else {
            if (expectOperand) return false;
            expectOperand = true;
        }
    }
    return !expectOperand && balance == 0;
}

bool validateONP(const string &s) {
    if (s.empty()) return false;
    int stack_size = 0;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            stack_size++;
        } else if (c == '~') {
            if (stack_size < 1) return false;
        } else {
            if (stack_size < 2) return false;
            stack_size--;
        }
    }
    return stack_size == 1;
}

string infToRpn(const string &expr) {
    string output;
    LinkedList<char> stack;
    for (char c : expr) {
        if (c >= 'a' && c <= 'z') {
            output += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                output += stack.top();
                stack.pop();
            }
            if (!stack.empty()) stack.pop();
        } else {
            while (!stack.empty() && stack.top() != '(') {
                char top = stack.top();
                if (getPriority(top) > getPriority(c) ||
                    (getPriority(top) == getPriority(c) && !isRightAssociative(c))) {
                    output += top;
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        output += stack.top();
        stack.pop();
    }
    return output;
}

string rpnToInf(const string &expr) {
    LinkedList<Expr> stack;
    for (char c : expr) {
        if (c >= 'a' && c <= 'z') {
            stack.push({string(1, c), 0});
        } else if (c == '~') {
            Expr A = stack.top();
            stack.pop();
            bool parens = (A.main_op != 0 && getPriority(A.main_op) < getPriority('~'));
            string s = "~" + (parens ? "(" + A.str + ")" : A.str);
            stack.push({s, '~'});
        } else {
            Expr R = stack.top();
            stack.pop();
            Expr L = stack.top();
            stack.pop();

            bool pL = false, pR = false;
            if (L.main_op != 0) {
                if (getPriority(L.main_op) < getPriority(c)) pL = true;
                if (getPriority(L.main_op) == getPriority(c) && isRightAssociative(c)) pL = true;
            }
            if (R.main_op != 0) {
                if (getPriority(R.main_op) < getPriority(c)) pR = true;
                if (getPriority(R.main_op) == getPriority(c) && !isRightAssociative(c)) pR = true;
            }

            string sL = pL ? "(" + L.str + ")" : L.str;
            string sR = pR ? "(" + R.str + ")" : R.str;
            stack.push({sL + string(1, c) + sR, c});
        }
    }
    return stack.top().str;
}

void processExpressions(fstream& file) {
    file.clear();
    file.seekg(0, ios::beg);

    int lines;
    if (!(file >> lines)) return;
    string dummy;
    getline(file, dummy);

    for (int i = 0; i < lines; i++) {
        string line;
        getline(file, line);

        size_t pos = line.find(':');
        if (pos == string::npos) continue;

        string type = line.substr(0, pos);
        string raw_expr = line.substr(pos + 1);

        if (type.find("INF") != string::npos) {
            string cleaned = cleanString(raw_expr, true);
            if (validateINF(cleaned)) {
                cout << "ONP: " << infToRpn(cleaned) << endl;
            } else {
                cout << "ONP: error" << endl;
            }
        } else if (type.find("ONP") != string::npos) {
            string cleaned = cleanString(raw_expr, false);
            if (validateONP(cleaned)) {
                cout << "INF: " << rpnToInf(cleaned) << endl;
            } else {
                cout << "INF: error" << endl;
            }
        }
    }
}

int main() {
    fstream file = openFile("../assets/z4/input.txt");
    processExpressions(file);
    return 0;
}