#pragma once
class MainGame final
{
public:
	void Ready();
	void Update();
	void LateUpdate();
	void Render();
	void Release();
public:
	explicit MainGame();
	~MainGame();
};

