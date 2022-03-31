#include "setFunctions.h"
#include "set.h"
#include "set.cpp"
#include <cmath>

using namespace std;

// Returns a set that is the Union of the two sets s1 and s2
Set<char> setUnion(const Set<char> &s1, const Set<char> &s2)
{
    Set<char> result;

    size_t setLengths1 = s1.cardinality();
    for (size_t i = 0; i < setLengths1; ++i)
    {
        result.insertElement(s1[i]);
    }

    size_t setLengths2 = s2.cardinality();
    for (size_t i = 0; i < setLengths2; ++i)
    {
        result.insertElement(s2[i]);
    }

    return result;
}

// Returns a set that is the intersection of the two sets s1 and s2
Set<char> setIntersection(const Set<char> &s1, const Set<char> &s2)
{
    Set<char> result;

    size_t setLength = s1.cardinality();
    for (size_t i = 0; i < setLength; ++i)
    {
        if (s2.isElement(s1[i]))
            result.insertElement(s1[i]);
    }

    return result;
}

// Returns a set that is the s1 - s2
Set<char> setDiff(const Set<char> &s1, const Set<char> &s2)
{
    Set<char> result;
    size_t setLengths1 = s1.cardinality();

    for (size_t i = 0; i < setLengths1; ++i)
    {
        if (!(s2.isElement(s1[i])))
            result.insertElement(s1[i]);
    }

    return result;
}

// Returns a set that is the symmetric difference of the two sets s1 and s2
Set<char> setSymDiff(const Set<char> &s1, const Set<char> &s2)
{
    Set<char> result;

    size_t setLengths1 = s1.cardinality();
    for (size_t i = 0; i < setLengths1; ++i)
    {
        if (!(s2.isElement(s1[i])))
            result.insertElement(s1[i]);
    }

    size_t setLengths2 = s2.cardinality();
    for (size_t i = 0; i < setLengths2; ++i)
    {
        if (!(s1.isElement(s2[i])))
            result.insertElement(s2[i]);
    }

    return result;
}

// Returns true if s1 is a subset of s2
bool isSubSet(const Set<char> &s1, const Set<char> &s2)
{
    size_t setLengths1 = s1.cardinality();
    bool subset = true;

    int index{0};
    while (subset && (index < setLengths1))
    {
        if (!s2.isElement(s1[index]))
        {
            subset = false;
        }
        ++index;
    }

    return subset;
}

// Returns true if s1 is a proper subset of s2
bool isProperSubSet(const Set<char> &s1, const Set<char> &s2)
{
    // Add your code here and return the correct truth value
    bool properSubset{false};

    if ((isSubSet(s1, s2)) && (s1.cardinality() != s2.cardinality()))
        properSubset = true;

    return properSubset;
}

// Returns the Power Set of set s as a set of sets
Set<Set<char>> PowerSet(const Set<char> &s)
{
    Set<Set<char>> result;
    size_t setLength = s.cardinality();
    size_t powerLength = 1 << setLength;

    for (size_t i = 0; i < powerLength; ++i)
    {
        Set<char> temp;
        for (size_t j = 0; j < setLength; ++j)
        {
            if (i & (1 << j))
                temp.insertElement(s[j]);
        }
        result.insertElement(temp);
    }
    return result;
}

// Returns true if the sets in p make up a Partition of set s
bool isPartition(const Set<Set<char>> &p, const Set<char> &s)
{
    bool result{true};
    size_t setLength = p.cardinality();

    if (!setLength)
    {
        result = false;
    } else
    {
        Set<char> temp;
        for (size_t i{0}; i < setLength; ++i)
        {
            size_t partSetLength = p[i].cardinality();
            for (size_t j{0}; j < partSetLength; ++j)
                temp.insertElement(p[i][j]);
        }
        temp == s ? result = true : result = false;
    }
    return result;
}