#pragma once
class Scene;

class SceneManager final
{
	DECLARE_SINGLETON(SceneManager)
private:
	explicit SceneManager();
	~SceneManager();
public:
	SCENE::TYPE Get_CurScene()const { return m_eCurScene; }
public:
	HRESULT Change_Scene(SCENE::TYPE eNextScene);
	void Update();
	void LateUpdate();
	void Render();
	void Release();
private:
	bool IsActivateScene(const int& speed = 3);
	void Render_FadeIn();
private:
	SCENE::TYPE m_eCurScene;
	SCENE::TYPE m_eNextScene;
	Scene* m_pScene{ nullptr };

	bool	isFadeIn_Activation;
	int		m_iAlpha;
};

