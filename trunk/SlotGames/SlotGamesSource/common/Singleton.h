#ifndef _SINGLETON_H_
#define _SINGLETON_H_

//--------------------------------------------------------------
// Usage of Singleton
//
// 1.In .h file:
//   class SampleManager : public Singleton<SampleManager>
// 2.In .cpp file:
//   SINGLETON_IMP(SampleManager);
//
// NOTE:
// _type must have default constructor.
//--------------------------------------------------------------

#define SINGLETON_IMP(_type) template<> _type Singleton<_type>::m_Instance=_type();

template<class T>
class Singleton
{
public:
	Singleton()
	{
	}

	virtual ~Singleton()
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

#endif /* _SINGLETON_H_ */
