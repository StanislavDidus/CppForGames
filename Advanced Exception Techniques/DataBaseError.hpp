#pragma once

#include "ApplicationError.hpp"

class DataBaseError : public ApplicationError
{
public:
	DataBaseError(std::string msg) : ApplicationError{std::move(msg)}
	{}

	const char* getErrorCode() const noexcept override
	{
		return "DATABASE-ERROR";
	}
};

// More specific database error
class ConnectionError : public DataBaseError
{
public:
	explicit ConnectionError(const std::string& msg)
		: DataBaseError("Connection failed: " + msg)
	{
		
	}
	
	const char* getErrorCode() const noexcept override
	{
		return "DB-CONNECTION-ERROR";
	}
};

// SQL Query error
class QueryError : public DataBaseError
{
public:
	QueryError(const std::string& msg, std::string sqlQuery)
		: DataBaseError("Query failed: " + msg), query{std::move(sqlQuery)}
	{
		
	}

	const char* getErrorCode() const noexcept override
	{
		return "DB-QUERY-ERROR";
	}

	const std::string& getQuery() const
	{
		return query;
	}

private:
	std::string query;
};