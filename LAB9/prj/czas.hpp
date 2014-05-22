#ifndef CZAS_HPP
#define CZAS_HPP

#include <windows.h>
/*! 
	* \file
	* \brief Definicja startTimer
	*
	*  Powoduje start zegara.

*/
LARGE_INTEGER startTimer();
/*! 
	* \file
	* \brief Definicja endTimer
	*
	*  Powoduje stop zegara.

*/
LARGE_INTEGER endTimer();

#endif
