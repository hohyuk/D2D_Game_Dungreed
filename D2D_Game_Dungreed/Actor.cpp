#include "framework.h"
#include "Actor.h"

HRESULT Actor::Ready()
{
	return S_OK;
}

int Actor::Update()
{
	return 0;
}

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::ChangeAnim()
{
}
