#if !defined(CHARACTER_HPP)
#define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"
#include "Trash.hpp"

class AMateria;

class Character: public ICharacter
{
private:
	std::string _name;
	AMateria* _inv[4];
	Trash bin;
	Character();
public:
	Character(std::string name);
	Character(std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	const std::string & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif // CHARACTER_HPP
