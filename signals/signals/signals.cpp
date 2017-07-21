// signals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>

#include <Windows.h>

#include <boost\signals2.hpp>

using namespace boost::signals2;

void Hello() {
	std::cout << "Hello";
}

void World() {
	std::cout << " World!";
}

int main()
{
	signal< void () > _signal;

	_signal.connect(Hello);
	_signal.connect(World);

	_signal();
	
	int pause;
	std::cin >> pause;

    return 0;
}

