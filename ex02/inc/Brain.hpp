#if !defined(BRAIN_HPP)
#define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string _ideas[100];
	int _curr_idea;
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	int getCurrIdea() const;
	void printIdeas() const;
	void addIdea(const std::string& idea);
};

#endif // BRAIN_HPP
