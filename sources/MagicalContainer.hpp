#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace ariel
{

    class MagicalContainer
    {
    private:
        vector<int> elements;

        static bool isPrime(int num);

    public:
        /* constructor & destructor: */
        MagicalContainer(){};

        ~MagicalContainer(){};

        /* METHODS: */
        void addElement(int element);

        void removeElement(int index);

        int size();

        vector<int>& getElements();

        /********************** Iterators - nested classes **********************/

        /* Ascending Iterator*/
        class AscendingIterator
        {
        private:
            MagicalContainer& container;
            int index;

        public:
            
            /* constructors & destructor: */
            AscendingIterator(MagicalContainer& container, int index): container(container), index(index){}
            AscendingIterator(MagicalContainer& container): container(container), index(0){};
            AscendingIterator(AscendingIterator& other): container(other.container), index(other.index){};
            ~AscendingIterator() {}

            /* METHODS: */
            

            AscendingIterator& operator=(const AscendingIterator& other);

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator& operator++();

            AscendingIterator begin();

            AscendingIterator end();
        };

        /* Side Cross Iterator*/
        class SideCrossIterator
        {
        private:
            MagicalContainer& container;
            int index;

        public:
            
            /* constructors & destructor: */
            SideCrossIterator(MagicalContainer& container, int index): container(container), index(index){}
            SideCrossIterator(MagicalContainer& container): container(container), index(0){};
            SideCrossIterator(SideCrossIterator& other): container(other.container), index(other.index){};
            ~SideCrossIterator() {}

            /* METHODS: */
            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            int operator*() const;

            SideCrossIterator &operator++();

            SideCrossIterator begin();

            SideCrossIterator end();
        };

        /* Prime Iterator */
        class PrimeIterator
        {
        private:
            MagicalContainer& container;
            int index;

        public:

            /* constructor & destructor: */

            PrimeIterator(MagicalContainer& container, int index): container(container), index(index){}
            PrimeIterator(MagicalContainer& container): container(container), index(0){};
            PrimeIterator(PrimeIterator& other): container(other.container), index(other.index){};
            ~PrimeIterator() {}
            
            /* METHODS: */
            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator& operator++();

            PrimeIterator begin();

            PrimeIterator end();
        };
    };
}
