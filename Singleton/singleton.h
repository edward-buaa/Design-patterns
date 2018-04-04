#ifndef __C_SINGLETON_H__
#define __C_SINGLETON_H__

#include <mutex>

class singleton
{
public:
	static singleton* getInstance()
	{
		/*
		///���̰߳�ȫ����Ҫ����
		std::lock_guard<std::mutex> lock(singleton::mtx);
		if (m_instance == nullptr)
			m_instance = new singleton();
		return m_instance;
		*/

		//��������̬ʵ����ʼ���ڳ���ʼʱ����������֮ǰ�������߳��Ե��̷߳�ʽ����˳�ʼ��������
		//Ӧ��˵�Ƿ������ڴ�ռ䣬Ĭ�ϳ�ʼ��������intֵΪ0�����ǲ�û�е��ù��캯����ɳ�ʼ��
		//��һ�ε��ý��빹�캯����ʼ�������̰߳�ȫ�ġ������Ƴ�ʱ�������������
		static singleton manage;
		return &manage;
	}

	~singleton() 
	{
		
	};

private:
	///˽�л������������ⲿʵ����
	singleton() 
	{
	};
	
	singleton(const singleton&) = delete;
	singleton(const singleton&&) = delete;
	singleton& operator=(const singleton&) = delete;
	singleton& operator=(const singleton&&) = delete;

/* ��vs2017�е��Է��ֲ�û�е�����������
///��C++�У�ϵͳ���Զ��������е�ȫ�ֱ����Լ����е���ľ�̬��Ա����
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

///��̬��Ա��Ҫ�����ⲿ��ʼ��
//singleton* singleton::m_instance = nullptr;
//std::mutex singleton::mtx;

#endif
