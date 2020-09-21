#pragma once
class Texture abstract
{
public:
	virtual HRESULT Insert_Texture(const wstring& wstrFilePath,
		const wstring& wstrStateKey = TEXT(""), const DWORD& rCount = 0) PURE;
	virtual const TEXINFO* Get_Texture(const wstring& wstrStateKey = TEXT(""), const DWORD& rIndex = 0)PURE;

	virtual void Release_Texture()PURE;
public:
	explicit Texture();
	virtual ~Texture();
};

