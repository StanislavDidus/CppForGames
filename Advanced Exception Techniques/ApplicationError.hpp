#pragma once

#include <exception>
#include <string>

class ApplicationError : public std::exception
{
public:
	ApplicationError(std::string msg) : msg(std::move(msg))
	{}

	const char* what() const noexcept override
	{
		return msg.c_str();
	}

	virtual const char* getErrorCode() const noexcept
	{
		return "APPLICATION-ERROR";
	}

private:
	std::string msg;
};