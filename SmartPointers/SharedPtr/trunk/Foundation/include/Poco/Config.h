//
// Config.h
//
// $Id: //poco/svn/Foundation/include/Poco/Config.h#3 $
//
// Library: Foundation
// Package: Core
// Module:  Foundation
//
// Feature configuration for the POCO libraries.
//
// Copyright (c) 2006-2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
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


#ifndef Foundation_Config_INCLUDED
#define Foundation_Config_INCLUDED


// Define to enable Windows Unicode (UTF-8) support
// #define POCO_WIN32_UTF8


// Define to disable implicit linking
// #define POCO_NO_AUTOMATIC_LIBS


// Define to disable FPEnvironment support
// #define POCO_NO_FPENVIRONMENT


// Define if std::wstring is not available
// #define POCO_NO_WSTRING


// Define to disable shared memory
// #define POCO_NO_SHAREDMEMORY


// Define to desired default thread stack size
// Zero means OS default
#define POCO_THREAD_STACK_SIZE 0


#endif // Foundation_Config_INCLUDED
