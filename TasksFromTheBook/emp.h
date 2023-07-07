#ifndef EMP_H
#define EMP_H
#include <iostream>
#include <string>
class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;
protected:
	virtual void data() const;
	virtual void get();
public:
	abstr_emp() :
		fname("no data"), lname("no data"), job("no data") {};
	abstr_emp(const std::string & fn, const std::string & ln, const std::string & j) :
		fname(fn), lname(ln), job(j) {};
	virtual void showAll() const = 0;
	virtual void setAll() = 0;
	virtual void a() const {};
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & ae);
	virtual ~abstr_emp() {};
	
};
class employee : public abstr_emp
{
protected:
	virtual void data() const override { abstr_emp::data(); };
	virtual void get() override { abstr_emp::get(); };
public:
	employee() : abstr_emp() {};
	employee(const std::string & fn, const std::string & ln, const std::string & j) :
		abstr_emp(fn,ln,j) {};
	virtual void showAll() const override;
	virtual void setAll() override;
};
class manager : virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	virtual void data() const override;
	virtual void get() override;
	int getInchargeof() const { return inchargeof; };
	void setInchargeof(const int ico) { inchargeof = ico; };
public:
	manager() : abstr_emp(), inchargeof(0) {};
	manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0) :
		abstr_emp(fn,ln,j), inchargeof(ico) {};
	manager(const abstr_emp & ae, int ico = 0) : abstr_emp(ae), inchargeof(ico) {};
	virtual void showAll() const override;
	virtual void setAll() override;
};
class fink : virtual public abstr_emp
{
private:
	std::string reportsto;
protected:
	virtual void data() const override;
	virtual void get() override;
	std::string getReportsto() const { return reportsto; };
	void setReportsto(const std::string & rt) { reportsto = rt; };
public:
	fink() : abstr_emp(), reportsto("no data") {};
	fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rt) : 
		abstr_emp(fn,ln,j), reportsto(rt) {};
	fink(const abstr_emp & ae, const std::string & rt) : 
		abstr_emp(ae), reportsto(rt) {};
	virtual void showAll() const override;
	virtual void setAll() override;
};
class highfink : virtual public manager, virtual public fink
{
protected:
	virtual void data() const override {};
	virtual void get() override {};
public:
	highfink() : abstr_emp(), manager(), fink() {};
	highfink(const std::string & fn, const std::string & ln, const std::string & j,
		const std::string & rt, int ico) : abstr_emp(fn,ln,j), manager(fn,ln,j,ico), fink(fn,ln,j,rt) {};
	highfink(const abstr_emp & ae, const std::string & rp, int ico) : abstr_emp(ae), manager(ae, ico), fink(ae, rp) {};
	highfink(const manager & m, const std::string & rp) : abstr_emp(m), manager(m), fink(m, rp) {};
	highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico), fink(f) {};
	highfink(const highfink & hf) : abstr_emp(hf), fink(hf), manager(hf) {};
	virtual void showAll() const override;
	virtual void setAll() override;
};
#endif