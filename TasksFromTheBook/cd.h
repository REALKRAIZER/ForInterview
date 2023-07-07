#ifndef CD_INCLUDED
#define CD_INCLUDED
class Cd {
private:
	char * performers;
	char * label;
	int selections;
	double playtime;
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd & operator=(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void report() const;
};
#endif