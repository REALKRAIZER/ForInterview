#ifndef DMA_H_
#define DMA_H_
#include <iostream>
class abcDma
{
public:
	virtual void View() const = 0;
	virtual ~abcDma() {std::cout << "ABCDESTR\n";};
	
};
class baseDMA : public abcDma
{
private:
	char * label;
	int rating;
public:
	baseDMA(const char * l = "null", int r = 0);
	baseDMA(const baseDMA & rs);
	~baseDMA();
	baseDMA & operator=(const baseDMA & rs);
	void View() const;
	friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};
class lacksDMA : public baseDMA
{
private:
	enum { COL_LEN=40 };
	char color[COL_LEN];
public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const baseDMA & rs);
	void View() const;
	friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
};
class hasDMA : public baseDMA
{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const baseDMA & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator=(const hasDMA & hs);
	void View() const;
	friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};
#endif