#ifndef __DATE_H
#define __DATE_H

#include <iostream>

struct Date {
	int day;
	int month;
	int year;
};


std::ostream &operator<<(std::ostream &os, Date d);
#endif
