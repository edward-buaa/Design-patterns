#ifndef __IMPLEMENTATION_H__
#define __IMPLEMENTATION_H__

#include "basis.h"
#include <iostream>

class ImplSubject : public Subject
{
public:
	ImplSubject()  {};
	ImplSubject(const ImplSubject&) = delete;
	ImplSubject(const ImplSubject&&) = delete;
	ImplSubject& operator=(const ImplSubject&) = delete;
	ImplSubject& operator=(const ImplSubject&&) = delete;

	~ImplSubject() {};

	//设置状态
	void SetStatus(std::string s)
	{
		m_status = s;
	}

	//获取状态
	std::string GetStatus()
	{
		return m_status;
	}
};

class ImplObserver : public Observer
{
public:
	ImplObserver(Subject* obj) { m_obj = obj; };
	ImplObserver(const ImplObserver&) = delete;
	ImplObserver(const ImplObserver&&) = delete;
	ImplObserver& operator=(const ImplObserver&) = delete;
	ImplObserver& operator=(const ImplObserver&&) = delete;

	~ImplObserver() {};

	void update()
	{
		std::string status = m_obj->GetStatus();
		std::cout << status << std::endl;
	}

private:
	//放到基类中去了，就不可以用在构造函数的初始化列表了
	//Subject* m_obj;
};



#endif