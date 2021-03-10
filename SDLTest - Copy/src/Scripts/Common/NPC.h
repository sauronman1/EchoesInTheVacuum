#pragma once

class NPC {
private:
	float health;

public:
	virtual float takeDamage(float damageMade) {return  health = getHealth() - damageMade; }
	virtual float getHealth() { return health; }
	virtual void shoot() {};

};