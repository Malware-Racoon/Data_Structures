#include <iostream>

#include "GenericList.cc"
#include "Stack.cc"
#include "Queue.cc"
#include <cmath>

using namespace std;

//Templates
Queue<char> makeInfixQue(char Line[MAX_SIZE]);
Queue<char> makePostfixQue(Queue<char> infix);
int getPriority(char Peek, bool infix);
double findAnswer(Queue<char> postfix);
double checkOperator(char, double, double);





int main()
{
	char Line[MAX_SIZE];
	while(cin.getline(Line, MAX_SIZE))
	{
		Queue<char> infix(makeInfixQue(Line));
		cout << infix << endl;

		Queue<char> postfix(makePostfixQue(infix));
		cout << postfix << endl;

		double Answer = findAnswer(postfix);
		cout << Answer << endl << endl;
	}
}


Queue<char> makeInfixQue(char Line[MAX_SIZE])
{
	Queue<char> q1;
	for(int i = 0; i < (cin.gcount()) - 1; i++)
	{
		q1.Enqueue(Line[i]);

	}
	return q1;
}

Queue<char> makePostfixQue(Queue<char> infix)
{
	Queue<char> q2;
	Stack<char> s1;
	while(!infix.IsEmpty())
	{
		if(isdigit(infix.Peek()))
		{
			q2.Enqueue(infix.Dequeue());
		}
		else
		{
			if(infix.Peek() == ')')
			{
				while(s1.Peek() != '(')
				{
					q2.Enqueue(s1.Pop());
				}
				s1.Pop();
				infix.Dequeue();
			}
			else
			{
				if(!(s1.IsEmpty()))
				{
					while(getPriority(s1.Peek(), false) >= getPriority(infix.Peek(), true) && !(s1.IsEmpty()))
					{
						q2.Enqueue(s1.Pop());
					}
				}
				s1.Push(infix.Dequeue());
			}
		}
	}
	while(!(s1.IsEmpty()))
	{
		q2.Enqueue(s1.Pop());
	}
	return q2;
}

int getPriority(char peek, bool infix)
{
	if(infix)
	{
		if(peek == '(')
			return 4;
		if(peek == '^')
			return 3;
		if(peek == '*' || peek == '/')
			return 2;
		if(peek == '+' || peek == '-')
			return 1;
		return 0;
	}

	else
	{
		if(peek == '*' || peek == '/' || peek == '^')
			return 2;
		if(peek == '+' || peek == '-')
			return 1;
		return 0;

	}
}

double findAnswer(Queue <char> postfix)
{
	Stack<double> s1;
	while(!postfix.IsEmpty())
	{
		if(isdigit(postfix.Peek()))
		{
			s1.Push((double)(postfix.Dequeue()) - '0');
		}
		else
		{
			double second = s1.Pop();
			double first = s1.Pop();
			s1.Push(checkOperator(postfix.Dequeue(), first, second));
		}
	}
	return s1.Pop();
}

double checkOperator(char op, double first, double second)
{
	double answer;
	if(op == '+')
	{
		answer = first + second;
	}
	if(op == '-')
	{
		answer = first - second;
	}
	if(op == '*')
	{
		answer = first * second;
	}
	if(op == '/')
	{
		answer = first / second;
	}
	if(op == '^')
	{
		answer = pow(first, second);
	}
	return answer;
}
}