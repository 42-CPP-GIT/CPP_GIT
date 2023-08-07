#include "PmergeMe.hpp"

const char*	PmergeMe::InvalidArgument::what() const throw()
{
	return ("Error");
}

PmergeMe::PmergeMe(const int& argc, char** argv)
:  _argc(argc)
{
	if (!_checkArgument(argc, argv))
		throw InvalidArgument();
	std::cout << "Before:	"; 
	_printContainer(this->_sortedVec);
}

PmergeMe::~PmergeMe()
{
}

// -------------------<VECTOR>-----------------------------

void PmergeMe::_mergeVec(std::vector<unsigned int>& vec, int left, int mid, int right)
{
    int i = left;
	int j = mid + 1;
    std::vector<unsigned int> tmp;
    while (i <= mid && j <= right)
	{
        if (vec[i] < vec[j]) {
            tmp.push_back(vec[i++]);
        } else {
            tmp.push_back(vec[j++]);
        }
    }
    while (i <= mid)
        tmp.push_back(vec[i++]);
    while (j <= right)
        tmp.push_back(vec[j++]);
    for (size_t k = 0; k < tmp.size(); ++k) {
        vec[left + k] = tmp[k];
    }
}

void    PmergeMe::_insertVec(std::vector<unsigned int>& vec, int left, int right)
{
    unsigned int key;
    int j;
    for (int i = left + 1; i <= right; ++i)
    {
        key = vec[i];
        j = i - 1;
        while (j >= left && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}
void    PmergeMe::_fordJohnsonVec(std::vector<unsigned int>& vec)
{
    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    //1. 페어로 죄다 만들어버린다. 중요한건, 페어로 만들어질때 작은 값이 오도록 정렬하는 것.
    //마지막 원소 또 처리해야하네 이런
    int index = 0;
    int size = vec.size();
    for (; index < size - 1; index += 2) 
	{
        if (vec[index] > vec[index + 1])
        {
            pairs.push_back(std::make_pair(vec[index + 1], vec[index]));
        }
        else
        {
            pairs.push_back(std::make_pair(vec[index], vec[index + 1]));
        }
    }
    if (index == size - 1)
	{
        pairs.push_back(std::make_pair(vec[size - 1], vec[size - 1]));
    }
    // 2. 각 페어를 정렬하고, key보다 큰 페어가 등장하면 집어넣어야 한다. 그냥 삽입정렬로 해도
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        std::pair<unsigned int, unsigned int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j] > key)
        {
            pairs[j + 1] = pairs[j];
            --j;
        }
        pairs[j + 1] = key;
    }
    // 3. 이미 정렬된 페어를 병합. 모든 페어가 사라질 때까지.
    // 여기서 중요한건, 원본 벡터의 어느 부분이 어디인지 판단하는 것이다. 벡터를 여러개 만들어서 직접 다 합치는 행복한 상상을 했지만
    // 메모리가 지랄난다. 알고리즘은 맞는데 보통의 경우 일반적인 삽입병합정렬에 비해 엄청나게 복잡하고 느리다. 비교가 적다는데 의의를 둔 그런
    // https://cplusplus.com/reference/algorithm/lower_bound/
    // 핵심 아이디어는 비교 횟수를 줄이는 것. pair는 한번만 비교하면 되니깐, 전체에 대해서 비교 횟수가 절반으로 줄어든다.
    // vec: [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t]
    //      |<--- left --->|<-- mid --><-- mid+1 --->|<--- right    -->|
    //최악의 경우 찾아냄 -> 포드존슨알고리즘은 원소의 수가 많고, 원소가 무작위로 분포되어 있을때 효과적. 하지만
    //예를 들어 우연찮게 마지막 두 원소가 가장 작은 값과 가장 큰 값 혹은 이에 가까우면 효율이 끔찍해질 수 있다. 이 알고리즘 싫다. cpp09빨리할껄
    //그리고...
    while (pairs.size() > 1)
    {
        std::pair<unsigned int, unsigned int> target = pairs.back();
        pairs.pop_back();
        int left = std::lower_bound(vec.begin(), vec.end(), target.first) - vec.begin();
        int right = std::upper_bound(vec.begin(), vec.end(), target.second) - vec.begin() - 1;
		_mergeVec(vec, left, (left + right) / 2, right);
    }
    if (size % 2 == 1)
    {
        unsigned int last = vec[size - 1];
        int i;
        for (i = size - 2; i >= 0 && vec[i] > last; --i)
        {
            vec[i + 1] = vec[i];
        }
        vec[i + 1] = last;
    }
    //병합정렬 해도 완전히 정렬되지 않는다. 핵심 아이디어 : 삽입정렬은 어느 정도 정렬된 상태에선 효율적이다.
    _insertVec(vec, 0, size - 1);
}

// -------------------<DEQUE>-----------------------------

void PmergeMe::_mergeDeque(std::deque<unsigned int>& deq, int left, int mid, int right)
{
    int i = left;
	int j = mid + 1;
    std::deque<unsigned int> tmp;
    while (i <= mid && j <= right)
	{
        if (deq[i] < deq[j]) {
            tmp.push_back(deq[i++]);
        } else {
            tmp.push_back(deq[j++]);
        }
    }
    while (i <= mid)
        tmp.push_back(deq[i++]);
    while (j <= right)
        tmp.push_back(deq[j++]);
    for (size_t k = 0; k < tmp.size(); ++k) {
        deq[left + k] = tmp[k];
    }
}

void PmergeMe::_insertDeque(std::deque<unsigned int>& deq, int left, int right)
{
    unsigned int key;
    int j;
    for (int i = left + 1; i <= right; ++i)
    {
        key = deq[i];
        j = i - 1;
        while (j >= left && deq[j] > key)
        {
            deq[j + 1] = deq[j];
            --j;
        }
        deq[j + 1] = key;
    }
}

void PmergeMe::_fordJohnsonDeque(std::deque<unsigned int>& deq)
{
	std::deque<std::pair<unsigned int, unsigned int> > pairs;

    // 1. 페어로 죄다 만들어버린다. 중요한건, 페어로 만들어질때 작은 값이 오도록 정렬하는 것.
    int index = 0;
    int size = deq.size();
    for (; index < size - 1; index += 2) 
    {
        if (deq[index] > deq[index + 1])
        {
            pairs.push_back(std::make_pair(deq[index + 1], deq[index]));
        }
        else
        {
            pairs.push_back(std::make_pair(deq[index], deq[index + 1]));
        }
    }
    if (index == size - 1)
    {
        pairs.push_back(std::make_pair(deq[size - 1], deq[size - 1]));
    }

    // 2. 각 페어를 정렬하고, key보다 큰 페어가 등장하면 집어넣어야 한다. 그냥 삽입정렬로 해도
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        std::pair<unsigned int, unsigned int> first = pairs[i];
        int j = i - 1;
        while (j >= 0 && first < pairs[j])
        {
            pairs[j + 1] = pairs[j];
            --j;
        }
        pairs[j + 1] = first;
    }

    // 3. 이미 정렬된 페어를 병합. 모든 페어가 사라질 때까지.
    while (pairs.size() > 1)
    {
        std::pair<unsigned int, unsigned int> target = pairs.back();
		std::cout << "target.first " << target.first  << " target.second : " << target.second << std::endl;
        pairs.pop_back();
		_printContainer(deq);
        int left = std::lower_bound(deq.begin(), deq.end(), target.first) - deq.begin();
		std::cout << "upper_bound : " << std::upper_bound(deq.begin(), deq.end(), target.second) - deq.begin() << std::endl;
        int right = std::upper_bound(deq.begin(), deq.end(), target.second) - deq.begin() - 1;
		std::cout << "left : " << left << " right : " << right << std::endl;
		_mergeDeque(deq, left, (left + right) / 2, right);
    }
    if (size % 2 == 1)
    {
        int i;
        unsigned int last = deq[size - 1];
        for (i = size - 2; i >= 0 && deq[i] > last; --i)
        {
            deq[i + 1] = deq[i];
        }
        deq[i + 1] = last;
    }
    // 병합정렬 해도 완전히 정렬되지 않는다. 핵심 아이디어 : 삽입정렬은 어느 정도 정렬된 상태에선 효율적이다.
    _insertDeque(deq, 0, size - 1);
}

void	PmergeMe::sort()
{
	// vetor sort
	clock_t	start = std::clock();
	_fordJohnsonVec(this->_sortedVec);
	clock_t	end = std::clock();
	this->_vectorTime = static_cast<double>(end - start) / (double)1000;

	// deque sort
	start = std::clock();
	_fordJohnsonDeque(this->_sortedDeque);
	end = std::clock();
	this->_dequeTime = static_cast<double>(end - start) / (double)1000;
}

// -------------------<Utils>-----------------------------

bool	PmergeMe::_checkArgument(const int& argc, char** argv)
{
	size_t	k;
	for (int i(0); i < argc; ++i)
	{
		k = 0;
		while (std::isspace(static_cast<int>(argv[i][k])))
			k++;
		if (argv[i][k] == '+')
			k++;
		while (std::isdigit(static_cast<int>(argv[i][k])))
			k++;
		if (k == std::strlen(argv[i]))
		{
			unsigned int	num = _arryToInt(argv[i]);
			if (num < 0)
				return (false);
			_sortedDeque.push_back(num);
			_sortedVec.push_back(num);
			continue ;
		}
		return (false);
	}
	return (true);
}


unsigned int	PmergeMe::_arryToInt(const char *str)
{
	unsigned int	i;
	size_t			res;

	i = 0, res = 0;
	while (std::isspace(static_cast<int>(str[i])))
		i++;
	if (str[i] == '+')
		i++;
	while (std::isdigit(str[i]) && *str)
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (res > 4294967295)
		throw InvalidArgument();
	return (res);
}

void	PmergeMe::_printContainer(const std::vector<unsigned int>& vec)
{
	for (std::vector<unsigned int>::const_iterator	it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::_printContainer(const std::deque<unsigned int>& deq)
{
	for (std::deque<unsigned int>::const_iterator	it = deq.begin(); it != deq.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}



void	PmergeMe::printRes()
{
	std::cout << "After:	"; 
	_printContainer(this->_sortedVec);
	//std::cout << "=======================\n";
	//std::cout << ((std::is_sorted(_sortedVec.begin(), _sortedVec.end()) == true) ?  "Vector Sorted" : "Vector Not sorted") << std::endl;
	//std::cout << ((std::is_sorted(_sortedDeque.begin(), _sortedDeque.end()) == true) ? "Deque Sorted" : "Deque Not sorted") << std::endl;
	//std::cout << "=======================\n";
	std::cout << "Time to process a range of " << this->_argc << " elements with std::vector : " << this->_vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_argc << " elements with std::deque  : " << this->_dequeTime << " us" << std::endl;
}
