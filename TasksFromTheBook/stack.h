struct customer {
	char fullname[35];
	double payment;
};
typedef char Item;
class stack {
private:
	enum {MAX = 10};
	Item list[MAX];
	int top;
public:
	stack() {top = 0;}
	bool isfull() const;
	bool isempty() const;
	bool push(const Item & item);
	bool pop();
};