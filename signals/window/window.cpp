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
	static signal< void( ) > _click;

	void click() {
		std::cout << "before click" << std::endl;
		_click();
		std::cout << "after click" << std::endl;
	}
};

signal< void() > Button::_click;

class Window {
public:
	Window() {
		Button::_click.connect(boost::bind(&Window::refresh, this ));
	}
	~Window() {}

public:
	void refresh() {
		std::cout << "refresh window" << std::endl;
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
		Button::_click.connect(boost::bind(&List::refresh, this ));
	}
	~List(){}

public:
	void refresh() {
		std::cout << "refresh list" << std::endl;
	}
};


int main()
{
	Window w;
	List l;
	Button b;
	
	b.click();

	int pause;
	std::cin >> pause;

	return 0;
}
