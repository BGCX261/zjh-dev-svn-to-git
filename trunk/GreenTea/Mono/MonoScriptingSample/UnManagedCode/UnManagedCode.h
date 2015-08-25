#ifndef _UN_MANAGED_CODE_H_
#define _UN_MANAGED_CODE_H_

class UnManagedCode
{
public:
	UnManagedCode();
	~UnManagedCode();	
};

extern "C" __declspec(dllexport) int __stdcall TestAdd(int a, int b);
extern "C" __declspec(dllexport) int __stdcall TestSub(int a, int b);

#endif /* _UN_MANAGED_CODE_H_ */
