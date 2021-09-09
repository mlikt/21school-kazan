#ifndef __WHATEVER_H__
#define __WHATEVER_H__

template<class T>
void swap(T& a, T& b){
	T buf;

	buf = a;
	a = b;
	b = buf;
}

template<typename T>
T min(T a , T b){
	if (a < b)
		return (a);
	return(b);
}

template<typename T>
T max(T a , T b){
	if (a > b)
		return (a);
	return(b);
}

#endif