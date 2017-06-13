# ifndef STACK_H
#define STACK_H

#include <exception>
#include <deque>

template <class T>
class Stack
{
public:
	T pop();
	T& top();
	void push(const T& val);
	bool isEmpty() const { return c.empty(); }

	class ReadEmptyStack : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Read Stack error: the stack is empty;\n";
		}
	};

	//void Stack::push(const T& val)
	//{
	//	c.push_back(val);
	//}

	//T& Stack::top()
	//{
	//	if (c.empty())
	//		throw ReadEmptyStack();
	//	return c.back();
	//}

	//T Stack::pop()
	//{
	//	if (c.empty())
	//		throw ReadEmptyStack();
	//	T temp(c.back());  //ʹ�����ų�ʼ������Ϊ����������Ļ�������û������=
	//	c.pop_back();
	//	return temp;
	//}

private:
	std::deque<T> c;
};

template <class T>
void Stack<T>::push(const T& val)  //������д��������ʱ��Stack�����<T>����ʡ�ԣ������޷��������Ķ��������ڵ�����ƥ��
{
	c.push_back(val);
}

template <class T>
T& Stack<T>::top()
{
	if (c.empty())
		throw ReadEmptyStack();
	return c.back();
}

template <class T>
T Stack<T>::pop()
{
	if (c.empty())
		throw ReadEmptyStack();
	T temp (c.back() );  //ʹ�����ų�ʼ������Ϊ����������Ļ�������û������=
	c.pop_back();
	return temp;
}
#endif