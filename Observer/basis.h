#ifndef __BASIS_C_H__
#define __BASIS_C_H__

/*
观察者和被观察者的基类
观察模式解决的是一对多的问题，当一变化时，多每个都收到更新通知
总结：
	（1）唯一的被观察者中存有所有观察者的基类指针(list)
	（2）当需要观察的属性更新时调用notify，观察者各自调用update
	（3）每个观察者中存有被观察者基类指针，可用于或者对应的属性信息
	（4）观察者只是读取属性，考虑线程安全问题，只需要控制被观察者中属性修改时刻
*/

#include <list>
#include <string>

class Subject;

//观察者
class Observer
{
public:
	Observer() {};
	Observer(const Observer&) = delete;
	Observer(const Observer&&) = delete;
	Observer& operator=(const Observer&) = delete;
	Observer& operator=(const Observer&&) = delete;
	
	virtual ~Observer() {};
	virtual void update() = 0;

protected:
	Subject* m_obj;
};

//被观察对象
class Subject
{
public:
	Subject() {};
	Subject(const Subject&) = delete;
	Subject(const Subject&&) = delete;
	Subject& operator=(const Subject&) = delete;
	Subject& operator=(const Subject&&) = delete;

	virtual ~Subject() {};	//必须为虚，析构才没有问题

	//添加观察者
	void attch(Observer* obj)
	{
		if(obj)
			m_boservers.push_back(obj);
	}

	//移除观察者
	void remove(Observer* obj)
	{
		if(obj)
			m_boservers.remove(obj);
	}

	//通知观察者
	void notify()
	{
		for (auto it : m_boservers)
		{
			it->update();
		}
	}

	virtual void SetStatus(std::string s) = 0;	//设置状态
	virtual std::string GetStatus() = 0;		//获取状态

private:
	std::list<Observer*>	m_boservers;	//观察者链表
protected:
	//状态，这是观察的对象，放在子类也是可以的，被观察者只有一个
	std::string		m_status;	
};


#endif