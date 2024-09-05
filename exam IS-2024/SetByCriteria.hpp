#pragma once
#include "Set.h"

template <class T>
class SetByCriteria:public Set
{
private:
	T criteria;

public:
	SetByCriteria(const T& cr);
	SetByCriteria(T&& cr);
	bool accepts(uint32_t el) const override;
	Set* clone() const override;
};

template <class T>
SetByCriteria<T>::SetByCriteria(const T& cr) :criteria(cr)
{

}

template <class T>
SetByCriteria<T>::SetByCriteria(T&& cr) :criteria(std::move(cr))
{

}

template <class T>
bool SetByCriteria<T>::accepts(uint32_t el) const 
{
	return criteria(el);
}

template<class T>
Set* SetByCriteria<T>::clone() const 
{
	return new SetByCriteria(*this);

}