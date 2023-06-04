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

TEST_CASE("AscendingIterator checks") // Should return the numbers in ascending order
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

TEST_CASE("PrimeIterator checks") // Should only return the prime numbers, in order
{
    MagicalContainer mc, mc2;
    mc.addElement(3);
    mc.addElement(0);
    mc.addElement(8);
    mc.addElement(2);
    mc.addElement(7);
    mc.addElement(11);
    mc.addElement(19);

    mc2.addElement(1);
    mc2.addElement(4);
    mc2.addElement(8);
    mc2.addElement(10);

    MagicalContainer::PrimeIterator prmIt(mc);
    MagicalContainer::PrimeIterator prmIt2(mc2);

    CHECK(*prmIt == 2);
    CHECK_FALSE(*prmIt != 2); // check also false statments
    ++prmIt;

    CHECK(*prmIt == 3);
    CHECK_FALSE(*prmIt != 3);
    ++prmIt;

    CHECK(*prmIt == 7);
    CHECK_FALSE(*prmIt != 7);
    ++prmIt;

    CHECK(*prmIt == 11);
    CHECK_FALSE(*prmIt != 11);
    ++prmIt;
    
    CHECK(*prmIt == 19);
    CHECK_FALSE(*prmIt != 19);
    ++prmIt;

    CHECK(&prmIt2 == nullptr); // no prime numbers in mc2
    ++prmIt2;
    
    CHECK(&prmIt2 == nullptr); // no prime numbers in mc2
}


TEST_CASE("SideCrossIterator checks")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(5);
    mc.addElement(2);
    mc.addElement(14);
        
    MagicalContainer::SideCrossIterator sideIt(mc); 
    
    CHECK(*sideIt == 1);
    ++sideIt;
    
    CHECK_FALSE(*sideIt == 5);
    CHECK(*sideIt == 14);
    ++sideIt;
    
    CHECK(*sideIt == 2);
    ++sideIt;

    CHECK(*sideIt == 5);
}

TEST_CASE("operators < and == check")
{
    MagicalContainer mc1, mc2, mc3;
    mc1.addElement(1); // should be this order: 1, 2, 3, 4
    mc1.addElement(2);
    mc1.addElement(3);
    mc1.addElement(4);
    
    mc2.addElement(40); // should be this order: 10, 40, 20, 30
    mc2.addElement(20);
    mc2.addElement(10);
    mc2.addElement(30);
    
    mc3.addElement(1); // should be this order: 2, 3, 5, 7, 11
    mc3.addElement(2);
    mc3.addElement(3);
    mc3.addElement(7);
    mc3.addElement(5);
    mc3.addElement(12);
    mc3.addElement(11);

    MagicalContainer::AscendingIterator ascndIt(mc1);
    MagicalContainer::SideCrossIterator sideIt(mc2); 
    MagicalContainer::SideCrossIterator sideIt2(mc2); 
    MagicalContainer::PrimeIterator primeIt(mc3);

    CHECK((sideIt == sideIt2)); // point at the same container
    
//   CHECK(ascndIt.begin() < ascndIt.end());
//     CHECK(*(ascndIt.begin()) == 1);
//     CHECK(*(ascndIt.end()) == 4);
    
//     CHECK(primeIt.begin() < primeIt.end());
//     CHECK(*(primeIt.begin()) == 2);
//     CHECK(*(primeIt.end()) == 11);
//     CHECK_FALSE(*(primeIt.begin()) == 1);
    
//     CHECK(sideIt.begin() < sideIt.end());
//     CHECK(*(sideIt.begin()) == 10);
//     CHECK_FALSE(*(sideIt.begin()) == 40);
//     CHECK(*(sideIt.end()) == 30);
}