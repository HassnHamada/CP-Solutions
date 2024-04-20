#include <map>
#include <iostream>
#include <assert.h>
template <typename K, typename V>
class interval_map
{
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;

public:
	// constructor associates whole range of K with val
	interval_map(V const &val)
		: m_valBegin(val)
	{
	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const &keyBegin, K const &keyEnd, V const &val)
	{
		/*** RERTURN ON WRONG INPUT ***/
		if (!(keyBegin < keyEnd))
		{
			return;
		}

		/*** SETTING RANGE ***/
		std::cout << "Setting the range from " << keyBegin << "(included) to " << keyEnd << "(excluded) to the value `" << val << "`\n";
		auto itEnd = m_map.lower_bound(keyEnd);
		// Case 1:
		// Interval is empty or doesn't overlap with existing intervals
		if (itEnd == m_map.end())
		{
			m_map.insert_or_assign(keyEnd, m_valBegin);
		}
		// Case 2:
		// Interval overlaps with existing interval(s)
		else if (keyEnd < itEnd->first)
		{
			m_map.insert_or_assign(keyEnd, itEnd == m_map.begin() ? m_valBegin
																  : std::prev(itEnd)->second);
		}
		m_map.insert_or_assign(keyBegin, val);

		/*** ERRASING EXISTING INTERVAL OVERRIDEN BY NEW ONE ***/
		auto itBegin = m_map.find(keyBegin);
		assert(itBegin != m_map.end());
		auto itEraseBegin = std::next(itBegin);
		auto itEraseEnd = m_map.find(keyEnd);
		assert(itEraseBegin != m_map.end());
		assert(itEraseEnd != m_map.end());
		m_map.erase(itEraseBegin, itEraseEnd);
		std::cout << "Erased interval from " << (itEraseBegin->first) << "(included) to " << (itEraseEnd->first) << "(excluded)\n";

		/*** MAKE CANONICAL ***/
		auto itNewEnd = m_map.find(keyEnd);
		auto itNewBegin = m_map.find(keyBegin);
		if (itNewEnd != m_map.end() && itNewEnd->second == std::next(itNewEnd)->second)
		{
			m_map.erase(std::next(itNewEnd));
		}
		if (itNewBegin->second == itNewEnd->second)
		{
			m_map.erase(itNewEnd);
		}
		if (itNewBegin == m_map.begin() ? itNewBegin->second == m_valBegin
										: itNewBegin->second == std::prev(itNewBegin)->second)
		{
			m_map.erase(itNewBegin);
		}
		assert(m_map.empty() || std::prev(m_map.end())->second == m_valBegin);
	}

	// look-up of the value associated with key
	V const &operator[](K const &key) const
	{
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin())
		{
			return m_valBegin;
		}
		else
		{
			return (--it)->second;
		}
	}
	void print()
	{
		std::cout << "[START:" << m_valBegin << "]";
		for (auto &&[key, val] : m_map)
			std::cout << "[" << key << ':' << val << "]";
		std::cout << '\n';
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main()
{
	interval_map<int, char> map{'a'};
	map.print();

	map.assign(3, 15, 'b');
	map.print();

	map.assign(12, 23, 'c');
	map.print();

	map.assign(22, 23, 'd');
	map.print();

	map.assign(2, 4, 'e');
	map.print();

	map.assign(4, 18, 'f');
	map.print();

	map.assign(2, 8, 'g');
	map.print();

	map.assign(0, 10, 'a');
	map.print();

	map.assign(0, 20, 'a');
	map.print();

	map.assign(0, 30, 'a');
	map.print();

	map.assign(0, 300, 'a');
	map.print();

	map.assign(0, 300, 'b');
	map.print();

	map.assign(100, 200, 'c');
	map.print();

	map.assign(210, 250, 'a');
	map.print();

	map.assign(210, 299, 'a');
	map.print();

	map.assign(199, 300, 'a');
	map.print();

	map.assign(199, 300, 'a');
	map.print();

	map.assign(500, 550, 'a');
	map.print();

	map.assign(0, 159, 'a');
	map.print();

	map.assign(0, 1590, 'a');
	map.print();

	map.assign(300, 1590, 'b');
	map.print();

	map.assign(100, 300, 'c');
	map.print();

	map.assign(0, 3000, 'd');
	map.print();

	map.assign(0, 2999, 'a');
	map.print();

	map.assign(10000, 10001, 'c');
	map.print();
}