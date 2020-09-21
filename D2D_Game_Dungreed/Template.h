#pragma once
template<typename T>
void Safe_Delete(T& rObj)
{
	if (rObj)
	{
		delete rObj;
		rObj = nullptr;
	}
}

template<typename T>
void Safe_Delete_Array(T& rObj)
{
	if (rObj)
	{
		delete[] rObj;
		rObj = nullptr;
	}
}

template<typename T>
void Safe_Release(T& rObj)
{
	if (rObj)
		rObj->Release();
}

template<typename T>
void Safe_Delete_Vector(vector<T*>& rVec)
{
	for (auto& rObj : rVec)
		Safe_Delete(rObj);

	rVec.clear();
	rVec.shrink_to_fit();
}