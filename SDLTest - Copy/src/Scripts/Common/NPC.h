#pragma once

class NPC {
protected:
	float health;

public:
	virtual float takeDamage(float damageMade) {return  health = getHealth() - damageMade; }
	virtual float getHealth() { return health; }
	virtual void setHealth(float newHealth) { health = newHealth; }
	virtual void shoot() {};

};