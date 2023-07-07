typedef const char * Item;
class List {
private:
	enum {MAX = 4};
	Item m_list[MAX];
	short m_top;
public:
	List() {m_top = 0};
	void add();
};