#pragma once

#include <memory>

class WindowImpl;
class Window
{
public:
	Window();
	~Window();

	void showWindow();
private:
	//The pimpl idiom (pointer to implementation)
	std::unique_ptr<WindowImpl> pImpl;
};