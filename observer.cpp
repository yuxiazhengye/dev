#include "observer.h"
#include <iostream>

using namespace std;

void Blog::attach(Observer* ober)
{
	obers.push_back(ober);
}

void Blog::remove(Observer* ober)
{
	for (auto it = obers.begin(); it != obers.end(); )
	{
		if (*it == ober)
		{
			it = obers.erase(it);
			break;
		}
		else
		{
			it++;
		}
	}
}

void Blog::notify()
{
	for (auto it = obers.begin(); it != obers.end(); it++)
	{
		(*it)->update(this);
	}
}

void Blog::setStatus(string str)
{
	m_status = str;
}

string Blog::getStatus()
{
	return m_status;
}

void BlogCSDN::setStatus(string str)
{
	m_status = "CSDN֪ͨ: " + m_name + str;
}

string BlogCSDN::getStatus()
{
	return m_status;
}

void BlogSINA::setStatus(string str)
{
	m_status = "SINA֪ͨ: " + m_name + str;
}

string BlogSINA::getStatus()
{
	return m_status;
}

void ObserverBlog::attach(Blog* blog)
{
	if (NULL == blog) return;
	blogs.push_back(blog);
	blog->attach(this);
}

void ObserverBlog::remove(Blog* blog)
{
	if (NULL == blog) return;
	for (auto it = blogs.begin(); it != blogs.end(); )
	{
		if (*it == blog)
		{
			it = blogs.erase(it);
			break;
		}
		else
			it++;
	}
	blog->remove(this);
}

void ObserverBlog::update(Blog* blog)
{
	for (auto it = blogs.begin(); it != blogs.end(); it++)
	{
		if (*it == blog)
		{
			string status = (*it)->getStatus();
			cout << m_name << "----------" << status << endl;
		}
	}
}

void observerTest()
{
	Blog* csdnBlog = new BlogCSDN("CSDN����С��");
	Blog* sinaBlog = new BlogSINA("SINA����С��");
	Observer* ober1 = new ObserverBlog("�Թ�Ⱥ��СA");
	Observer* ober2 = new ObserverBlog("�Թ�Ⱥ��СB");
	Observer* ober3 = new ObserverBlog("�Թ�Ⱥ��СC");
	ober1->attach(csdnBlog);
	ober2->attach(csdnBlog);
	ober2->attach(sinaBlog);
	ober3->attach(sinaBlog);

	csdnBlog->setStatus("д��һƪ�ֹϵĲ���");
	sinaBlog->setStatus("д��һƪ�ԹϵĲ���");
	csdnBlog->notify();
	sinaBlog->notify();

	ober1->remove(csdnBlog);
	ober1->attach(sinaBlog);
	csdnBlog->setStatus("��߻�һ����");
	sinaBlog->setStatus("�ұ߻�һ���ʺ�");
	csdnBlog->notify();
	sinaBlog->notify();

	delete csdnBlog;
	delete sinaBlog;
	delete ober1;
	delete ober2;
	delete ober3;
}



