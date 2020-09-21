#pragma once
#include "Texture.h"
class MultiTexture final :
	public Texture
{
public:
	// Texture을(를) 통해 상속됨
	virtual HRESULT Insert_Texture(const wstring& wstrFilePath, const wstring& wstrStateKey = TEXT(""), const DWORD& rCount = 0) override;
	virtual const TEXINFO * Get_Texture(const wstring& wstrStateKey = TEXT(""), const DWORD& rIndex = 0) override;
	virtual void Release_Texture() override;
public:
	explicit MultiTexture();
	virtual ~MultiTexture();

private:
	map<wstring, vector<TEXINFO*>> m_mapMultiTexture;	// StateKey를 담을 것
};

