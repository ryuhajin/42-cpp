# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

// 히트 포인트 == 체력. 히트 포인트가 없으면 행동 불가
// 에너지 포인트 == 행동력. 에너지 포인트가 없으면 행동 불가
// 클랩 트랩은 공격과 수리에 각각 1 에너지 포인트를 소모한다.

class ClapTrap
{
protected:
	std::string name;
	int hit_Point;
	int energy_Point;
	int attack_Damage;
public:
	ClapTrap(void);
	ClapTrap(const std::string& in_name);
	~ClapTrap();

	//복사 생성자
	//대입 연산자 만들기

	//claptrap의 attack damege 만큼 target에게 hit point 피해
	void	attack(const std::string& target);
	//amount 만큼 hit point 소모.
	void	takeDamage(unsigned int amount);
	//amount 만큼 claptap이 hit point 회복.
	void	beRepaired(unsigned int amount);
};

#endif
