#ifndef QUEUE_H_
#define QUEUE_H_
class Customer
{
	long arrive;//когда челик появился в очереди
	int processtime;//время транзакции(сколько челик стоит у банкомата)
public:
	Customer() : arrive(0), processtime(0) {};
	void set(long arrive);
	long when() const { return arrive;};
	long ptime() const { return processtime;};
};
typedef Customer Item;
class queue
{
private:
	struct Node {Item item; Node * next;};
	static const short Qsize = 10;
	Node * start;
	Node * end;
	int items;
	const int qsize;

	queue(const queue & q) : qsize(Qsize) {};
	queue & operator=(const queue & q) {return *this;};

public:
	queue(const int qs = Qsize);
	~queue();
	bool isfull() const;
	bool isempty() const;
	int queuecount() const;
	bool addqueue(const Item &);
	bool delqueue(Item &);
};
#endif