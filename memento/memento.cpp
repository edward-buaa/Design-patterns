

#include "memento.h"


Memento* Originator::CreateMemento() 
{ 
	return new Memento(m_sdt); 
}

void Originator::SetMemento(Memento* men) 
{
	this->m_sdt = m_mt->GetState();
}

void Originator::RestoreToMemento(Memento* mt) 
{
	this->m_sdt = mt->m_sdt; 
}