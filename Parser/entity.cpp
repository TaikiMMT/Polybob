#include "parserPrivate.h"

Entity::Entity()
{
	initialized = false;
	isContainer = isFunction = false;
	previousOperator = PREV_OP_NONE;
	power = 0;
}

bool Entity::setMonome(monome entry)
{
	if(isContainer)
		return false;
	
	_monome = entry;
	return true;
}

bool Entity::setSublevel(std::vector<Entity> entry)
{
	if(initialized && !isContainer)
		return false;
	
	isContainer = true;
	subLevel = entry;
	
	return true;
}

bool Entity::setFunction(std::string name)
{
	if(initialized)
		return false;
	
	isContainer = true;
	isFunction = true;
	functionName = name;
	
	return true;
}

bool Entity::isReal()
{
	return !isContainer && _monome.exponent == SPIRIT_DEFAULT_POWER_VALUE && _monome.coef.coefComplex == 0;
}