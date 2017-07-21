// window.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>

#include <boost\signals2.hpp>
#include <boost\bind.hpp>

using namespace boost::signals2;



class Button {
public:
	Button() {}
	~Button() {}

public:
	static signal< void() > _click;
};

class Window {
public:
	Window() {
		Button::_click.connect(boost::bind(&Window::refresh, this, _1));
	}
	~Window() {}

public:
	void refresh() {

	}
};

class Input {
public:
	Input(){}
	~Input(){}
};

class List {
public:
	List(){
		Button::_click.connect(boost::bind(&List::refresh, this, _1));
	}
	~List(){}

public:
	void refresh() {
		std::cout << "refresh list" << std::endl;
	}
};


int main()
{
	signal< void() > _signal;

	//_signal.connect(Hello);
	//_signal.connect(World);

	//_signal();

	int pause;
	std::cin >> pause;

	return 0;
}
