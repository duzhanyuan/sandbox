//
// StreamConverterTest.cpp
//
// $Id: //poco/svn/Foundation/testsuite/src/StreamConverterTest.cpp#2 $
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
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


#include "StreamConverterTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/StreamConverter.h"
#include "Poco/ASCIIEncoding.h"
#include "Poco/Latin1Encoding.h"
#include "Poco/UTF8Encoding.h"
#include "Poco/StreamCopier.h"
#include <sstream>


using Poco::InputStreamConverter;
using Poco::OutputStreamConverter;
using Poco::Latin1Encoding;
using Poco::UTF8Encoding;
using Poco::ASCIIEncoding;
using Poco::StreamCopier;


StreamConverterTest::StreamConverterTest(const std::string& name): CppUnit::TestCase(name)
{
}


StreamConverterTest::~StreamConverterTest()
{
}


void StreamConverterTest::testIdentityASCIIIn()
{
	ASCIIEncoding encoding;
	
	std::istringstream istr1("");
	std::ostringstream ostr1;
	InputStreamConverter converter1(istr1, encoding, encoding);
	StreamCopier::copyStream(converter1, ostr1);
	assert (ostr1.str() == "");
	assert (converter1.errors() == 0);
	
	std::istringstream istr2("foo bar");
	std::ostringstream ostr2;
	InputStreamConverter converter2(istr2, encoding, encoding);
	StreamCopier::copyStream(converter2, ostr2);
	assert (ostr2.str() == "foo bar");
	assert (converter2.errors() == 0);

	std::istringstream istr3("x");
	std::ostringstream ostr3;
	InputStreamConverter converter3(istr3, encoding, encoding);
	StreamCopier::copyStream(converter3, ostr3);
	assert (ostr3.str() == "x");
	assert (converter3.errors() == 0);
}


void StreamConverterTest::testIdentityASCIIOut()
{
	ASCIIEncoding encoding;
	
	std::ostringstream ostr1;
	OutputStreamConverter converter1(ostr1, encoding, encoding);
	converter1 << "";
	assert (ostr1.str() == "");
	assert (converter1.errors() == 0);
	
	std::ostringstream ostr2;
	OutputStreamConverter converter2(ostr2, encoding, encoding);
	converter2 << "foo bar";
	assert (ostr2.str() == "foo bar");
	assert (converter2.errors() == 0);

	std::ostringstream ostr3;
	OutputStreamConverter converter3(ostr3, encoding, encoding);
	converter3 << "x";
	assert (ostr3.str() == "x");
	assert (converter3.errors() == 0);
}


void StreamConverterTest::testIdentityUTF8In()
{
	UTF8Encoding encoding;
	
	std::istringstream istr1("");
	std::ostringstream ostr1;
	InputStreamConverter converter1(istr1, encoding, encoding);
	StreamCopier::copyStream(converter1, ostr1);
	assert (ostr1.str() == "");
	assert (converter1.errors() == 0);
	
	std::istringstream istr2("foo bar");
	std::ostringstream ostr2;
	InputStreamConverter converter2(istr2, encoding, encoding);
	StreamCopier::copyStream(converter2, ostr2);
	assert (ostr2.str() == "foo bar");
	assert (converter2.errors() == 0);

	std::istringstream istr3("x");
	std::ostringstream ostr3;
	InputStreamConverter converter3(istr3, encoding, encoding);
	StreamCopier::copyStream(converter3, ostr3);
	assert (ostr3.str() == "x");
	assert (converter3.errors() == 0);
	
	const unsigned char greek[] = {0x20, 0xce, 0xba, 0xe1, 0xbd, 0xb9, 0xcf, 0x83, 0xce, 0xbc, 0xce, 0xb5, 0x20, 0x00};
	std::string text((const char*) greek);

	std::istringstream istr4(text);
	std::ostringstream ostr4;
	InputStreamConverter converter4(istr4, encoding, encoding);
	StreamCopier::copyStream(converter4, ostr4);
	assert (ostr4.str() == text);
	assert (converter4.errors() == 0);
}


void StreamConverterTest::testIdentityUTF8Out()
{
	UTF8Encoding encoding;
	
	std::ostringstream ostr1;
	OutputStreamConverter converter1(ostr1, encoding, encoding);
	converter1 << "";
	assert (ostr1.str() == "");
	assert (converter1.errors() == 0);
	
	std::ostringstream ostr2;
	OutputStreamConverter converter2(ostr2, encoding, encoding);
	converter2 << "foo bar";
	assert (ostr2.str() == "foo bar");
	assert (converter2.errors() == 0);

	std::ostringstream ostr3;
	OutputStreamConverter converter3(ostr3, encoding, encoding);
	converter3 << "x";
	assert (ostr3.str() == "x");
	assert (converter3.errors() == 0);
	
	const unsigned char greek[] = {0x20, 0xce, 0xba, 0xe1, 0xbd, 0xb9, 0xcf, 0x83, 0xce, 0xbc, 0xce, 0xb5, 0x20, 0x00};
	std::string text((const char*) greek);

	std::ostringstream ostr4;
	OutputStreamConverter converter4(ostr4, encoding, encoding);
	converter4 << text;
	assert (ostr4.str() == text);
	assert (converter4.errors() == 0);
}


void StreamConverterTest::testUTF8toASCIIIn()
{
	UTF8Encoding utf8Encoding;
	ASCIIEncoding asciiEncoding;

	const unsigned char greek[] = {0x20, 0xce, 0xba, 0xe1, 0xbd, 0xb9, 0xcf, 0x83, 0xce, 0xbc, 0xce, 0xb5, 0x20, 0x41, 0x42, 0x00};
	std::string text((const char*) greek);

	std::istringstream istr1(text);
	std::ostringstream ostr1;
	InputStreamConverter converter1(istr1, utf8Encoding, asciiEncoding);
	StreamCopier::copyStream(converter1, ostr1);
	assert (ostr1.str() == " ????? AB");
	assert (converter1.errors() == 0);

	std::istringstream istr2("abcde");
	std::ostringstream ostr2;
	InputStreamConverter converter2(istr2, utf8Encoding, asciiEncoding);
	StreamCopier::copyStream(converter2, ostr2);
	assert (ostr2.str() == "abcde");
	assert (converter2.errors() == 0);
}


void StreamConverterTest::testUTF8toASCIIOut()
{
	UTF8Encoding utf8Encoding;
	ASCIIEncoding asciiEncoding;

	const unsigned char greek[] = {0x20, 0xce, 0xba, 0xe1, 0xbd, 0xb9, 0xcf, 0x83, 0xce, 0xbc, 0xce, 0xb5, 0x20, 0x41, 0x42, 0x00};
	std::string text((const char*) greek);

	std::ostringstream ostr1;
	OutputStreamConverter converter1(ostr1, utf8Encoding, asciiEncoding);
	converter1 << text;
	assert (ostr1.str() == " ????? AB");
	assert (converter1.errors() == 0);

	std::ostringstream ostr2;
	OutputStreamConverter converter2(ostr2, utf8Encoding, asciiEncoding);
	converter2 << "abcde";
	assert (ostr2.str() == "abcde");
	assert (converter2.errors() == 0);
}


void StreamConverterTest::testLatin1toUTF8In()
{
	UTF8Encoding utf8Encoding;
	Latin1Encoding latin1Encoding;
	
	const unsigned char latin1Chars[] = {'g', 252, 'n', 't', 'e', 'r', 0};
	const unsigned char utf8Chars[]   = {'g', 195, 188, 'n', 't', 'e', 'r', 0};
	std::string latin1Text((const char*) latin1Chars);
	std::string utf8Text((const char*) utf8Chars);

	std::istringstream istr1(latin1Text);
	std::ostringstream ostr1;
	InputStreamConverter converter1(istr1, latin1Encoding, utf8Encoding);
	StreamCopier::copyStream(converter1, ostr1);
	assert (ostr1.str() == utf8Text);
	assert (converter1.errors() == 0);
}


void StreamConverterTest::testLatin1toUTF8Out()
{
	UTF8Encoding utf8Encoding;
	Latin1Encoding latin1Encoding;
	
	const unsigned char latin1Chars[] = {'g', 252, 'n', 't', 'e', 'r', 0};
	const unsigned char utf8Chars[]   = {'g', 195, 188, 'n', 't', 'e', 'r', 0};
	std::string latin1Text((const char*) latin1Chars);
	std::string utf8Text((const char*) utf8Chars);

	std::ostringstream ostr1;
	OutputStreamConverter converter1(ostr1, latin1Encoding, utf8Encoding);
	converter1 << latin1Text;
	assert (ostr1.str() == utf8Text);
	assert (converter1.errors() == 0);
}


void StreamConverterTest::testErrorsIn()
{
	UTF8Encoding utf8Encoding;
	Latin1Encoding latin1Encoding;

	const unsigned char badChars[] = {'a', 'b', 255, 'c', 254, 0};
	std::string badText((const char*) badChars);
	
	std::istringstream istr1(badText);
	std::ostringstream ostr1;
	InputStreamConverter converter1(istr1, utf8Encoding, latin1Encoding);
	StreamCopier::copyStream(converter1, ostr1);
	assert (converter1.errors() == 2);
}


void StreamConverterTest::testErrorsOut()
{
	UTF8Encoding utf8Encoding;
	Latin1Encoding latin1Encoding;

	const unsigned char badChars[] = {'a', 'b', 255, 'c', 254, 0};
	std::string badText((const char*) badChars);
	
	std::ostringstream ostr1;
	OutputStreamConverter converter1(ostr1, utf8Encoding, latin1Encoding);
	converter1 << badText;
	assert (converter1.errors() == 1);
}


void StreamConverterTest::setUp()
{
}


void StreamConverterTest::tearDown()
{
}


CppUnit::Test* StreamConverterTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("StreamConverterTest");

	CppUnit_addTest(pSuite, StreamConverterTest, testIdentityASCIIIn);
	CppUnit_addTest(pSuite, StreamConverterTest, testIdentityASCIIOut);
	CppUnit_addTest(pSuite, StreamConverterTest, testIdentityUTF8In);
	CppUnit_addTest(pSuite, StreamConverterTest, testIdentityUTF8Out);
	CppUnit_addTest(pSuite, StreamConverterTest, testUTF8toASCIIIn);
	CppUnit_addTest(pSuite, StreamConverterTest, testUTF8toASCIIOut);
	CppUnit_addTest(pSuite, StreamConverterTest, testLatin1toUTF8In);
	CppUnit_addTest(pSuite, StreamConverterTest, testLatin1toUTF8Out);
	CppUnit_addTest(pSuite, StreamConverterTest, testErrorsIn);
	CppUnit_addTest(pSuite, StreamConverterTest, testErrorsOut);

	return pSuite;
}