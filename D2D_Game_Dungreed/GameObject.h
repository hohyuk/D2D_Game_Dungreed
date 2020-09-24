#pragma once
class GameObject abstract
{
public:
	virtual HRESULT Ready() = 0;
	virtual int		Update() = 0;
	virtual void	LateUpdate();
	virtual void	Render();
	virtual void	Release();
public:
	explicit GameObject();
	virtual ~GameObject();
};

