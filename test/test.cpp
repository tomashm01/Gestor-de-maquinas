#include "test.h"
#include "cute.h"

void thisIsAtestTest() {
	ASSERTM("start writing tests", false);
}

cute::suite make_suite_test() {
	cute::suite s { };
	s.push_back(CUTE(thisIsAtestTest));
	return s;
}
