//
// SerialPort_POSIX.cpp
//
// $Id: //poco/Main/IO/src/SerialPort_POSIX.cpp#1 $
//
// Library: IO
// Package: Serial
// Module:  SerialPort
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
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


#include "Poco/IO/SerialPort_POSIX.h"
#include "Poco/Exception.h"


using Poco::CreateFileException;
using Poco::IOException;


namespace Poco {
namespace IO {


SerialPortImpl::SerialPortImpl(const std::string& name, const SerialConfigImpl& config): 
	_name(name), _config(config)
{
	openImpl();
}


SerialPortImpl::~SerialPortImpl()
{
	closeImpl();
}


void SerialPortImpl::initImpl()
{
	//TODO
}


void SerialPortImpl::reconfigureImpl(const SerialConfigImpl& config)
{
	_config = config;
	initImpl();
}


void SerialPortImpl::openImpl()
{
	//TODO

	initImpl();
}


void SerialPortImpl::closeImpl()
{
	//TODO
}


char SerialPortImpl::readImpl()
{
	char readBuf = 0;
	readImpl(&readBuf, 1);
	return readBuf;
}


int SerialPortImpl::readImpl(char* pBuffer, int length)
{
	if (0 == length) return 0;

	int read = 0;

	//TODO

	return read;
}


std::string& SerialPortImpl::readImpl(std::string& buffer)
{
	int read = 0;
	int bufSize = _config.getBufferSizeImpl();
	char* pReadBuf = new char[bufSize+1];

	buffer.clear();
	do
    {
		//TODO
		/*
		ZeroMemory(pReadBuf, bufSize+1);
		
		if (!ReadFile(_handle, pReadBuf, bufSize, &read, NULL)) 
		{
			delete[] pReadBuf;
			handleError(_name);
		}*/

		poco_assert(read <= bufSize);
		buffer.append(pReadBuf, read);
		
		if (_config.getUseEOFImpl()) 
		{
			size_t pos = buffer.find(_config.getEOFCharImpl());
			if (pos != buffer.npos)
			{
				buffer = buffer.substr(0, pos);
				//TODO
				//PurgeComm(_handle, PURGE_RXCLEAR);
				break;
			}
		}
	}while(0 != read);

	delete[] pReadBuf;
	return buffer;
}


int SerialPortImpl::writeImpl(char c)
{
	return writeImpl(&c, 1);
}


int SerialPortImpl::writeImpl(const char* pBuffer, int length)
{
	if (0 == length) return 0;

	std::string str;
	str.assign(pBuffer, length);
	
	return writeImpl(str);
}


int SerialPortImpl::writeImpl(const std::string& data)
{
	if (0 == data.length()) return 0;

	std::string d = data;

	if (_config.getUseEOFImpl()) 
	{
		size_t pos = d.find(_config.getEOFCharImpl());
		if (pos != d.npos) d = d.substr(0, pos+1);
	}

	int written = 0;
	int length = d.length();

	//TODO
	/*
	if (!WriteFile(_handle, d.data(), length, &written, NULL) || 
		((written != length) && (0 != written)))
		handleError(_name);
	else if (0 == written)
		throw IOException("Error writing to " + _name);
*/
	return written;
}


const std::string& SerialPortImpl::getNameImpl() const
{
	return _name;
}


std::string& SerialPortImpl::getErrorText(std::string& buf)
{
    //TODO
    return buf;
}


void SerialPortImpl::handleError(const std::string& name)
{
	//TODO
	int error = 0;
	std::string errorText;

	switch (error)
	{
	//TODO
	default:
		throw FileException(name, getErrorText(errorText));
	}
}


} } // namespace Poco::IO
