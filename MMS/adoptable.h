#ifndef __ADOPTABLE_H
#define __ADOPTABLE_H

#include "date.h"
#include <string>


enum AdoptableType { ALL, TURTLE, CAT, DOG };

class Adoptable {
	

public:

	


	Adoptable(double m_weight, bool m_has_shots, Date m_adoptable_since, std::string m_first_name
		, std::string m_last_name, AdoptableType m_type){
		weight = m_weight;
		has_shots = m_has_shots;
		adoptable_since = m_adoptable_since;
		first_name = m_first_name;
		last_name = m_last_name;
		type = m_type;
	}

  virtual bool hasRestrictions(std::string &);

  void print();

  AdoptableType getType() const;

  bool hasShot() const;

  std::string getFirstName() const;
  std::string getLastName() const;

private:
	
	double weight;
	bool has_shots;
	std::string first_name;
	std::string last_name;
	Date adoptable_since;
	AdoptableType type;
	
};




class Turtle : public Adoptable {
public:
	
	Turtle(double weight, bool has_shots, Date adoptable_since, std::string first_name, std::string last_name) :
		Adoptable(weight, has_shots, adoptable_since, first_name, last_name, TURTLE)
	{
	}
		


};

class Dog : public Adoptable {
public:

	Dog(double weight, bool has_shots, Date adoptable_since, std::string first_name, std::string last_name) :
		Adoptable(weight, has_shots, adoptable_since, first_name, last_name, DOG)
	{
	}

};

class Cat : public Adoptable {
public:
	Cat(double weight, bool has_shots, Date adoptable_since, std::string first_name, std::string last_name) :
		Adoptable(weight, has_shots, adoptable_since, first_name, last_name,CAT)
	{}


};

#endif