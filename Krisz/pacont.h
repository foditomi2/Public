//#pragma once
#ifndef _PACONT_H_
#define _PACONT_H_
#include <deque>


template <class T, class Pred>
class predicate_alternating_container
{
private:
	typedef std::deque<T> Container;
	Container cont;
	Pred p;
public:
	void insert(const T& t)
	{
		if(p(cont)) {
			cont.push_front(t);
		}
		else
		{
			cont.push_back(t);
		}
	}
	
	int size() const
	{
		return cont.size();
	}
	
	const T& at (int a) const
	{
		return cont.at(a);
	}
	
	void erase(int a)
	{
		cont.erase(cont.begin()+a);
	}
	
	const T& operator[](int a) const
	{
		return cont.at(a);
	}
	
	T& operator[](int a)
	{
		return cont.at(a);
	}
	
	predicate_alternating_container(){}
	
	template<typename Pred2>
	predicate_alternating_container(predicate_alternating_container<T,Pred2> a) 
	{
		for(int i=0; i<a.size(); ++i) {
			insert(a.at(i));
		}
	}
	
	template<typename Pred2>
	bool operator==(predicate_alternating_container<T, Pred2> a){
		if (this->size() == a.size())
		{
			for(int i=0; i<this->size();i++)
			{
				if(this->at(i)!=a.at(i))
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
};

#endif
