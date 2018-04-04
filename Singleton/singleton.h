#ifndef __C_SINGLETON_H__
#define __C_SINGLETON_H__

#include <mutex>

class singleton
{
public:
	static singleton* getInstance()
	{
		/*
		///多线程安全，需要加锁
		std::lock_guard<std::mutex> lock(singleton::mtx);
		if (m_instance == nullptr)
			m_instance = new singleton();
		return m_instance;
		*/

		//？？？静态实例初始化在程序开始时进入主函数之前就由主线程以单线程方式完成了初始化？？？
		//应该说是分配了内存空间，默认初始化，比如int值为0，但是并没有调用构造函数完成初始化
		//第一次调用进入构造函数初始化，是线程安全的。程序推出时会调用析构函数
		static singleton manage;
		return &manage;
	}

	~singleton() 
	{
		
	};

private:
	///私有化，并允许类外部实例化
	singleton() 
	{
	};
	
	singleton(const singleton&) = delete;
	singleton(const singleton&&) = delete;
	singleton& operator=(const singleton&) = delete;
	singleton& operator=(const singleton&&) = delete;

/* 在vs2017中调试发现并没有调用析构函数
///在C++中，系统会自动析构所有的全局变量以及所有的类的静态成员变量
private:
	class release
	{
	public:
		~release()
		{
			if (singleton::m_instance)
			{
				delete singleton::m_instance;
				singleton::m_instance = nullptr;
			}
		}
	};
*/

private:
	//static release rl;
	//static std::mutex mtx;
	//static singleton* m_instance;
};

///静态成员需要在类外部初始化
//singleton* singleton::m_instance = nullptr;
//std::mutex singleton::mtx;

#endif
