#include <iostream>
#include <memory>
#include <cassert>

#include "window.hpp"

class Widget
{
public:
	Widget(int data = 0)
		: data(data)
	{
		std::cout << "Widge::Widget( " << data << " )" << std::endl;
	}

	~Widget()
	{
		std::cout << "~Widge::Widget()" << std::endl;
	}

	void doSomething()
	{
		std::cout << "Widge::doSometing()" << std::endl;
	}
private:
	int data = 0;
};

struct WidgetDeleter
{
	void operator()(Widget* w)
	{
		std::cout << "WidgetDeleter::operator()" << std::endl;
		delete w;
	}
};

template<typename T>
struct CustomAllocator
{
	using value_type = T;

	CustomAllocator() noexcept = default;

	template<typename U>
	CustomAllocator(const CustomAllocator<U>&) noexcept {}

	T* allocate(std::size_t n)
	{
		std::cout << "CustomAllocator::allocate( " << n << " )" << std::endl;
		return static_cast<T*>(::operator new(n * sizeof(T)));
	}

	void deallocate(T* p, std::size_t n) noexcept
	{
		std::cout << "CustomAllocator::deallocate( " << n << " )" << std::endl;
		::operator delete(p);
	}
};

template<typename T, typename U>
bool operator==(const CustomAllocator<T>&, const CustomAllocator<U>&) noexcept { return true; }

template<typename T, typename U>
bool operator!=(const CustomAllocator<T>& lhs, const CustomAllocator<U>& rhs) noexcept { return !(lhs == rhs); }


std::shared_ptr<Widget> make_widget(int data = 0)
{
	return std::allocate_shared<Widget>(CustomAllocator<Widget>(), data);
}



int main()
{
	//std::weak_ptr<Widget> wPtr;
	//std::shared_ptr<Widget> sPtr;
	//{

	//	//auto widget = std::shared_ptr<Widget>(new Widget(1

	//	auto widget = make_widget(1);
	//	sPtr = widget;

	//	std::cout << "Use count: " << widget.use_count() << std::endl;

	//	wPtr = widget;

	//	std::cout << "Use count: " << widget.use_count() << std::endl;
	//}

	//if(auto widget = wPtr.lock())
	//{
	//	widget->doSomething();

	//}

	////std::unique_ptr<Widget> uPtr = std::unique_ptr<Widget>(new Widget(2));
	//{
	//	// RAII
	//	std::unique_ptr<Widget> widget = std::make_unique<Widget>(2);

	//	//Someting happens
	//	throw std::exception();
	//}
	//auto uPtr = std::make_unique<Widget>(2);

	////auto uPtr2 = std::move(uPtr);

	//Window win;
	//win.showWindow();

	//Modulo operator

	int array_of_prime_numbers[100];

	int last_number = 2;

	for (int i = 0; i < std::size(array_of_prime_numbers); i++)
	{
		while (true)
		{
			bool isOtherDivisor = false;
			for (int j = 2; j < last_number - 1; j++)
			{
				if (last_number % j == 0)
				{
					isOtherDivisor = true;
					break;
				}
			}

			if (!isOtherDivisor)
			{
				array_of_prime_numbers[i] = last_number;
				last_number++;
				break;
			}

			last_number++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << array_of_prime_numbers[j + i * 10] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}