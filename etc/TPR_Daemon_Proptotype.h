/**
  * File TPR_Daemon_Prototype.h (it can be named "engine" or something like that).
  * Conventions:
  * 1)File naming convention: as Class name + .h for headers and .cpp for implementation.
  * 2)Class naming convention All class names must begin with "TPR_" - abbreviation of the
  * Tipra (TIny PRinters Assistant... or Assasin uhahah), name of the product. Next, name of 
  * the "package" (Daemon, GUI, Database), another "_" delimeter and real class name 
  * (Prototype, i.e.).
  */

#pragma once  
#ifndef _TPR_DAEMON_PROTOTYPE_ //include guards: all the letters are capital, begins and ends with "_"
#define _TPR_DAEMON_PROTOTYPE_

/**
  * Including convention: Include only what you will use in THIS file. 
  * Usually, you don't use anything in headers, just declare it. So, use 
  * declaration instead of inclusion for acceleration of the building after 
  * headers modifications.
  */
#include <list>
#include <string>
class TPR_Daemon_PrinterInfo;

class TPR_Daemon_Prototype
{
/** 
  * Don't tabify public/private keywords. 
  * Don't mix methods and fields.
  * Don't use public fields.
  */
public: //public methods;
    TPR_Daemon_Prototype();
	TPR_Daemon_Prototype(TPR_Daemon_WrapperConnector* theWrapper);
	~TPR_Daemon_Prototype();
	
					 //Give names for parameters in headers explicitly (theParameter).
	void 			setWrapperConnector( TPR_Daemon_WrapperConnector* theWrapper);
	std::string 	watch();
	void 			addPrinter( TPR_Daemon_PrinterInfo* );
	bool 			removePrinter( TPR_Daemon_PrinterInfo* );
	
private: //private methods;
	//Just for example, of course i delegate all private logic to you. 
	TPR_Daemon_PrinterInfo* 	statusChanged();
	bool 						observablePrinter();
	
private: //private fields;
    /**
	  * Fields and varibles naming convention: 
	  * use "m_" in the beginning of the FIELDs names (means my).
	  * First letter(s) means type of variable, use "p" for pointers, 
	  * "b" - boolean, "c" - char, "lt" - list, "map" - guess what, etc.
	  */
	std::list<TPR_Daemon_PrinterInfo> 	m_ltPrinters;
	TPR_Daemon_WrapperConnector*		m_pWrapperConnector; //Probably, will be writen by me (Qt needed).
};

#endif //_TPR_DAEMON_PROTOTYPE_

/**
  * File TPR_Daemon_Prototype.cpp (This is another file, i concatenate them for easement).
  */

TPR_Daemon_Prototype::TPR_Daemon_Prototype()
{
	
}
  /** Constructors, blah blah blah... 
    * Brackets conventions:
	* Put "{" on next line only after methods implementation i.e. method()\n{ _body_; \n}\n
	* Always put next line after "}" bracket.
	* Use spacing in () brackets for logical and visual indentation.
	*/
 
 /**
   * Kick-ass smart method.
   */
std::string watch()
{
	if( observablePrinter(statusChanged()) ){
		//Ring a Ding Ding Baby...
	} else {
		//Or not =)
	}
}

/** 
  * Something like this. =)
  */
  