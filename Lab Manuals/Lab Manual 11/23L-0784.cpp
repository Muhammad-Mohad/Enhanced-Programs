#include <iostream>
using namespace std;

template <class K> K GetMax(K num1, K num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
		
}

template <class K> K GetMin(K num1, K num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

template <class K , class M> K GetMax(K num1, M num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;

}

template <class K , class M> K GetMin(K num1, M num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

// int main()
// {
// 	int i = 5, j = 6, k;
// 	long int  l = 10, m = 5, n;
// 	k = GetMax<int>(i, j);
// 	n = GetMin<long>(l, m);
// 	cout << k << endl;
// 	cout << n << endl;
// 	return 0;
// }

// int main()
// {
// 	char i = 'Z';
// 	int j = 6, k;
// 	long l = 10, m = 5, n;
// 	k = GetMax(i, m);
// 	n = GetMin(j, l);
// 	cout << k << endl;
// 	cout << n << endl;

// 	return 0;
// }

template <class T>

class Pair
{
    friend ostream& operator<<(ostream& out, const Pair<T>& p)
    {
        out << p.values[0] << ", " << p.values[1];
        return out;
    }

    private:
	    T values[2];

    public:
        Pair();
        Pair(T, T);

        T GetMax()
        {
            if (values[0] > values[1])
                return values[0];
            else
                return values[1];
        }
        
        T GetMin();
};

template <class T> Pair<T>::Pair()
{

}
template <class T> Pair<T>::Pair(T num1, T num2)
{
    values[0] = num1;
    values[1] = num2;
}
template <class T> T Pair<T>::GetMin()
{
    if (values[0] < values[1])
        return values[0];
    else
        return values[1];
}

// int main()
// {
// 	Pair<double> myObject(1.012, 1.01234);
// 	cout << myObject.GetMax();

// 	return 0;
// }

template<class T> class Container
{
    private:
	    T data;

    public:
        Container(T);
};

template<class T> Container<T>::Container(T t)
{
    data = t;
}

template<> class Container<char>
{
    private:
	    char data;

    public:
        Container(char);
        char Uppercase();
};

Container<char>::Container(char c)
{
    data = c;
}

char Container<char>::Uppercase()
{
    data -= 32;
    return data;
}


template<> class Container<int>
{
    private:
	    int data;

    public:
        Container(int);
        int Increase();
};

Container<int>::Container(int i)
{
    data = i;
}

int Container<int>::Increase()
{
    data++;
    return data;
}

// int main()
// {
// 	Container<int> myInt(7);
// 	Container<char> myChar('j');

// 	cout << myInt.Increase() << endl;
// 	cout << myChar.Uppercase() << endl;

// 	return 0;
// }


template<class T, int N>
class Sequence 
{
    private:
	    T memblock[N];

    public:
        Sequence();
        void setmember(int, T);
        T getmember(int);
};

template<class T, int N> Sequence<T, N>::Sequence()
{

}

template<class T, int N> void Sequence<T, N>::setmember(int x, T value)
{
    memblock[x] = value;
}

template<class T, int N> T Sequence<T, N>::getmember(int x)
{
    return memblock[x];
}

// int main()
// {
// 	Sequence <int, 5> myints;
// 	Sequence <double, 5> myfloats;
// 	myints.setmember(0, 100);
// 	myfloats.setmember(3, 3.1416);
// 	cout << myints.getmember(0) << "\n";
// 	cout << myfloats.getmember(3) << "\n";
// 	return 0;
// }

int main()
{
	Pair<double> y(2.23, 3.45);
	Sequence<Pair<double>,5> myPairs;
	myPairs.setmember(0, y);
	cout << myPairs.getmember(0) << "\n";
}
