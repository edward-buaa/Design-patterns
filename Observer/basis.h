#ifndef __BASIS_C_H__
#define __BASIS_C_H__

/*
�۲��ߺͱ��۲��ߵĻ���
�۲�ģʽ�������һ�Զ�����⣬��һ�仯ʱ����ÿ�����յ�����֪ͨ
�ܽ᣺
	��1��Ψһ�ı��۲����д������й۲��ߵĻ���ָ��(list)
	��2������Ҫ�۲�����Ը���ʱ����notify���۲��߸��Ե���update
	��3��ÿ���۲����д��б��۲��߻���ָ�룬�����ڻ��߶�Ӧ��������Ϣ
	��4���۲���ֻ�Ƕ�ȡ���ԣ������̰߳�ȫ���⣬ֻ��Ҫ���Ʊ��۲����������޸�ʱ��
*/

#include <list>
#include <string>

class Subject;

//�۲���
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

//���۲����
class Subject
{
public:
	Subject() {};
	Subject(const Subject&) = delete;
	Subject(const Subject&&) = delete;
	Subject& operator=(const Subject&) = delete;
	Subject& operator=(const Subject&&) = delete;

	virtual ~Subject() {};	//����Ϊ�飬������û������

	//��ӹ۲���
	void attch(Observer* obj)
	{
		if(obj)
			m_boservers.push_back(obj);
	}

	//�Ƴ��۲���
	void remove(Observer* obj)
	{
		if(obj)
			m_boservers.remove(obj);
	}

	//֪ͨ�۲���
	void notify()
	{
		for (auto it : m_boservers)
		{
			it->update();
		}
	}

	virtual void SetStatus(std::string s) = 0;	//����״̬
	virtual std::string GetStatus() = 0;		//��ȡ״̬

private:
	std::list<Observer*>	m_boservers;	//�۲�������
protected:
	//״̬�����ǹ۲�Ķ��󣬷�������Ҳ�ǿ��Եģ����۲���ֻ��һ��
	std::string		m_status;	
};


#endif