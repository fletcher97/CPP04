#if !defined(AMATERIA_HPP)
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
private:
	AMateria();
protected:
	std::string _type;
public:
	AMateria(const std::string& type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	const std::string& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif // AMATERIA_HPP
