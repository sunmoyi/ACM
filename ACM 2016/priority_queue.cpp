#include<cstdio>
#include<vector>
#include<cstdlib>
#include<functional>

using namespace std;

template<class _Ty, class _Container = vector<_Ty>, class _Pr = less<typename _Container::value_type> > //默认以vector为容器的  
class priority_queue
{   // priority queue implemented with a _Container  
public:
	typedef _Container container_type;
	typedef typename _Container::value_type value_type;
	typedef typename _Container::size_type size_type;
	typedef typename _Container::reference reference;
	typedef typename _Container::const_reference const_reference;

	priority_queue() : c(), comp()
	{   // construct with empty container, default comparator  
	}

	explicit priority_queue(const _Pr& _Pred) : c(), comp(_Pred)
	{   // construct with empty container, specified comparator  
	}

	priority_queue(const _Pr& _Pred, const _Container& _Cont) : c(_Cont), comp(_Pred)
	{   // construct by copying specified container, comparator  
		make_heap(c.begin(), c.end(), comp); //参见《STL系列之四 heap 堆的相关函数》  
	}

	template<class _Iter>
	priority_queue(_Iter _First, _Iter _Last) : c(_First, _Last), comp()
	{   // construct by copying [_First, _Last), default comparator  
		make_heap(c.begin(), c.end(), comp);
	}

	template<class _Iter>
	priority_queue(_Iter _First, _Iter _Last, const _Pr& _Pred) : c(_First, _Last), comp(_Pred)
	{   // construct by copying [_First, _Last), specified comparator  
		make_heap(c.begin(), c.end(), comp);
	}

	template<class _Iter>
	priority_queue(_Iter _First, _Iter _Last, const _Pr& _Pred, const _Container& _Cont) : c(_Cont), comp(_Pred)
	{   // construct by copying [_First, _Last), container, and comparator  
		c.insert(c.end(), _First, _Last);
		make_heap(c.begin(), c.end(), comp);
	}

	bool empty() const
	{   // test if queue is empty  
		return (c.empty());
	}

	size_type size() const
	{   // return length of queue  
		return (c.size());
	}

	const_reference top() const
	{   // return highest-priority element  
		return (c.front());
	}

	reference top()
	{   // return mutable highest-priority element (retained)  
		return (c.front());
	}

	void push(const value_type& _Pred)
	{   // insert value in priority order  
		c.push_back(_Pred);
		push_heap(c.begin(), c.end(), comp);
	}

	void pop()
	{   // erase highest-priority element  
		pop_heap(c.begin(), c.end(), comp);
		c.pop_back();
	}

protected:
	_Container c;   // the underlying container  
	_Pr comp;   // the comparator functor  
};