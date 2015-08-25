#ifndef _GREENTEA_ALGORITHM_H_
#define _GREENTEA_ALGORITHM_H_

#include <algorithm>

// Sort
template<class _RanIt>
inline void GTAlgorithmSort(_RanIt _First, _RanIt _Last)
{
	std::sort(_First, _Last);
}
template<class _RanIt, class _Pr>
inline void GTAlgorithmSort(_RanIt _First, _RanIt _Last, _Pr _Pred)
{
	std::sort(_First, _Last, _Pred);
}

#endif /* _GREENTEA_ALGORITHM_H_ */
