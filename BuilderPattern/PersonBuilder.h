#include "Person.h"
#ifndef PERSONBUILDER_H
#define PERSONBUILDER_H
class PersonBuilder
{
    Person person;

public:
    PersonBuilder(string name) : person(name) {}

    operator Person() const { return move(person); }

    PersonBuilder&  lives();
    PersonBuilder&  at(std::string street_address);
    PersonBuilder&  with_postcode(std::string post_code);
    PersonBuilder&  in(std::string city);
    PersonBuilder&  works();
    PersonBuilder&  with(string company_name);
    PersonBuilder&  as_a(string position);
    PersonBuilder&  earning(string annual_income);
};
#endif