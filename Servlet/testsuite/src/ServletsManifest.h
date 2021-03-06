//
// ServletsManifest.h
//
//
// Library: TestServlet
// Package: TestServlet
// Module:  ServletsManifest
//
// Definition of the ServletsManifest class.
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


#ifndef Servlet_ServletsManifest_INCLUDED
#define Servlet_ServletsManifest_INCLUDED


#include "Poco/ClassLibrary.h"
#include "Poco/Servlet/HttpServlet.h"
#include "TestServlet.h"


POCO_BEGIN_MANIFEST(Poco::Servlet::HttpServlet)
	using Poco::Servlet::TestServlet;
	using Poco::Servlet::SingletonTestServlet;
	using Poco::Servlet::DefaultTestServlet;
	using Poco::Servlet::FormTestServlet;
	using Poco::Servlet::JSPTestServlet;
	using Poco::Servlet::ForwardTestServlet;
	using Poco::Servlet::ForwardedTestServlet;
	using Poco::Servlet::IncludeTestServlet;
	using Poco::Servlet::IncludedTestServlet;
	using Poco::Servlet::RefreshTestServlet;

	POCO_EXPORT_CLASS(TestServlet)
	POCO_EXPORT_SINGLETON(SingletonTestServlet)
	POCO_EXPORT_CLASS(DefaultTestServlet)
	POCO_EXPORT_CLASS(FormTestServlet)
	POCO_EXPORT_CLASS(JSPTestServlet)
	POCO_EXPORT_CLASS(ForwardTestServlet)
	POCO_EXPORT_CLASS(ForwardedTestServlet)
	POCO_EXPORT_CLASS(IncludeTestServlet)
	POCO_EXPORT_CLASS(IncludedTestServlet)
	POCO_EXPORT_CLASS(RefreshTestServlet)
POCO_END_MANIFEST


#endif //Servlet_ServletsManifest_INCLUDED

