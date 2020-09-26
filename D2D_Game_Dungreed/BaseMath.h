#pragma once
inline int WrapInt(const int& _min, int _val, const int& _max);
inline float WrapFloat(const float& _min, float _val, const float& _max);

inline RECT MakeRect(RECT& rc, const D3DXVECTOR3& vPos, const D3DXVECTOR3& vObjectHalfSize);
inline bool IsPointInRect(const D3DXVECTOR3& p, const RECT& rc);

inline int WrapInt(const int& _min, int _val, const int& _max)
{
	int n = (_val - _min) % (_max - _min);
	return (n >= 0) ? (n + _min) : (n + _max);
}

inline float WrapFloat(const float& _min, float _val, const float& _max)
{
	float n = fmod(_val - _min, _max - _min);
	return (n >= 0) ? (n + _min) : (n + _max);
}

inline RECT MakeRect(RECT& rc, const D3DXVECTOR3& vPos, const D3DXVECTOR3& vObjectHalfSize)
{
	rc.left = LONG(vPos.x - vObjectHalfSize.x);
	rc.top = LONG(vPos.y - vObjectHalfSize.y);
	rc.right = LONG(vPos.x + vObjectHalfSize.x);
	rc.bottom = LONG(vPos.y + vObjectHalfSize.y);
	return rc;
}

inline bool IsPointInRect(const D3DXVECTOR3& p, const RECT& rc)
{
	if (rc.left <= p.x && rc.right >= p.x && rc.top <= p.y && rc.bottom >= p.y)
		return true;
	return false;
}