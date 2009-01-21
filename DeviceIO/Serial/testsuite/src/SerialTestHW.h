//
// SerialTestHW.h
//
// $Id: //poco/Main/template/test.h#7 $
//
// Definition of the SerialTestHW class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
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


#ifndef SerialTestHW_INCLUDED
#define SerialTestHW_INCLUDED


#include "Poco/DeviceIO/Serial/Serial.h"
#include "CppUnit/TestCase.h"
#include "Poco/BinaryReader.h"
#include "Poco/BinaryWriter.h"
#include "Poco/DeviceIO/Channel.h"
#include "Poco/DeviceIO/ChannelStream.h"
#include "Poco/DeviceIO/Serial/SerialConfig.h"
#include "Poco/DeviceIO/Serial/SerialChannel.h"


class SerialTestHW: public CppUnit::TestCase
	/// In order for these tests to work, two null-modem wired 
	/// serial ports are required.
{
public:
	typedef Poco::DeviceIO::ChannelInputStream SerialInputStream;
	typedef Poco::DeviceIO::ChannelOutputStream SerialOutputStream;
	
	SerialTestHW(const std::string& name);
	~SerialTestHW();

	void testChannel();
	void testActiveChannel();
	void testStreams();
	void testBinary();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
	void writeBinary(Poco::BinaryWriter& writer);
	void readBinary(Poco::BinaryReader& reader);

	Poco::DeviceIO::Serial::SerialConfig* _pConfig1;
	Poco::DeviceIO::Serial::SerialConfig* _pConfig2;
};


#endif // SerialTestHW_INCLUDED