#pragma once

#include <string>
#include <list>

using namespace std;

/***************************
*   观察者基类
****************************/
struct Blog;
struct Observer {
	Observer() {}
	virtual ~Observer() {}
	virtual void attach(Blog*) {}
	virtual void remove(Blog*) {}
	virtual void update(Blog*) {}
};

/***************************
*   博客基类
****************************/
struct Blog {
	Blog() {}
	virtual ~Blog() {}
	void notify();
	virtual void setStatus(string str);
	virtual string getStatus();
	void attach(Observer* m_Obe);
	void remove(Observer* m_Obe);

protected:
	string m_status;		//博客状态

private:
	list<Observer*> obers;	//观察者集合，此处最好用set
};

/***************************
*   具体的博客
****************************/
struct BlogCSDN : public Blog {
	BlogCSDN(string _name) :m_name(_name)
	{}
	~BlogCSDN() {}
	void setStatus(string str);
	string getStatus();
private:
	string m_name;			//博主名称
};

struct BlogSINA : public Blog {
	BlogSINA(string _name) :m_name(_name)
	{}
	~BlogSINA() {}
	void setStatus(string str);
	string getStatus();
private:
	string m_name;			//博主名称
};

/***************************
*   具体的观察者
****************************/
struct ObserverBlog : public Observer {
	ObserverBlog(string _name):m_name(_name){}
	~ObserverBlog() {}
	void update(Blog* blog);
	void attach(Blog* blog);
	void remove(Blog* blog);
private:
	string m_name;		// 观察者名称
	list<Blog*> blogs;	//博客集合
};

void observerTest(void);