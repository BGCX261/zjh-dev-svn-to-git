#ifndef _GREENTEA_DICTIONARY_H_
#define _GREENTEA_DICTIONARY_H_

#include "GTBaseDef.h"
#include "GTString.h"
#include <map>

template <class KeyObjectType, class ValueObjectType>
class GTDictionary
{
public:
	typedef std::map<KeyObjectType, ValueObjectType> DictionaryType;
	typedef std::pair<KeyObjectType, ValueObjectType> KeyValuePair;
	// ObjectTypeIterator.first = Key
	// ObjectTypeIterator.second = Value
	typedef typename std::map<KeyObjectType, ValueObjectType>::iterator ObjectTypeIterator;

public:
	GTDictionary()
	{
	}

	/*
	GTDictionary(const GTDictionary& src)
	{
		for(ObjectTypeIterator it = src.Begin(); it != src.End(); it++)
		{
			Add(it.first, it.second);
		}
	}
	*/

	virtual ~GTDictionary()
	{
		m_Dictionary.clear();
	}

	GTString ToString(void)
	{
		return GTString(CTEXT("GTDictionary"));
	}

	// Get how many objects in the dictionary
	int32 Count() const
	{
		return m_Dictionary.size();
	}

	// Check if a key already exists
	bool KeyExists(const KeyObjectType& key)
	{
		ObjectTypeIterator it = m_Dictionary.find(key);
		if(it == m_Dictionary.end())
		{
			// No match case
			return false;
		}

		return true;
	}

	// Add a pair
	bool Add(const KeyObjectType& key, const ValueObjectType& value)
	{
		if(KeyExists(key))
		{
			// The key already exists
			return false;
		}
		// Insert
		m_Dictionary.insert(KeyValuePair(key, value));

		return true;
	}

	// Get a value by the key
	bool GetValueByKey(const KeyObjectType& key, ValueObjectType& value)
	{
		ObjectTypeIterator it = m_Dictionary.find(key);
		if(it == m_Dictionary.end())
		{
			// Key not found
			return false;
		}

		// Return the value
		value = it->second;

		return true;
	}

	// Change value by key
	bool ChangeValueByKey(const KeyObjectType& key, const ValueObjectType& value)
	{
		ObjectTypeIterator it = m_Dictionary.find(key);
		if(it == m_Dictionary.end())
		{
			// Key not found
			return false;
		}

		// Change the value
		it->second = value;

		return true;
	}
		
	// Remove a value by the key
	void Remove(const KeyObjectType& key)
	{
		ObjectTypeIterator it = m_Dictionary.find(key);
		if(it == m_Dictionary.end())
		{
			// Key not found
			return;
		}

		// Remove this object from the map
		m_Dictionary.erase(it);
	}
	void Remove(const ObjectTypeIterator it)
	{
		// Remove this object from the map
		m_Dictionary.erase(it);
	}

	// Get a value from key
	ValueObjectType& operator[](KeyObjectType key)
	{
		ObjectTypeIterator it = m_Dictionary.find(key);
		if(it == m_Dictionary.end())
		{
			// Key not found
			m_Dictionary.insert(KeyValuePair(key, ValueObjectType()));
			it = m_Dictionary.find(key);
		}
		return it->second;
	}
	
	inline ObjectTypeIterator Begin()
	{
		return m_Dictionary.begin();
	}

	inline ObjectTypeIterator End()
	{
		return m_Dictionary.end();
	}

	void Clear()
	{
		m_Dictionary.clear();
	}

	// Get all keys

private:
	DictionaryType m_Dictionary;
};

// Helper
// Get the key from ObjectTypeIterator
#define GTDictionaryGetKey(_it) (_it.first)
// Get the value from ObjectTypeIterator
#define GTDictionaryGetValue(_it) (_it.second)

#endif /* _GREENTEA_DICTIONARY_H_ */
