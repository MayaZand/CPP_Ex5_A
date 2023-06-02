#include "doctest.h"

#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("check all MagicalContainer methods")
{
    MagicalContainer mc, mc2;
    
    CHECK (mc.size() == 0);
    // add 3 elements to the container
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);
    
    CHECK (mc.size() == 5);
    
    // remove the LAST element
    mc.removeElement(4); 

    CHECK(mc.size() == 4);
    
    // Should throw an error on the deletion of an element in the index that does not exist in the container
    CHECK_THROWS(mc.removeElement(4)); 
    
    // remove another (random) element from the container
    mc.removeElement(1);

    CHECK(mc.size() == 3);

    CHECK_NOTHROW(mc.removeElement(1));

    //add 2 elements and than delete 2 elements. suppose to throw an error.
    mc2.addElement(1);
    mc2.addElement(2);
    
    CHECK (mc2.size() == 2);
    CHECK_THROWS(mc2.removeElement(-1)); // There are no negative indexes in vector

    mc2.removeElement(0); 
    mc2.removeElement(1); 

    CHECK (mc2.size() == 0);
    CHECK_THROWS(mc2.removeElement(1));
    CHECK_THROWS(mc2.removeElement(1));
}

TEST_CASE("AscendingIterator checks")
{
    MagicalContainer mc;
    mc.addElement(0);
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    
    MagicalContainer::AscendingIterator ascndIt(mc);
    
    CHECK(*ascndIt == 0);
    ++ascndIt;

    CHECK(*ascndIt == 1);
    ++ascndIt;

    CHECK(*ascndIt == 2);
    ++ascndIt;

    CHECK(*ascndIt == 3);
    ++ascndIt;
}

TEST_CASE("PrimeIterator checks")
{
    MagicalContainer mc, mc2;
    mc.addElement(0);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(7);
    mc.addElement(8);
    mc.addElement(11);
    mc.addElement(19);

    mc2.addElement(1);
    mc2.addElement(4);
    mc2.addElement(8);
    mc2.addElement(10);

    MagicalContainer::PrimeIterator prmIt(mc);
    MagicalContainer::PrimeIterator prmIt2(mc2);

    CHECK(*prmIt == 2);
    ++prmIt;

    CHECK(*prmIt == 3);
    ++prmIt;

    CHECK(*prmIt == 7);
    ++prmIt;

    CHECK(*prmIt == 11);
    ++prmIt;
    
    CHECK(*prmIt == 19);
    ++prmIt;

    CHECK(&prmIt2 == nullptr); // no prime numbers in mc2
    ++prmIt2;
    
    CHECK(&prmIt2 == nullptr);

}