#pragma once
#include "Scene.h"
class LogoScene final :
	public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual HRESULT Ready() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	explicit LogoScene();
	virtual ~LogoScene();

private:
	void Render_BackGround();
	void Render_Cloud();
	void Render_MainLogo();

	void Render_MoveCloud(const wstring& objectKey, float& move);
private:
	const float m_BackGroundSize { 640.f * 4.27f };

	float m_fBackMove{};
	float m_fFrontMove{};
	float m_Size;
};