#include "MagicalContainer.hpp"

using namespace ariel;

void MagicalContainer::addElement(int newElement)
{
    elements.push_back(newElement);
}

void MagicalContainer::removeElement(int index)
{
    // if (index < 0 || index >= this->elements.size())
    // {
    //     throw invalid_argument ("Invalid index!");

    //     return;
    // }

    // elements.erase(elements.begin() + index);
}

int MagicalContainer::size()
{
    return this->elements.size();
}

vector<int>& MagicalContainer::getElements() 
{
    return this->elements;
}

bool isPrime(int num)
{
    if (num < 2) 
    {
        return false;
    }
    
    for (int i=2; i <= sqrt(num); ++i) 
    {
        if (num % i == 0) 
        {
            return false;
        }
    }
    
    return true;
}

// void findNextPrime()
// {
//     while (this->index != end && !isPrime(*current)) 
//     {
//         ++current;
//     }
// }

/********************** Iterators implementation area **********************/

/********************** AscendingIterator **********************/       
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
    {
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return this->index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return this->index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return this->index < other.index;
}

int MagicalContainer::AscendingIterator::operator*() const //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
{
    //return container.getElements()[static_cast<vector<int>::size_type>(index)];
    return 1;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    ++index;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(*this);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    // AscendingIterator itr (this*);
    // itr.index += size;

    // return itr;
    return *this;
}

/********************** SideCrossIterator **********************/       
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this != &other)
    {
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    //return this->index == other.index && end == other.end;
    return true;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return this->index > other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return this->index < other.index;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    //return container.getElements()[static_cast<vector<int>::size_type>(index)];
    return 1;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    // if (this->index == end)
    // {
    //     this->index = end - 1;
    // }
    // else if (current == end - 1)
    // {
    //     current = end;
    // }
    // else
    // {
    //     ++current;
    // }
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator:: begin()
{
    return SideCrossIterator(*this);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    return *this;
}


/********************** PrimeIterator **********************/       
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this != &other)
    {
        this->index = other.index;
        //end = other.end;
    }
    
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    //return current == other.current && end == other.end;
    return 1;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return this->index > other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return this->index < other.index;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    //return *current;
    return 1;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    ++index;
    //findNextPrime();
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    //return PrimeIterator(*this);
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator:: end()
{
    //return PrimeIterator(elements + size, elements + size);
    return *this;
}

