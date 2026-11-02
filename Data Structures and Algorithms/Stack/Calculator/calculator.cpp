// Source - https://stackoverflow.com/q/64744819
// Posted by user14337188
// Retrieved 2026-10-28, License - CC BY-SA 4.0

#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

int pri(char ch) //precedence checking
{
  switch (ch)
  {
    case '-':
    case '+': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
    case '(': 
    case ')': return 4;
    default: return -1;
    }
}


int calculate(char op, int l , int r) //actual calculations
{
  if(op == '+') return l + r;
  
  if(op == '-') return l - r ;
   
  if(op == '*') return l * r;
   
  if(op == '/')
   {
       if(r > 0)
       {
          return l/r;
       }
       return 0;
    }
  if(op == '^') return pow(l,r);
  
  return -1;
}


int main(void)
{
  string equ;
  cout << "Enter an expression: ";
  getline(cin, equ);
  char math[equ.size()+1];
  int l = sizeof(math)/sizeof(char);
  stack<char> s;
  stack<int> op_s;
  int i = 0;
  
  while(math[i] != '\0')
  { 
    if(math[i] == '(')
    {
      s.push('(');
      }
    else if(math[i] == ')')
    {
      while(s.top() != '(')
      {
        int r = op_s.top();
        op_s.pop();
        int l = op_s.top();
        op_s.pop();
        int re = calculate(s.top(),l,r);
        op_s.push(re);
        s.pop();
        }
      s.pop();
     }
     else if(math[i] == '+' || math[i] == '-' || math[i] == '*' || math[i] == '/' || math[i] == '^')
     {
        int pC = pri(math[i]);
        while(!s.empty() && pri(s.top()) >= pC)
        {
          int r = op_s.top();
          op_s.pop();
          int l = op_s.top();
          op_s.pop();
          int re = calculate(s.top(),l,r);
          op_s.push(re);
          s.pop();
          }
           s.push(math[i]);
       }
       else
       {
          op_s.push(int(math[i])- 48);
       }
      i++;
   }
   while(!s.empty())
   {
       int r = op_s.top();
       op_s.pop();
       int l = op_s.top();
       op_s.pop();
       int re = calculate(s.top(),l,r);
       op_s.push(re);
       s.pop();
   }

   cout <<"Result: " << op_s.top() << endl;
   return 0;
}
