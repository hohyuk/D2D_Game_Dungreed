#pragma once

inline void D3DX_ST(INFO& info);


inline void D3DX_ST(INFO& info)
{
	D3DXMATRIX matScale, matTrans;
	D3DXMatrixScaling(&matScale, info.vSize.x  * info.vLook.x, info.vSize.y, 0.f);
	D3DXMatrixTranslation(&matTrans, info.vPos.x, info.vPos.y, 0.f);
	info.mat = matScale * matTrans;
}