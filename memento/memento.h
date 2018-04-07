#ifndef __MEMENTO_C_H__
#define __MEMENTO_C_H__

#include <string>
#include <iostream>

class Memento;

class Originator
{
public:
	Originator() { m_mt = nullptr; m_sdt = ""; }
	Originator(const std::string sdt) { m_mt = nullptr; m_sdt = sdt; }
	Originator(const Originator&) = delete;
	Originator(const Originator&&) = delete;
	Originator& operator=(const Originator&) = delete;
	Originator& operator=(const Originator&&) = delete;
	~Originator() {}

	Memento* CreateMemento();
	void SetMemento(Memento* men);
	void RestoreToMemento(Memento* mt);
	std::string GetState() { return m_sdt; }
	void SetState(const std::string sdt) { m_sdt = sdt; }
	void PrintState() { std::cout << m_sdt << std::endl; }

private:
	std::string m_sdt;
	Memento*	m_mt;
};

class Memento
{
private:
	friend class Originator;
	Memento() {};
	Memento(const std::string sdt) { m_sdt = sdt; }
	Memento(const Memento&) = delete;
	Memento(const Memento&&) = delete;
	Memento& operator=(const Memento&) = delete;
	Memento& operator=(const Memento&&) = delete;
	~Memento() {}

	void SetState(const std::string sdt) { m_sdt = sdt; }
	std::string GetState() { return m_sdt; }

private:
	std::string m_sdt;
};

//管理者类
class CareTaker
{
public:

};

#endif