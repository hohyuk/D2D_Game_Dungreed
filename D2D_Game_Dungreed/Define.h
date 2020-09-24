#pragma once

#define FPS_MGR			FPS_Manager::Get_Instance()
#define TIME_MGR		TimeManager::Get_Instance()
#define DELTA_TIME		TIME_MGR->Get_DeltaTime()

#define GD_MGR			GraphicDevice::Get_Instance()
#define TEXTURE_MGR		TextureManager::Get_Instance()

#define SCENE_MGR		SceneManager::Get_Instance()