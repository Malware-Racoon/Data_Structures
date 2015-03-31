#include <iostream>


using namespace std;

template <class sType>

class Stack

{
	private: 
	List<sType> list;

	public:
		Stack()
		{
			list.First();

		}

		Stack(const Stack& s)
		{
			*this = s;

		}

		void operator=(const Stack& s)
		{
			list = s.list;
			list.First();
		}

		void Push(sType data)
		{
			list.InsertBefore(data);
		}

		sType Pop()
		{
			sType top = Peek();
			list.Remove();
			return top;
		}

		sType Peek()
		{
			list.First();
			return list.GetValue();
		}

		int Size()
		{
			return list.GetSize();
		}

		bool IsEmpty()
		{
			return list.IsEmpty();
		}

		bool IsFull()
		{
			return list.IsFull();
		}

		Stack operator+(const Stack& s) const
		{
			Stack newStack = *this;

			newStack.list = newStack.list + s.list;

			return newStack;
		}

		bool operator==(const Stack& s) const
		{
			return ((*this).list == s.list);
		}

		bool operator!=(const Stack& s) const
		{
			return(!(s==(*this)));
		}

		friend ostream& operator<<(ostream& out, const Stack& s)
		{
			out << s.list;
			return out;
		}
};