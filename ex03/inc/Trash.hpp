#if !defined(TRASH_HPP)
#define TRASH_HPP

#include "AMateria.hpp"

class Trash
{
private:
	class Node
	{
	private:
		AMateria* _content;
		Trash::Node* _next;
		Node();
	public:
		Node(AMateria* content);
		Node(const Trash::Node& other);
		Trash::Node& operator=(const Trash::Node& other);
		~Node();

		bool hasNext() const;
		Trash::Node* next() const;
		void addNext(Trash::Node* next);
	};

	Node* _head;

public:
	Trash();
	Trash(const Trash& other);
	Trash& operator=(const Trash& other);
	~Trash();

	void add(AMateria *elem);
};

#endif // TRASH_HPP
