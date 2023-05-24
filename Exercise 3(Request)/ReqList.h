#pragma once
#include <list>
#include "Request.h"
#include <memory>
#include <iostream>
#include <array>

constexpr int NUMBER_OF_DATA_FIELDS = 4;

using std::cin;
using std::cout;
class ReqList
{
private:
	std::list<std::unique_ptr<Request>> m_reqlist;

	std::unique_ptr<Request> m_req;
	std::array<bool, NUMBER_OF_DATA_FIELDS> m_flags;
	bool isFirstAddThisRequest;

public:
	ReqList() : isFirstAddThisRequest(true) { m_flags.fill(false); }

	bool addRequest();
	
	bool deleteRequest(int index);

	bool showAllRequests();
	
};

