#ifndef _GREENTEA_SINGLETON_H_
#define _GREENTEA_SINGLETON_H_

//--------------------------------------------------------------
// Usage of Singleton
//
// 1.In .h file:
//   class SampleManager : public GTSingleton<SampleManager>
// 2.In .cpp file:
//   GTSINGLETON_IMP(SampleManager);
//
// NOTE:
// _type must have default constructor.
//--------------------------------------------------------------

#define GTSINGLETON_IMP(_type) template<> _type GTSingleton<_type>::m_Instance=_type();

template<class T>
class GTSingleton
{
public:
	GTSingleton()
	{
	}

	virtual ~GTSingleton()
	{
	}

public:
	// Get singleton instance
	static T* GetInstance()
	{
		return &m_Instance;
	}

	static T* Instance()
	{
		return &m_Instance;
	}

	static T* Inst()
	{
		return &m_Instance;
	}

protected:
	// Singleton object
	static T m_Instance;
};

#endif /* _GREENTEA_SINGLETON_H_ */
