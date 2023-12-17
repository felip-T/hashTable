#include <functional>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stdexcept>

#define NUMBER_OF_BUCKETS 128

template <class key, class T>
class hashTable
{
public:
	hashTable(std::function<size_t(key)>);
	void setHash(std::function<size_t(key)>);
	void insert(key, T);
	void remove(key);
	T operator[](key);
	std::vector<std::tuple<key,T>>* getTable() { return table; }
	unsigned getSize() { return size; }
private:
	std::vector<std::tuple<key,T>>* table;
	std::function<size_t(key)> hash;
	size_t size;
};

template <class key, class T>
hashTable<key, T>::hashTable(std::function<size_t(key)> h)
{
	table = new std::vector<std::tuple<key, T>>[NUMBER_OF_BUCKETS];
	hash = h;
	size = 0;
}

template <class key, class T>
void hashTable<key, T>::setHash(std::function<size_t(key)> h)
{
	hash = h;
}

template <class key, class T>
void hashTable<key, T>::insert(key k, T t)
{
	size_t index = hash(k);
	if (std::find_if(table[index].begin(), table[index].end(), [k](std::tuple<key,T> t) { return std::get<0>(t) == k; }) == table[index].end()){
		table[index].push_back(std::make_tuple<key,T>(std::move(k),std::move(t)));
		size++;
	}
}

template <class key, class T>
T hashTable<key, T>::operator[](key k)
{
	size_t index = hash(k);
	auto elem = std::find_if(table[index].begin(), table[index].end(), [k](std::tuple<key,T> t) { return std::get<0>(t) == k; });
	if (elem == table[index].end())
		throw std::invalid_argument("not found");
	return std::get<1>(*elem);
}

template <class key, class T>
void hashTable<key, T>::remove(key k)
{
	size_t index = hash(k);
	auto elem = std::find_if(table[index].begin(), table[index].end(), [k](std::tuple<key,T> t) { return std::get<0>(t) == k; });
	if (elem == table[index].end())
		throw std::invalid_argument("not found");
	table[index].erase(elem);
	size--;
}
