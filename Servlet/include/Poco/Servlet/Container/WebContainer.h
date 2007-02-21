//
// WebContainer.h
//
//
// Library: Container
// Package: ContainerCore
// Module:  WebContainer
//
// Definition of the WebContainer class.
//
// Copyright (c) 2006, Aleksandar Fabijanic and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

#ifndef Container_WebContainer_INCLUDED
#define Container_WebContainer_INCLUDED


#include "Poco/TaskManager.h"
#include "Poco/Runnable.h"
#include "Poco/Logger.h"
#include "Poco/Servlet/Container/ContainerBase.h"
#include "Poco/Servlet/Ex/HttpServletDispatcher.h"
#include "Poco/Servlet/Ex/FilterDispatcher.h"


namespace Poco {
namespace Servlet {
namespace Container {


class Container_API WebContainer : public Poco::Runnable
	/// Application container class. This class loads Contained entities
	/// (servlets and servers). 
{
public:

	WebContainer(const std::string& rootDir,
					  const std::string& webAppDir,
					  const std::string& webSrvDir,
						Poco::Logger* pLogger=0);
	 /// Constructor

	~WebContainer();
	 /// Destructor.

	void init();
	 /// Initialization method. Loads container's web.xml and fills in
	 /// default values and mime types map.
	 
	void run();
	 /// Function that runs the container. It contains TaskManager which
	 /// starts two types of tasks:
	 ///
	 ///		1) WebServer task - loads all the servers it finds properly
	 ///			 configured in the container server directory.
	 ///
	 ///		2) WebApplication task - registers al the servlets it finds properly
	 ///			 configured in the container servlets directory. Servlets configured as
	 ///			 load on startup are loaded on startup, others are loaded on demand.

	void stop();
		/// Stops the container.

	bool isRunning();
		/// Indicates whether the container has completed initialization and is running.

private:
	WebContainer();
	
	Poco::TaskManager                        _taskManager;
	Poco::Logger*                            _pLogger;
	std::string                              _rootDir;
	std::string                              _webAppDir;
	std::string                              _webSrvDir;
	Poco::Servlet::Ex::HttpServletDispatcher _servletDispatcher;
	Poco::Servlet::Ex::FilterDispatcher	     _filterDispatcher;
	bool                                     _stop;
	bool                                     _running;
};


} } } // namespace Poco::Servlet::Container


#endif //Container_WebContainer_INCLUDED