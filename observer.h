#pragma once

#include <string>
#include <list>

using namespace std;

/***************************
*   �۲��߻���
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
*   ���ͻ���
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
	string m_status;		//����״̬

private:
	list<Observer*> obers;	//�۲��߼��ϣ��˴������set
};

/***************************
*   ����Ĳ���
****************************/
struct BlogCSDN : public Blog {
	BlogCSDN(string _name) :m_name(_name)
	{}
	~BlogCSDN() {}
	void setStatus(string str);
	string getStatus();
private:
	string m_name;			//��������
};

struct BlogSINA : public Blog {
	BlogSINA(string _name) :m_name(_name)
	{}
	~BlogSINA() {}
	void setStatus(string str);
	string getStatus();
private:
	string m_name;			//��������
};

/***************************
*   ����Ĺ۲���
****************************/
struct ObserverBlog : public Observer {
	ObserverBlog(string _name):m_name(_name){}
	~ObserverBlog() {}
	void update(Blog* blog);
	void attach(Blog* blog);
	void remove(Blog* blog);
private:
	string m_name;		// �۲�������
	list<Blog*> blogs;	//���ͼ���
};

void observerTest(void);