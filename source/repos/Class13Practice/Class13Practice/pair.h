#pragma once
template<typename K, typename V>
class Pair
{
public:
	Pair(K k, V v);
	Pair(Pair<K, V>& source);
	Pair& operator=(Pair<K, V>& source);
	K getkey();
	V getvalue();
	void setkey(int k);
	void setvalue(int v);
	void PrintPair();


private:
	K key;
	V value;
};

template <typename K, typename V>
Pair<K, V>::Pair(K k, V v) :key(k), value(v) { }

template <typename K, typename V>
Pair<K, V>::Pair(Pair<K, V>& source)
{
	key = source.key;
	value = source.value;
}

template <typename K, typename V>
Pair<K, V>& Pair<K, V>::operator=(Pair<K, V>& source)
{
	key = source.key;
	value = source.value;
}

template <typename K, typename V>
K Pair<K, V>::getkey()
{
	return key;
}

template <typename K, typename V>
V Pair<K, V>::getvalue()
{
	return value;
}

template <typename K, typename V>
void Pair<K, V>::setkey(int k)
{
	key = k;
}

template <typename K, typename V>
void Pair<K, V>::setvalue(int v)
{
	value = v;
}

template <typename K, typename V>
void Pair<K, V>::PrintPair()
{
	std::cout << "(" << key << ": " << value << ")" << "\n";
}

