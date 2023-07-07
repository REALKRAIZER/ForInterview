bool stack::isfull() const
{
	return top==MAX;
}
bool stack::isempty() const
{
	return top==0;
}
bool stack::push(const Item & item)
{
	if(top < MAX) {
		list[top++] = item;
		return true;
	}
	else 
		return false;
}
bool stack::pop()
{
	if(top > 0) {
		--top;
		return true;
	}
	else 
		return false;
}