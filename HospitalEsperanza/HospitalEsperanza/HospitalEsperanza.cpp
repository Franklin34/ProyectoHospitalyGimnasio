#include "Contenedor.h"
#include "Control.h"
#include "Doctor.h"
#include <iostream>

int main()
{
	system("color 1f");
	Control* c = new Control();
	c->controlPrincipal();
	delete c;
    
}

