#include <bits/stdc++.h> 
using namespace std; 
#define max 100000
  
int isOperator(char input) 
{ 
    switch (input) { 
    case '+': 
        return 1; 
    case '-': 
        return 1; 
    case '*': 
        return 1; 
    case '^': 
        return 1; 
    case '%': 
        return 1; 
    case '/': 
        return 1; 
    case '(': 
        return 1; 
    } 
    return 0; 
} 

int isOperand(char input) 
{ 
    if (input >= 65 && input <= 90 
        || input >= 97 && input <= 122) 
        return 1; 
    return 0; 
} 
  

int inPrec(char input) 
{ 
    switch (input) { 
    case '+': 
    case '-': 
        return 2; 
    case '*': 
    case '%': 
    case '/': 
        return 4; 
    case '^': 
        return 5; 
    case '(': 
        return 0; 
    } 
} 

int outPrec(char input) 
{ 
    switch (input) { 
    case '+': 
    case '-': 
        return 1; 
    case '*': 
    case '%': 
    case '/': 
        return 3; 
    case '^': 
        return 6; 
    case '(': 
        return 100; 
    } 
} 
  

void inToPost(char* input) 
{ 
    stack<char> s; 

    int i = 0; 
    while (input[i] != '\0') { 

        if (isOperand(input[i])) { 
            cout<<input[i]; 
        } 

        else if (isOperator(input[i])) { 
            if (s.empty() 
                || outPrec(input[i]) > inPrec(s.top())) 
                s.push(input[i]); 
            else { 
                while (!s.empty() 
                       && outPrec(input[i]) < inPrec(s.top())) { 
                    cout<<s.top(); 
                    s.pop(); 
                } 
                s.push(input[i]); 
            } 
        } 

        else if (input[i] == ')') { 
            while (s.top() != '(') { 
                cout<<s.top(); 
                s.pop(); 

                if (s.empty()) {
                    exit(1); 
                } 
            } 

            s.pop(); 
        } 
        i++; 
    } 

    while (!s.empty()) { 
        if (s.top() == '(') {  
            exit(1); 
        } 
        cout<<s.top(); 
        s.pop(); 
    } 
} 

int main() 
{ 
	int n;
	cin>>n;
	while(n--)
	{
	    char input[max];
	    cin>>input; 
	    inToPost(input);
	    cout<<endl;
	}
    return 0; 
} 
