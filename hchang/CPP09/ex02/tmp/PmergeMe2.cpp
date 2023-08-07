#include "PmergeMe.hpp"

//집어넣고 오류처리
void PmergeMe::initVec(char** numStr)
{
    int i = -1;
    while (numStr[++i])
    {
        if (!isNumber(numStr[i]))
            throw std::runtime_error("Error");
        vec.push_back(atoi(numStr[i]));
        if (vec.back() != atol(numStr[i]))
            throw std::runtime_error("Error: unsigned int overflow");
    }
}
void PmergeMe::mergeVec(std::vector<unsigned int>& vec, int left, int mid, int right)
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
void    PmergeMe::insertVec(std::vector<unsigned int>& vec, int left, int right)
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
void    PmergeMe::fordJohnsonVec(std::vector<unsigned int>& vec)
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
        std::pair<unsigned int, unsigned int> p = pairs.back();
        pairs.pop_back();
        int left = std::lower_bound(vec.begin(), vec.end(), p.first) - vec.begin();
        int right = std::upper_bound(vec.begin(), vec.end(), p.second) - vec.begin() - 1;
        if (right - left <= 5)
        {
            insertVec(vec, left, right);
        }
        else
        {
            mergeVec(vec, left, (left + right) / 2, right);
        }
    }
    if (n % 2 == 1)
    {
        unsigned int last = vec[n - 1];
        int i;
        for (i = n - 2; i >= 0 && vec[i] > last; --i)
        {
            vec[i + 1] = vec[i];
        }
        vec[i + 1] = last;
    }
    //병합정렬 해도 완전히 정렬되지 않는다. 핵심 아이디어 : 삽입정렬은 어느 정도 정렬된 상태에선 효율적이다.
    insertVec(vec, 0, n-1);
}