//
// HttpSession.h
//
//
// Library: Servlet
// Package: Http
// Module:  HttpSession
//
// Definition of the HttpSession class.
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
//
// The code in this file is derived from Apache Tomcat project
// Copyright (c) 2004 The Apache Software Foundation.
// http://www.apache.org/licenses/LICENSE-2.0
// 


#ifndef Servlet_Http_HttpSession_INCLUDED
#define Servlet_Http_HttpSession_INCLUDED


#include "Poco/Servlet/Object.h"
#include "Poco/Servlet/ServletContext.h"
#include <ctime>


namespace Poco {
namespace Servlet {


class Servlet_API HttpSession : public Object
	/// Provides a way to identify a user across more than one page
	/// request or visit to a Web site and to store information about that user.
	///
	/// The servlet container uses this interface to create a session
	/// between an HTTP client and an HTTP server. The session persists
	/// for a specified time period, across more than one connection or
	/// page request from the user. A session usually corresponds to one 
	/// user, who may visit a site many times. The server can maintain a 
	/// session in many ways such as using cookies or rewriting URLs.
	///
	/// This interface allows servlets to view and manipulate information 
	/// about a session, such as the session identifier, creation time, 
	/// and last accessed time
	/// 
	/// When an application stores an object in or removes an object from a
	/// session, the servlet notifies the object that it has been bound to 
	/// or unbound from the session. The object must implement
	/// {HttpSessionBindingListener} interface.
	/// Notifications are sent after the binding methods complete. 
	/// For session that are invalidated or expire, notifications are sent after
	/// the session has been invalidated or expired.
	///
	/// A servlet should be able to handle cases in which
	/// the client does not choose to join a session, such as when cookies are
	/// intentionally turned off. Until the client joins the session,
	/// isNew returns true. If the client chooses not to join
	/// the session, getSession will return a different session
	/// on each request, and isNew will always return true.
	///
	/// Session information is scoped only to the current web application
	/// (ServletContext), so information stored in one context
	/// will not be directly visible in another.
{
public:

	HttpSession();
		/// Constructor.

	virtual ~HttpSession();
		/// Destructor.

	virtual time_t getCreationTime() const = 0;
		/// Returns the time when this session was created, measured
		/// in milliseconds since midnight January 1, 1970 GMT.

	virtual std::string getId() const = 0;
		/// Returns a string containing the unique identifier assigned 
		/// to this session. The identifier is assigned 
		/// by the servlet container and is implementation dependent.

	virtual time_t getLastAccessedTime() const = 0;
		/// Returns the last time the client sent a request associated with
		/// this session, as the number of milliseconds since midnight
		/// January 1, 1970 GMT, and marked by the time the container received the request. 
		/// 
		/// Actions that your application takes, such as getting or setting
		/// a value associated with the session, do not affect the access
		/// time.

	virtual const ServletContext& getServletContext() const = 0;
		/// Returns the ServletContext to which this session belongs.

	virtual void setMaxInactiveInterval(time_t interval) = 0;
		/// Specifies the time, in seconds, between client requests before the 
		/// servlet container will invalidate this session.  A negative time
		/// indicates the session should never timeout.

	virtual long getMaxInactiveInterval() const = 0;
		/// Returns the maximum time interval, in seconds, that 
		/// the servlet container will keep this session open between 
		/// client accesses. After this interval, the servlet container
		/// will invalidate the session.  The maximum time interval can be set
		/// with the setMaxInactiveInterval method.
		/// A negative time indicates the session should never timeout.
    
	virtual const Object* getAttribute(const std::string& name) const = 0;
		/// Returns the object bound with the specified name in this session, or
		/// null if no object is bound under the name.

	virtual const Object* getValue(const std::string& name) const = 0;
		/// Deprecated. As of Version 2.2, this method is
		/// replaced by {getAttribute}.

	virtual const std::vector<std::string>& getAttributeNames() const = 0;
		/// Returns an Enumeration of String objects
		/// containing the names of all the objects bound to this session. 

	virtual const std::vector<std::string>& getValueNames() const = 0;
		/// Deprecated. This method is replaced by getAttributeNames

	virtual void setAttribute(const std::string& name, Object& value) = 0;
		/// Binds an object to this session, using the name specified.
		/// If an object of the same name is already bound to the session,
		/// the object is replaced.
		///
		/// After this method executes, and if the new object
		/// implements HttpSessionBindingListener,
		/// the container calls 
		/// HttpSessionBindingListener.valueBound. The container then   
		/// notifies any HttpSessionAttributeListeners in the web 
		/// application.
		///     
		/// If an object was already bound to this session of this name
		/// that implements HttpSessionBindingListener, its 
		/// HttpSessionBindingListener.valueUnbound method is called.
		///
		/// If the value passed in is null, this has the same effect as calling 
		/// removeAttribute().

	void putValue(const std::string& name, Object& value);
		/// Deprecated 	As of Version 2.2, this method is
		/// replaced by {setAttribute}

	virtual void removeAttribute(const std::string& name) = 0;
		/// Removes the object bound with the specified name from
		/// this session. If the session does not have an object
		/// bound with the specified name, this method does nothing.
		///
		/// After this method executes, and if the object
		/// implements HttpSessionBindingListener, the container calls 
		/// HttpSessionBindingListener.valueUnbound. The container then 
		/// notifies any HttpSessionAttributeListeners in the web application.

	void removeValue(const std::string& name);
		/// Deprecated. As of Version 2.2, this method is
		/// replaced by {removeAttribute}

	virtual void invalidate() = 0;
		/// Invalidates this session then unbinds any objects bound
		/// to it. 

	virtual bool isNew() const = 0;
		/// Returns true if the client does not yet know about the
		/// session or if the client chooses not to join the session.  For 
		/// example, if the server used only cookie-based sessions, and
		/// the client had disabled the use of cookies, then a session would
		/// be new on each request.

	static const std::string COOKIE_SESSION_ID;
	static const std::string URI_SESSION_ID;

	virtual bool isValidNS() const = 0;
		/// Non-standard API.

	virtual void setLastAccessedTimeNS(time_t) = 0;
		/// Non-standard API.

	static const std::string CLASS_NAME;
	static const long INDEFINITE;
};


///
///inlines
///

inline void HttpSession::removeValue(const std::string& name)
{
	removeAttribute(name);
}


inline void HttpSession::putValue(const std::string& name, Object& value)
{
	setAttribute(name, value);
}


class Servlet_API HttpSessionEvent
	/// This is the class representing event notifications for
	/// changes to sessions within a web application.
{
public:
	
	HttpSessionEvent(const HttpSession* psource) 
		/// Construct a session event from the given source.
	{
		_psource = psource;
	}
	
	const HttpSession* getSource() const
	{
		return _psource;
	}

	
   const HttpSession* getSession () const
		 /// Return the session that changed.
	 { 
		return getSource();
   }

private:
  const HttpSession* _psource;
};

#if 0
/// TODO
template<class T>
class Servlet_API HttpSessionBindingEvent : public HttpSessionEvent 
 /// Events of this type are either sent to an object that implements
 /// { HttpSessionBindingListener } when it is bound or 
 /// unbound from a session, or to a { HttpSessionAttributeListener} 
 /// that has been configured in the deployment descriptor when any attribute is
 /// bound, unbound or replaced in a session.
 ///
 /// The session binds the object by a call to
 /// HttpSession.setAttribute and unbinds the object
 /// by a call to HttpSession.removeAttribute.
{
public:
	HttpSessionBindingEvent(HttpSession* session, const std::string& name) :
		HttpSessionEvent(session), _name(name)
		/// Constructs an event that notifies an object that it
	/// has been bound to or unbound from a session. 
	/// To receive the event, the object must implement
	/// { HttpSessionBindingListener }.
	{
    }
    
	HttpSessionBindingEvent(HttpSession* session, const std::string& name, const T& value) :
		HttpSessionEvent(session), _name(name), _value(value)
		/// Constructs an event that notifies an object that it
		/// has been bound to or unbound from a session. 
		/// To receive the event, the object must implement
		/// { HttpSessionBindingListener }.
	{
    }
    
    const HttpSession* getSession () const
			/// Returns the session that changed.
	{ 
		return HttpSessionEvent::getSession();
		return 0;
    }

    std::string getName() 
		/// Returns the name with which the attribute is bound to or
		/// unbound from the session.
		{
			return _name;
    }
    
	const T& getValue() const
		/// Returns the value of the attribute that has been added, removed or replaced.
		/// If the attribute was added (or bound), this is the value of the attribute. If the attribute was
		/// removed (or unbound), this is the value of the removed attribute. If the attribute was replaced, this
		/// is the old value of the attribute.
	{
			return _value;   
	}

 private:
	std::string _name;
	 /// The name to which the object is being bound or unbound.
    
	T _value;
	 /// The object that is being bound or unbound.
    
 };
#endif //#if 0


class Servlet_API HttpSessionListener 
	/// Implementations of this interface are notified of changes to the 
	/// list of active sessions in a web application.
{
 public:   

  virtual void sessionCreated (const HttpSessionEvent& se ) = 0;
	 /// Notification that a session was created.
    
  virtual void sessionDestroyed (const HttpSessionEvent& se ) = 0;
	 /// Notification that a session is about to be invalidated.
    
};


class Servlet_API HttpSessionActivationListener 
	/// Objects that are bound to a session may listen to container
	/// events notifying them that sessions will be passivated and that
	/// session will be activated. A container that persists sessions 
	/// is required to notify all attributes bound to sessions
	/// implementing HttpSessionActivationListener.
{ 
public:
  virtual void sessionWillPassivate(HttpSessionEvent& se) = 0; 
	  /// Notification that the session is about to be passivated.
		 
  virtual void sessionDidActivate(HttpSessionEvent& se) = 0;
	  /// Notification that the session has just been activated.
};


class HttpSessionEventListener : public HttpSessionListener,
																 public HttpSessionActivationListener
	 /// Non-standard. Utility "intermediate" class aggregating
	 /// HttpSessionListener and HttpSessionActivationListener
	 /// interfaces.
{
};


#if 0
/// TODO
template<class T>
class Servlet_API HttpSessionAttributeListener 
	/// This listener interface can be implemented in order to
	/// get notifications of changes to the attribute lists of sessions within
	/// this web application.
{
	virtual void attributeAdded ( HttpSessionBindingEvent<T>& se ) = 0;
		/// Notification that an attribute has been added to a session. 
		/// Called after the attribute is added.
		 
	virtual void attributeRemoved ( HttpSessionBindingEvent<T>& se ) = 0;
		/// Notification that an attribute has been removed from a session. 
		/// Called after the attribute is removed. 

	virtual void attributeReplaced ( HttpSessionBindingEvent<T>& se ) = 0;
		/// Notification that an attribute has been replaced in a session. 
		/// Called after the attribute is replaced.
};


template<class T>
class Servlet_API HttpSessionBindingListener
 /// Causes an object to be notified when it is bound to
 /// or unbound from a session. The object is notified
 /// by an { HttpSessionBindingEvent } object. This may be as a result
 /// of a servlet programmer explicitly unbinding an attribute from a session,
 /// due to a session being invalidated, or due to a session timing out.
{
public:

	virtual void valueBound(const HttpSessionBindingEvent<T>* event) {};
		/// Notifies the object that it is being bound to
		/// a session and identifies the session.
	
	virtual void valueUnbound(const HttpSessionBindingEvent<T>* event) {};
		/// Notifies the object that it is being unbound
		/// from a session and identifies the session.

};
#endif //#if 0


} } // namespace Poco::Servlet


#endif // Servlet_Http_HttpSession_INCLUDED

